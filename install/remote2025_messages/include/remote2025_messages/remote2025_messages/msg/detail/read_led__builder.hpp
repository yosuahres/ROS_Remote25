// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice

#ifndef REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__BUILDER_HPP_
#define REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "remote2025_messages/msg/detail/read_led__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace remote2025_messages
{

namespace msg
{

namespace builder
{

class Init_ReadLed_distance_y
{
public:
  explicit Init_ReadLed_distance_y(::remote2025_messages::msg::ReadLed & msg)
  : msg_(msg)
  {}
  ::remote2025_messages::msg::ReadLed distance_y(::remote2025_messages::msg::ReadLed::_distance_y_type arg)
  {
    msg_.distance_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::remote2025_messages::msg::ReadLed msg_;
};

class Init_ReadLed_distance_x
{
public:
  explicit Init_ReadLed_distance_x(::remote2025_messages::msg::ReadLed & msg)
  : msg_(msg)
  {}
  Init_ReadLed_distance_y distance_x(::remote2025_messages::msg::ReadLed::_distance_x_type arg)
  {
    msg_.distance_x = std::move(arg);
    return Init_ReadLed_distance_y(msg_);
  }

private:
  ::remote2025_messages::msg::ReadLed msg_;
};

class Init_ReadLed_center_y
{
public:
  explicit Init_ReadLed_center_y(::remote2025_messages::msg::ReadLed & msg)
  : msg_(msg)
  {}
  Init_ReadLed_distance_x center_y(::remote2025_messages::msg::ReadLed::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return Init_ReadLed_distance_x(msg_);
  }

private:
  ::remote2025_messages::msg::ReadLed msg_;
};

class Init_ReadLed_center_x
{
public:
  explicit Init_ReadLed_center_x(::remote2025_messages::msg::ReadLed & msg)
  : msg_(msg)
  {}
  Init_ReadLed_center_y center_x(::remote2025_messages::msg::ReadLed::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_ReadLed_center_y(msg_);
  }

private:
  ::remote2025_messages::msg::ReadLed msg_;
};

class Init_ReadLed_index
{
public:
  Init_ReadLed_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReadLed_center_x index(::remote2025_messages::msg::ReadLed::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_ReadLed_center_x(msg_);
  }

private:
  ::remote2025_messages::msg::ReadLed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::remote2025_messages::msg::ReadLed>()
{
  return remote2025_messages::msg::builder::Init_ReadLed_index();
}

}  // namespace remote2025_messages

#endif  // REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__BUILDER_HPP_
