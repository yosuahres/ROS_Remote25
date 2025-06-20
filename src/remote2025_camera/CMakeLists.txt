cmake_minimum_required(VERSION 3.8)
project(remote2025_camera)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(remote2025_messages REQUIRED)
find_package(rosidl_default_generators REQUIRED) 
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenVINO REQUIRED)

# Export dependencies for downstream packages (important!)
ament_export_dependencies(rclcpp OpenCV sensor_msgs cv_bridge image_transport OpenVINO remote2025_messages)
ament_export_include_directories(include) 

add_executable(camera src/readCamera.cpp)
add_executable(detection src/detection.cpp)
add_executable(listenCam src/listenCamera.cpp)

# Use ament_target_dependencies for ROS 2 dependencies
ament_target_dependencies(camera rclcpp  sensor_msgs cv_bridge image_transport)

ament_target_dependencies(listenCam rclcpp  sensor_msgs cv_bridge image_transport)

ament_target_dependencies(detection rclcpp OpenCV sensor_msgs cv_bridge image_transport OpenVINO remote2025_messages)

target_include_directories(camera PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>) 

target_include_directories(listenCam PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>) 

target_include_directories(detection PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# Link libraries (OpenCV and OpenVINO)
target_link_libraries(camera ${OpenCV_LIBRARIES})

target_link_libraries(detection ${OpenCV_LIBRARIES} openvino::runtime)


install(TARGETS
  camera
  detection
  listenCam
  DESTINATION lib/${PROJECT_NAME}
)

# Install include directory (if you have one)
install(DIRECTORY include/
  DESTINATION include
)

ament_package()