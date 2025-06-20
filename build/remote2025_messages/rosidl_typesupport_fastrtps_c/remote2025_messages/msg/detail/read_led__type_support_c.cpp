// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice
#include "remote2025_messages/msg/detail/read_led__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "remote2025_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "remote2025_messages/msg/detail/read_led__struct.h"
#include "remote2025_messages/msg/detail/read_led__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ReadLed__ros_msg_type = remote2025_messages__msg__ReadLed;

static bool _ReadLed__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ReadLed__ros_msg_type * ros_message = static_cast<const _ReadLed__ros_msg_type *>(untyped_ros_message);
  // Field name: index
  {
    cdr << ros_message->index;
  }

  // Field name: center_x
  {
    cdr << ros_message->center_x;
  }

  // Field name: center_y
  {
    cdr << ros_message->center_y;
  }

  // Field name: distance_x
  {
    cdr << ros_message->distance_x;
  }

  // Field name: distance_y
  {
    cdr << ros_message->distance_y;
  }

  return true;
}

static bool _ReadLed__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ReadLed__ros_msg_type * ros_message = static_cast<_ReadLed__ros_msg_type *>(untyped_ros_message);
  // Field name: index
  {
    cdr >> ros_message->index;
  }

  // Field name: center_x
  {
    cdr >> ros_message->center_x;
  }

  // Field name: center_y
  {
    cdr >> ros_message->center_y;
  }

  // Field name: distance_x
  {
    cdr >> ros_message->distance_x;
  }

  // Field name: distance_y
  {
    cdr >> ros_message->distance_y;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_remote2025_messages
size_t get_serialized_size_remote2025_messages__msg__ReadLed(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ReadLed__ros_msg_type * ros_message = static_cast<const _ReadLed__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name index
  {
    size_t item_size = sizeof(ros_message->index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_x
  {
    size_t item_size = sizeof(ros_message->center_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_y
  {
    size_t item_size = sizeof(ros_message->center_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name distance_x
  {
    size_t item_size = sizeof(ros_message->distance_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name distance_y
  {
    size_t item_size = sizeof(ros_message->distance_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ReadLed__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_remote2025_messages__msg__ReadLed(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_remote2025_messages
size_t max_serialized_size_remote2025_messages__msg__ReadLed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: center_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: center_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: distance_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: distance_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = remote2025_messages__msg__ReadLed;
    is_plain =
      (
      offsetof(DataType, distance_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ReadLed__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_remote2025_messages__msg__ReadLed(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ReadLed = {
  "remote2025_messages::msg",
  "ReadLed",
  _ReadLed__cdr_serialize,
  _ReadLed__cdr_deserialize,
  _ReadLed__get_serialized_size,
  _ReadLed__max_serialized_size
};

static rosidl_message_type_support_t _ReadLed__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ReadLed,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, remote2025_messages, msg, ReadLed)() {
  return &_ReadLed__type_support;
}

#if defined(__cplusplus)
}
#endif
