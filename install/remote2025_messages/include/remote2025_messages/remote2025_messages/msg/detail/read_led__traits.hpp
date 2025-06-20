// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice

#ifndef REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__TRAITS_HPP_
#define REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "remote2025_messages/msg/detail/read_led__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace remote2025_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const ReadLed & msg,
  std::ostream & out)
{
  out << "{";
  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: center_x
  {
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << ", ";
  }

  // member: center_y
  {
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << ", ";
  }

  // member: distance_x
  {
    out << "distance_x: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_x, out);
    out << ", ";
  }

  // member: distance_y
  {
    out << "distance_y: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ReadLed & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }

  // member: center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << "\n";
  }

  // member: center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << "\n";
  }

  // member: distance_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_x: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_x, out);
    out << "\n";
  }

  // member: distance_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_y: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ReadLed & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace remote2025_messages

namespace rosidl_generator_traits
{

[[deprecated("use remote2025_messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const remote2025_messages::msg::ReadLed & msg,
  std::ostream & out, size_t indentation = 0)
{
  remote2025_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use remote2025_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const remote2025_messages::msg::ReadLed & msg)
{
  return remote2025_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<remote2025_messages::msg::ReadLed>()
{
  return "remote2025_messages::msg::ReadLed";
}

template<>
inline const char * name<remote2025_messages::msg::ReadLed>()
{
  return "remote2025_messages/msg/ReadLed";
}

template<>
struct has_fixed_size<remote2025_messages::msg::ReadLed>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<remote2025_messages::msg::ReadLed>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<remote2025_messages::msg::ReadLed>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__TRAITS_HPP_
