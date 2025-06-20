// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice

#ifndef REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__STRUCT_HPP_
#define REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__remote2025_messages__msg__ReadLed __attribute__((deprecated))
#else
# define DEPRECATED__remote2025_messages__msg__ReadLed __declspec(deprecated)
#endif

namespace remote2025_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ReadLed_
{
  using Type = ReadLed_<ContainerAllocator>;

  explicit ReadLed_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->distance_x = 0.0f;
      this->distance_y = 0.0f;
    }
  }

  explicit ReadLed_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->distance_x = 0.0f;
      this->distance_y = 0.0f;
    }
  }

  // field types and members
  using _index_type =
    uint8_t;
  _index_type index;
  using _center_x_type =
    float;
  _center_x_type center_x;
  using _center_y_type =
    float;
  _center_y_type center_y;
  using _distance_x_type =
    float;
  _distance_x_type distance_x;
  using _distance_y_type =
    float;
  _distance_y_type distance_y;

  // setters for named parameter idiom
  Type & set__index(
    const uint8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__center_x(
    const float & _arg)
  {
    this->center_x = _arg;
    return *this;
  }
  Type & set__center_y(
    const float & _arg)
  {
    this->center_y = _arg;
    return *this;
  }
  Type & set__distance_x(
    const float & _arg)
  {
    this->distance_x = _arg;
    return *this;
  }
  Type & set__distance_y(
    const float & _arg)
  {
    this->distance_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    remote2025_messages::msg::ReadLed_<ContainerAllocator> *;
  using ConstRawPtr =
    const remote2025_messages::msg::ReadLed_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      remote2025_messages::msg::ReadLed_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      remote2025_messages::msg::ReadLed_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__remote2025_messages__msg__ReadLed
    std::shared_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__remote2025_messages__msg__ReadLed
    std::shared_ptr<remote2025_messages::msg::ReadLed_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ReadLed_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    if (this->center_x != other.center_x) {
      return false;
    }
    if (this->center_y != other.center_y) {
      return false;
    }
    if (this->distance_x != other.distance_x) {
      return false;
    }
    if (this->distance_y != other.distance_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const ReadLed_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ReadLed_

// alias to use template instance with default allocator
using ReadLed =
  remote2025_messages::msg::ReadLed_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace remote2025_messages

#endif  // REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__STRUCT_HPP_
