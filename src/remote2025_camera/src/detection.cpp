#include <rclcpp/rclcpp.hpp>
#include <image_transport/image_transport.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <openvino/openvino.hpp>

#include <chrono>
#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

using namespace ov;
using namespace cv;
using namespace std;

const float SCORE_THRESHOLD = 0.2;
const float NMS_THRESHOLD = 0.4;
const float CONFIDENCE_THRESHOLD = 0.2;

class ImageSubscriberNode : public rclcpp::Node {
public:
  Mat img;
  ov::CompiledModel compiled_model;
  ov::InferRequest infer_request;
  struct Detection{
      int class_id;
      float confidence;
      Rect box;
    };

  struct Resize{
      Mat resized_image;
      int dw;
      int dh;
  };
  ImageSubscriberNode() : Node("image_subscriber_node_2") {
    // // Image transport subscriber
    // it_ = std::make_shared<image_transport::ImageTransport>(this->shared_from_this());
    // img_sub_ = it_->subscribe(
    //   "camera/image", // Topic yang sama dengan publisher
    //   10,
    //   std::bind(&ImageSubscriberNode::image_callback, this, std::placeholders::_1));
  }

  void init(){
    it_ = std::make_shared<image_transport::ImageTransport>(this->shared_from_this());
    img_sub_ = it_->subscribe("topic2",5,std::bind(&ImageSubscriberNode::image_callback, this, std::placeholders::_1));
    Core core;
    
    //read model
    shared_ptr<Model> model = core.read_model("/home/rivalits/Documents/res/erc_remote/src/remote2025_camera/include/openvino_model/BISADONGPLEASE.onnx");

    preprocess::PrePostProcessor ppp = preprocess::PrePostProcessor(model);
    ppp.input().tensor().set_element_type(element::u8).set_layout("NHWC").set_color_format(preprocess::ColorFormat::BGR);
    ppp.input().preprocess().convert_element_type(element::f32).convert_color(preprocess::ColorFormat::RGB).scale({255.,255.,255.});
    ppp.input().model().set_layout("NCHW");
    model = ppp.build();
    compiled_model = core.compile_model(model,"GPU");
    infer_request = compiled_model.create_infer_request();
  }

private:
  float fps = 0.0;
  std::shared_ptr<image_transport::ImageTransport> it_;
  image_transport::Subscriber img_sub_;

  //read password
  std::string password;
  int last_id = -1;

  Resize resize_and_pad(Mat& img,Size new_shape){
        float width = img.cols;
        float height = img.rows;

        float r = (float)(new_shape.width/max(width,height));
        int new_unpadW = int(round(width*r));
        int new_unpadH = int(round(height*r));
        Resize resize;
        cv::resize(img, resize.resized_image, Size(new_unpadW,new_unpadH), 0, 0,INTER_AREA);

        resize.dw = new_shape.width - new_unpadW;
        resize.dh = new_shape.height - new_unpadH;
        Scalar color = Scalar(100,100,100);
        copyMakeBorder(resize.resized_image, resize.resized_image, 0, resize.dh, 0, resize.dw, cv::BORDER_CONSTANT, color);

        return resize;
    }

  void image_callback(const sensor_msgs::msg::Image::ConstSharedPtr &msg) {

    try {
      // Konversi dari ROS Image ke OpenCV Mat
      Resize res;
      
      img = cv_bridge::toCvCopy(msg, "bgr8")->image;

      res = resize_and_pad(img,Size(640,640));

      auto start_time = chrono::high_resolution_clock::now();
      cv::waitKey(10);
      
      float *input_data = (float*) res.resized_image.data;
        
      Tensor input_tensor = Tensor(compiled_model.input().get_element_type(), compiled_model.input().get_shape(), input_data);
        
        infer_request.set_input_tensor(input_tensor);
        infer_request.infer();
        
        const Tensor &output_tensor = infer_request.get_output_tensor();
        Shape output_shape = output_tensor.get_shape();
        
        float *detections = output_tensor.data<float>();
        
        vector<cv::Rect> boxes;
        vector<int> class_ids;
        vector<float> confidences;

        for (size_t i = 0; i < output_shape[1]; i++){
            float *detection = &detections[i * output_shape[2]];

            float confidence = detection[4];
      
            if (confidence >= CONFIDENCE_THRESHOLD){
                float *classes_scores = &detection[5];
                cv::Mat scores(1, output_shape[2] - 5, CV_32FC1, classes_scores);
                cv::Point class_id;
                double max_class_score;
                cv::minMaxLoc(scores, 0, &max_class_score, 0, &class_id);

                if (max_class_score > SCORE_THRESHOLD){

                    confidences.push_back(confidence);

                    class_ids.push_back(class_id.x);

                    float x = detection[0];
                    float y = detection[1];
                    float w = detection[2];
                    float h = detection[3];

                    float xmin = x - (w / 2);
                    float ymin = y - (h / 2);

                    boxes.push_back(cv::Rect(xmin, ymin, w, h));
                }
            }
        }
      
        std::vector<int> nms_result;
      
        cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, nms_result);
      
        std::vector<Detection> output; 
      
        for (size_t i = 0; i < nms_result.size(); i++)
        {
            Detection result;
            int idx = nms_result[i];
            result.class_id = class_ids[idx];
            result.confidence = confidences[idx];
            result.box = boxes[idx];
            output.push_back(result);
        }
      
        int width = img.cols;
        int height = img.rows;
        int mid_x = width / 2;
        int mid_y = height / 2;
        
        std::vector<Detection> q1, q2, q3, q4;

        for(const auto &detection : output) {
            // get center
            int cx = detection.box.x + detection.box.width / 2;
            int cy = detection.box.y + detection.box.height / 2;

            if (cx >= mid_x && cy < mid_y) {
                q1.push_back(detection); // Right-Top
            } else if (cx < mid_x && cy < mid_y) {
                q2.push_back(detection); // Left-Top
            } else if (cx < mid_x && cy >= mid_y) {
                q3.push_back(detection); // Bottom-Left
            } else if (cx >= mid_x && cy >= mid_y) {
                q4.push_back(detection); // Bottom-Right
            }
        }

        //read in order
        std::vector<Detection> sorted_output;
        sorted_output.insert(sorted_output.end(), q1.begin(), q1.end());
        sorted_output.insert(sorted_output.end(), q2.begin(), q2.end());
        sorted_output.insert(sorted_output.end(), q3.begin(), q3.end());
        sorted_output.insert(sorted_output.end(), q4.begin(), q4.end());

        //read password
        for (size_t i = 0; i < sorted_output.size(); i++)
        {
            auto detection = sorted_output[i];
            auto box = detection.box;
            auto classId = detection.class_id;
            // auto confidence = detection.confidence;


            char detected_char;

            if(classId>=0 && classId<10)
              detected_char = '0' + classId; // Class 0-9 maps to '0'-'9'
            else if(classId >= 10 && classId < 36)
              detected_char = 'A' + (classId - 10); // Class 10-35 maps to 'A'-'Z'
            else
              detected_char = '?'; // Unknown class

            if (classId != last_id) {
              password += detected_char;
              last_id = classId;

              // RCLCPP_INFO(this->get_logger(), "Password so far: %s", password.c_str());
              RCLCPP_INFO(this->get_logger(), "Detected Class ID: %d, Character: %c", classId, detected_char);
            }

          //   if (classId != last_id) {
          //     char detected_char;
          
          //     // Adjusted mapping logic
          //     if (classId == 0) {
          //         detected_char = '0'; // Class 0 maps to '0'
          //     } else if (classId == 1) {
          //         detected_char = 'A'; // Class 1 maps to 'A'
          //     } else if (classId == 2) {
          //         detected_char = 'B'; // Class 2 maps to 'B'
          //     } else if (classId == 3) {
          //         detected_char = '?'; // Class 3 maps to 'BUKAN', represented as '?'
          //     } else {
          //         detected_char = '?'; // Default for unknown classes
          //     }
          
          //     password += detected_char;
          //     last_id = classId;
          
          //     RCLCPP_INFO(this->get_logger(), "Password so far: %s", password.c_str());
          // }

            if (output.empty()) {
              last_id = -1; // Reset last_id if no detections
              RCLCPP_INFO(this->get_logger(), "No detections found.");
            }
      
            float rx = (float)img.cols / (float)(res.resized_image.cols - res.dw);
            float ry = (float)img.rows / (float)(res.resized_image.rows - res.dh);
      
            box.x = rx * box.x;
            box.y = ry * box.y;
            box.width = rx * box.width;
            box.height = ry * box.height;
      
            // cout << "Bbox" << i + 1 << ": Class: " << classId << " "
            //     << "Confidence: " << confidence << " Scaled coords: [ "
            //     << "cx: " << (float)(box.x + (box.width / 2)) / img.cols << ", "
            //     << "cy: " << (float)(box.y + (box.height / 2)) / img.rows << ", "
            //     << "w: " << (float)box.width / img.cols << ", "
            //     << "h: " << (float)box.height / img.rows << " ]" << endl;
      
            float xmax = box.x + box.width;
            float ymax = box.y + box.height;
      
            // info_obj.center_x = (float)(box.x + (box.width / 2)) / img.cols;
            // info_obj.center_y = (float)(box.y + (box.height / 2)) / img.rows;
      
            cv::rectangle(img, cv::Point(box.x, box.y), cv::Point(xmax, ymax), cv::Scalar(0, 255, 0), 3);
            cv::rectangle(img, cv::Point(box.x, box.y - 20), cv::Point(xmax, box.y), cv::Scalar(0, 255, 0), cv::FILLED);
            
            // Display class ID
            cv::putText(img, std::to_string(classId), cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
            
            // Display detected character next to the bounding box
            std::string char_text = std::string(1, detected_char);
            cv::putText(img, char_text, cv::Point(box.x + box.width + 5, box.y + box.height/2), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 255, 255), 2);
        }
      
        auto end_time = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end_time - start_time;
        fps = 1.0 / elapsed.count(); 
      
        // RCLCPP_INFO(this->get_logger(), "FPS: %.2f", fps);
        putText(img, "FPS:" + to_string(fps),cv::Point(10,30),cv::FONT_HERSHEY_SIMPLEX,1.0,cv::Scalar(0,0,0),2);
      
        // RCLCPP_INFO(this->get_logger(), "FPS: %f", fps);
        // obj_pub->publish(this->info_obj);
      
        imshow("Detection Result_2", img);
        cv::waitKey(1); // Wajib untuk memproses event GUI OpenCV

        int key = cv::waitKey(1);
        if (key == 'q' || key == 'Q') {
          std::ofstream outfile("pass_result.txt");
          if(outfile.is_open()) {
            outfile << password << std::endl;
            outfile.close();
            RCLCPP_INFO(this->get_logger(), "Password saved to pass_result.txt: %s", password.c_str());
          } else {
            RCLCPP_ERROR(this->get_logger(), "Failed to open pass_result.txt for writing.");           
          }
        }

    } catch (const cv_bridge::Exception &e) {
      
      RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
    }
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ImageSubscriberNode>();
  node->init();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}