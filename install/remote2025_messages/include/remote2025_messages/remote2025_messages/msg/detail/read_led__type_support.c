// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "remote2025_messages/msg/detail/read_led__rosidl_typesupport_introspection_c.h"
#include "remote2025_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "remote2025_messages/msg/detail/read_led__functions.h"
#include "remote2025_messages/msg/detail/read_led__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  remote2025_messages__msg__ReadLed__init(message_memory);
}

void remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_fini_function(void * message_memory)
{
  remote2025_messages__msg__ReadLed__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_member_array[5] = {
  {
    "index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(remote2025_messages__msg__ReadLed, index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(remote2025_messages__msg__ReadLed, center_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(remote2025_messages__msg__ReadLed, center_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(remote2025_messages__msg__ReadLed, distance_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(remote2025_messages__msg__ReadLed, distance_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_members = {
  "remote2025_messages__msg",  // message namespace
  "ReadLed",  // message name
  5,  // number of fields
  sizeof(remote2025_messages__msg__ReadLed),
  remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_member_array,  // message members
  remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_init_function,  // function to initialize message memory (memory has to be allocated)
  remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_type_support_handle = {
  0,
  &remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_remote2025_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, remote2025_messages, msg, ReadLed)() {
  if (!remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_type_support_handle.typesupport_identifier) {
    remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &remote2025_messages__msg__ReadLed__rosidl_typesupport_introspection_c__ReadLed_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
