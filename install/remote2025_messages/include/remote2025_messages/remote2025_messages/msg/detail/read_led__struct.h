// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice

#ifndef REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__STRUCT_H_
#define REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ReadLed in the package remote2025_messages.
typedef struct remote2025_messages__msg__ReadLed
{
  uint8_t index;
  float center_x;
  float center_y;
  float distance_x;
  float distance_y;
} remote2025_messages__msg__ReadLed;

// Struct for a sequence of remote2025_messages__msg__ReadLed.
typedef struct remote2025_messages__msg__ReadLed__Sequence
{
  remote2025_messages__msg__ReadLed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} remote2025_messages__msg__ReadLed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__STRUCT_H_
