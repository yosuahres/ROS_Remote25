cmake_minimum_required(VERSION 3.8)
project(remote2025_camera)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(rosidl_default_generators REQUIRED) # Jika Anda menggunakan message custom
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenVINO REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# Export dependencies for downstream packages (important!)
ament_export_dependencies(rclcpp OpenCV sensor_msgs cv_bridge image_transport OpenVINO)
ament_export_include_directories(include) # Jika Anda punya header di direktori include

add_executable(camera src/readCamera.cpp)
add_executable(detection src/detection.cpp)

ament_target_dependencies(camera rclcpp  sensor_msgs cv_bridge image_transport)
ament_target_dependencies(detection rclcpp OpenCV sensor_msgs cv_bridge image_transport OpenVINO)


target_include_directories(camera PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_include_directories(detection PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_link_libraries(camera ${OpenCV_LIBRARIES})
target_link_libraries(detection ${OpenCV_LIBRARIES} openvino::runtime)

install(TARGETS 
  camera
  detection
  DESTINATION lib/${PROJECT_NAME})


# Install include directory (if you have one)
install(DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
