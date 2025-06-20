#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>

class Get_Frame : public rclcpp::Node{
public:
Get_Frame():Node("Get_Frame"){
  cap_.open("/dev/v4l/by-id/usb-BC-231018-A_XWF_1080P_PC_Camera-video-index0", cv::CAP_V4L2);
  if(!cap_.isOpened()){
    cap_.open("/dev/v4l/by-id/usb-Generic_HP_TrueVision_HD_Camera_0001-video-index0", cv::CAP_V4L2);
    if(!cap_.isOpened()){
      RCLCPP_ERROR(this->get_logger(), "Error opening camera");
      rclcpp::shutdown();
    }
    cap_.set(cv::CAP_PROP_FPS, 30);
  }
  timer_ = this->create_wall_timer(std::chrono::milliseconds(33), std::bind(&Get_Frame::get_, this));
  //* Muat parameter kalibrasi dari file
  cv::FileStorage fs("/home/ichbinwil/ros2_ws/calibration.yaml", cv::FileStorage::READ);
  if (!fs.isOpened()) {
      std::cerr << "Error opening calibration file!" << std::endl;
      return;
  }
  fs["cameraMatrix"] >> cameraMatrix;
  fs["distCoeffs"] >> distCoeffs;
  fs.release();

  // dapatkan lebar dan panjang layar
  float lebar_layar = cap_.get(cv::CAP_PROP_FRAME_WIDTH);
  float tinggi_layar = cap_.get(cv::CAP_PROP_FRAME_HEIGHT);
  RCLCPP_INFO(this->get_logger(), "Lebar layar: %f", lebar_layar);
  RCLCPP_INFO(this->get_logger(), "Tinggi layar: %f", tinggi_layar);

  cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::UMat(),cameraMatrix, cv::Size(640, 480), CV_32FC1, map1, map2);

}

void init(){
  it_ = std::make_shared<image_transport::ImageTransport>(this->shared_from_this());
  img_publisher_ = it_->advertise("topic", 5);
}
private:
cv::VideoCapture cap_;
rclcpp::TimerBase::SharedPtr timer_;
std::shared_ptr<image_transport::ImageTransport> it_;
image_transport::Publisher img_publisher_;
cv::Mat frame, frame_undistorted;
cv::Mat cameraMatrix, distCoeffs;
cv::UMat map1, map2;
void get_(){
  cap_ >> frame;
  if(frame.empty()){
    RCLCPP_WARN(this->get_logger(),"frame kosong");
    return;
  }
  // cv::undistort(frame, frame_undistorted, cameraMatrix, distCoeffs);
  cv::remap(frame, frame_undistorted, map1, map2, cv::INTER_LINEAR);
  // cv::imshow("result",frame_undistorted);
  // cv::waitKey(1);
  sensor_msgs::msg::Image::SharedPtr msg = cv_bridge::CvImage(std_msgs::msg::Header(),"bgr8",frame_undistorted).toImageMsg();
  // sensor_msgs::msg::Image::SharedPtr msg = cv_bridge::CvImage(std_msgs::msg::Header(),"bgr8",frame).toImageMsg();

  img_publisher_.publish(msg);
}
};

int main(int argc, char ** argv){
  rclcpp::init(argc,argv);
  auto node = std::make_shared<Get_Frame>();
  node->init();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}