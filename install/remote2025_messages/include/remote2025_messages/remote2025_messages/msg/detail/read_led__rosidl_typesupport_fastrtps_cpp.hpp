// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice

#ifndef REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "remote2025_messages/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "remote2025_messages/msg/detail/read_led__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace remote2025_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_remote2025_messages
cdr_serialize(
  const remote2025_messages::msg::ReadLed & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_remote2025_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  remote2025_messages::msg::ReadLed & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_remote2025_messages
get_serialized_size(
  const remote2025_messages::msg::ReadLed & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_remote2025_messages
max_serialized_size_ReadLed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace remote2025_messages

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_remote2025_messages
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, remote2025_messages, msg, ReadLed)();

#ifdef __cplusplus
}
#endif

#endif  // REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
