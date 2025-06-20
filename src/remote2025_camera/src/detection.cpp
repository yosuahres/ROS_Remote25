#include <rclcpp/rclcpp.hpp>
#include <image_transport/image_transport.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <openvino/openvino.hpp>

#include "detect_messages/msg/detect_object.hpp"

#include <chrono>
#include <algorithm>
#include <functional>
#include <memory>
#include <string>

using namespace ov;
using namespace cv;
using namespace std;

//TODO NILAI DEKLARASI
const float SCORE_THRESHOLD = 0.2;
const float NMS_THRESHOLD = 0.4;
const float CONFIDENCE_THRESHOLD = 0.5;

const float NILAI_X_CM = 21.0;
const float NILAI_Y_CM = 16.5;

const int FRAME_SKIP_INFERENCE = 2;

const int SKIP_CALLBACK = 50;
int current_skip_callback = 0;
//TODO NILAI DEKLARASIQ

//TODO Variabel PnP
/*std::vector<cv::Point3f> objectPoints = {
    {-r, -r, 0},   // Kiri atas (dibalik)
    {r, -r, 0},    // Kanan atas (dibalik)
    {r, r, 0},     // Kanan bawah (dibalik)
    {-r, r, 0}     // Kiri bawah (dibalik)
};
*/
vector<cv::Point3f> objectPoints = {
  {-2.75,-2.75,0},
  {2.75,-2.75,0},
  {2.75,2.75,0},
  {-2.75,2.75,0},
};

int counter = 0;

class ImageSubscriberNode : public rclcpp::Node {
public: //TODO ini public
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
  ImageSubscriberNode() : Node("image_subscriber_node") {
    // // Image transport subscriber
    // it_ = std::make_shared<image_transport::ImageTransport>(this->shared_from_this());
    // img_sub_ = it_->subscribe(
    //   "camera/image", // Topic yang sama dengan publisher
    //   10,
    //   std::bind(&ImageSubscriberNode::image_callback, this, std::placeholders::_1));
    pub_info_obj = this->create_publisher<detect_messages::msg::DetectObject> ("bismillah",5);
    Timer_1 = this->create_wall_timer(std::chrono::milliseconds(33),std::bind(&ImageSubscriberNode::pub_callback, this));
  }

  void init() {
        auto start_time = chrono::high_resolution_clock::now();
        
        it_ = std::make_shared<image_transport::ImageTransport>(this->shared_from_this());
        img_sub_ = it_->subscribe("topic", 5, std::bind(&ImageSubscriberNode::image_callback, this, std::placeholders::_1));
        
        Core core;
        auto model_start_time = chrono::high_resolution_clock::now();
        
        // read model
        shared_ptr<Model> model = core.read_model("/home/ichbinwil/Documents/face_detect_openvino_model/face_detect.xml");
        // shared_ptr<Model> model = core.read_model("/home/ichbinwil/Documents/kamera_bawa_best/best_openvino_model/best.xml");
        // shared_ptr<Model> model = core.read_model("/home/ichbinwil/openvn_test/yolov5s_openvino_model/yolov5s.xml");
        // shared_ptr<Model> model = core.read_model("/home/ichbinwil/Documents/data_model/yolov5s.xml");

        auto model_end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> model_elapsed = model_end_time - model_start_time;
        RCLCPP_INFO(this->get_logger(), "Model loading time: %.2f seconds", model_elapsed.count());
        
        auto ppp_start_time = chrono::high_resolution_clock::now();
        preprocess::PrePostProcessor ppp = preprocess::PrePostProcessor(model);
        ppp.input().tensor().set_element_type(element::u8).set_layout("NHWC").set_color_format(preprocess::ColorFormat::BGR);
        ppp.input().preprocess().convert_element_type(element::f16).convert_color(preprocess::ColorFormat::RGB).scale({255., 255., 255.});
        ppp.input().model().set_layout("NCHW");
        model = ppp.build();
        auto ppp_end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> ppp_elapsed = ppp_end_time - ppp_start_time;
        RCLCPP_INFO(this->get_logger(), "Preprocessing setup time: %.2f seconds", ppp_elapsed.count());
        
        auto compile_start_time = chrono::high_resolution_clock::now();
        compiled_model = core.compile_model(model, "GPU");
        auto compile_end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> compile_elapsed = compile_end_time - compile_start_time;
        RCLCPP_INFO(this->get_logger(), "Model compilation time: %.2f seconds", compile_elapsed.count());
        
        auto infer_start_time = chrono::high_resolution_clock::now();
        infer_request = compiled_model.create_infer_request();
        auto infer_end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> infer_elapsed = infer_end_time - infer_start_time;
        RCLCPP_INFO(this->get_logger(), "Infer request creation time: %.2f seconds", infer_elapsed.count());
        
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end_time - start_time;
        RCLCPP_INFO(this->get_logger(), "Total initialization time: %.2f seconds", elapsed.count());

        RCLCPP_WARN(this->get_logger(), "Model loaded successfully");
        cv::FileStorage fs("/home/ichbinwil/opencv_test/src/calibration.yaml", cv::FileStorage::READ);
        if (!fs.isOpened()) {
            std::cerr << "Error opening calibration file!" << std::endl;
            return;
        }
        fs["cameraMatrix"] >> cameraMatrix;
        fs["distCoeffs"] >> distCoeffs;
        fs.release();
    }

private: //TODO ini private
  rclcpp::Publisher<detect_messages::msg::DetectObject>::SharedPtr pub_info_obj;
  rclcpp::TimerBase::SharedPtr Timer_1;
  Tensor input_tensor;
  detect_messages::msg::DetectObject info_obj;
  float fps = 0.0;
  std::shared_ptr<image_transport::ImageTransport> it_;
  image_transport::Subscriber img_sub_;
  std::atomic<bool> is_prosses = false;

  cv::Mat cameraMatrix, distCoeffs;
  

  //TODO TANDAI
  // float lebar_layar = 0;
  // float tinggi_layar = 0;
  //TODO TANDAI

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

  void pub_callback(){
    pub_info_obj->publish(this->info_obj);
  }

  void image_callback(const sensor_msgs::msg::Image::ConstSharedPtr &msg) {
    if (current_skip_callback < SKIP_CALLBACK) {
      current_skip_callback++;
      return;
    }
    // static int frame_count = 0;
    // if(frame_count % (FRAME_SKIP_INFERENCE + 1) != 0){
    //   frame_count ++;
    //   return;
    // }

    // frame_count ++;

    if(is_prosses.load()) return;
    is_prosses.store(true);

    std::thread prosess_thread([this, msg] {
      try {
        // Konversi dari ROS Image ke OpenCV Mat
        img = cv_bridge::toCvCopy(msg, "bgr8")->image;
        Resize res = resize_and_pad(img,Size(640,640));
  
        auto start_time = chrono::high_resolution_clock::now();
        cv::waitKey(1);
  
        // cv::Mat blob;
        // cv::dnn::blobFromImage(res.resized_image, blob, 1.0/255.0, Size(640, 640), Scalar(), true, false);
        // input_tensor = Tensor(compiled_model.input().get_element_type(), compiled_model.input().get_shape(), blob.ptr<float>());
        
        float *input_data = (float*) res.resized_image.data;
        input_tensor = Tensor(compiled_model.input().get_element_type(), compiled_model.input().get_shape(), input_data);
        
        
        infer_request.set_input_tensor(input_tensor);
  
        //TODO Inferensi
        // infer_request.infer();
        infer_request.start_async();
        infer_request.wait();
  
        // size_t num_outputs = compiled_model.outputs().size();
        // if (num_outputs != 1) {
        //     RCLCPP_ERROR(this->get_logger(), "Model has %zu output tensors, expected 1", num_outputs);
        //     return;
        // }
        // RCLCPP_INFO(this->get_logger(), "Model has %zu output tensors, expected 1", num_outputs);
        
        const Tensor &output_tensor = infer_request.get_output_tensor();
        Shape output_shape = output_tensor.get_shape();
        float *detections = output_tensor.data<float>();
  
        vector<cv::Rect> boxes;
        vector<int> class_ids;
        vector<float> confidences;
  
        for (size_t i = 0; i < output_shape[1]; i++){
  
            float *detection = &detections[i * output_shape[2]];
            float confidence = detection[4];
  
            // RCLCPP_WARN(get_logger(),"NILAI: %ld", output_shape[1]);
  
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
          if (boxes.size() == 0){
              RCLCPP_WARN(this->get_logger(), "No objects detected");
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
          for (size_t i = 0; i < output.size(); i++)
          {
              auto detection = output[i];
              auto box = detection.box;
              auto classId = detection.class_id;
              auto confidence = detection.confidence;
              float rx = (float)img.cols / (float)(res.resized_image.cols - res.dw);
              float ry = (float)img.rows / (float)(res.resized_image.rows - res.dh);
              box.x = rx * box.x;
              box.y = ry * box.y;
              box.width = rx * box.width;
              box.height = ry * box.height;
              // pos_convert_to_pixle(img);
              cout << "Bbox" << i + 1 << ": Class: " << classId << " "
                  << "Confidence: " << confidence << "\n\n Scaled coords: [ \n"
                  << "cx(%): " << (float)(box.x + (box.width / 2)) / img.cols << " "
                  << "cy(%): " << (float)(box.y + (box.height / 2)) / img.rows << ",\n "
                  << "cx(px): " << (float)(box.x + (box.width / 2)) << ", "
                  << "cy(px): " << (float)(box.y + (box.height / 2)) << ",\n "
                  << "cx(cm): " << ((float)(box.x + (box.width / 2)) / img.cols )* NILAI_X_CM << ", "
                  << "cy(cm): " << ((float)(box.y + (box.height / 2)) / img.rows )* NILAI_Y_CM << ",\n\n "
                  << "w: " << (float)box.width / img.cols << ", "
                  << "h: " << (float)box.height / img.rows << " ]" << endl;
              float xmax = box.x + box.width;
              float ymax = box.y + box.height;
              float xmin = box.x;
              float ymin = box.y;
  
              //TODO pakai Pnp?
              vector<cv::Point2f> imagePoints = {
                {xmin , ymin},
                {xmax , ymin},
                {xmax , ymax},
                {xmin , ymax}
              };
              // cv::Mat rvec, tvec;
              // bool success = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);
              // // RCLCPP_INFO(this->get_logger(), "rvec: [%f, %f, %f]", rvec.at<double>(0), rvec.at<double>(1), rvec.at<double>(2));
              // // RCLCPP_INFO(this->get_logger(), "tvec: [%f, %f, %f]", tvec.at<double>(0), tvec.at<double>(1), tvec.at<double>(2));
              // if(success){
              //   RCLCPP_INFO(this->get_logger(), "Berhasil");
              // }else{
              //   RCLCPP_ERROR(this->get_logger(), "GAGAL");
              //   rvec = tvec = 0;
              // }
  
              // vector<cv::Point2f> projectedPoints;
              // cv::projectPoints(objectPoints,rvec,tvec,cameraMatrix,distCoeffs,projectedPoints);
  
              // float x_cm = tvec.at<double>(0, 0);
              // float y_cm = tvec.at<double>(1, 0);
              // float z_cm = tvec.at<double>(2, 0);
  
              // cout << "Jarak dari kiri layar (sumbu x): " << x_cm << " cm" << endl;
              // cout << "Jarak dari atas layar (sumbu y): " << y_cm << " cm" << endl;
              // cout << "Jarak dari kamera (sumbu z): " << z_cm << " cm" << endl;
  
  
              info_obj.center_x = (float)(box.x + (box.width / 2)) / img.cols;
              info_obj.center_y = (float)(box.y + (box.height / 2)) / img.rows;
              info_obj.index = classId;
              // info_obj.distance_x = x_cm;
              // info_obj.distance_y = y_cm;
              cv::rectangle(img, cv::Point(box.x, box.y), cv::Point(xmax, ymax), cv::Scalar(0, 255, 0), 3);
              cv::rectangle(img, cv::Point(box.x, box.y - 20), cv::Point(xmax, box.y), cv::Scalar(0, 255, 0), cv::FILLED);
              cv::putText(img, std::to_string(classId), cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
          }
          auto end_time = std::chrono::high_resolution_clock::now();
          chrono::duration<double> elapsed = end_time - start_time;
          fps = 1.0 / elapsed.count(); // Accurate frame rate calculation
          RCLCPP_INFO(this->get_logger(), "FPS: %.2f", fps);
          putText(img, "FPS:" + to_string(fps),cv::Point(10,30),cv::FONT_HERSHEY_SIMPLEX,1.0,cv::Scalar(0,0,0),2);
          // RCLCPP_INFO(this->get_logger(), "FPS: %f", fps);
          // if(counter == 0){
          //   imshow("Detection Result", img);
          //   counter++;
          //   cv::waitKey(1); // Wajib untuk memproses event GUI OpenCV
          // }else if(counter < 20){
          //   counter = 0;
          // }
          imshow("Detection Result", img);
          cv::waitKey(1);
  
          is_prosses.store(false);
      } catch (const cv_bridge::Exception &e) {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
      }
    });
    prosess_thread.detach();
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