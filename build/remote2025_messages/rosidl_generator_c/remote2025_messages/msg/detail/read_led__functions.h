// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice

#ifndef REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__FUNCTIONS_H_
#define REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "remote2025_messages/msg/rosidl_generator_c__visibility_control.h"

#include "remote2025_messages/msg/detail/read_led__struct.h"

/// Initialize msg/ReadLed message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * remote2025_messages__msg__ReadLed
 * )) before or use
 * remote2025_messages__msg__ReadLed__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
bool
remote2025_messages__msg__ReadLed__init(remote2025_messages__msg__ReadLed * msg);

/// Finalize msg/ReadLed message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
void
remote2025_messages__msg__ReadLed__fini(remote2025_messages__msg__ReadLed * msg);

/// Create msg/ReadLed message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * remote2025_messages__msg__ReadLed__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
remote2025_messages__msg__ReadLed *
remote2025_messages__msg__ReadLed__create();

/// Destroy msg/ReadLed message.
/**
 * It calls
 * remote2025_messages__msg__ReadLed__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
void
remote2025_messages__msg__ReadLed__destroy(remote2025_messages__msg__ReadLed * msg);

/// Check for msg/ReadLed message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
bool
remote2025_messages__msg__ReadLed__are_equal(const remote2025_messages__msg__ReadLed * lhs, const remote2025_messages__msg__ReadLed * rhs);

/// Copy a msg/ReadLed message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
bool
remote2025_messages__msg__ReadLed__copy(
  const remote2025_messages__msg__ReadLed * input,
  remote2025_messages__msg__ReadLed * output);

/// Initialize array of msg/ReadLed messages.
/**
 * It allocates the memory for the number of elements and calls
 * remote2025_messages__msg__ReadLed__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
bool
remote2025_messages__msg__ReadLed__Sequence__init(remote2025_messages__msg__ReadLed__Sequence * array, size_t size);

/// Finalize array of msg/ReadLed messages.
/**
 * It calls
 * remote2025_messages__msg__ReadLed__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
void
remote2025_messages__msg__ReadLed__Sequence__fini(remote2025_messages__msg__ReadLed__Sequence * array);

/// Create array of msg/ReadLed messages.
/**
 * It allocates the memory for the array and calls
 * remote2025_messages__msg__ReadLed__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
remote2025_messages__msg__ReadLed__Sequence *
remote2025_messages__msg__ReadLed__Sequence__create(size_t size);

/// Destroy array of msg/ReadLed messages.
/**
 * It calls
 * remote2025_messages__msg__ReadLed__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
void
remote2025_messages__msg__ReadLed__Sequence__destroy(remote2025_messages__msg__ReadLed__Sequence * array);

/// Check for msg/ReadLed message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
bool
remote2025_messages__msg__ReadLed__Sequence__are_equal(const remote2025_messages__msg__ReadLed__Sequence * lhs, const remote2025_messages__msg__ReadLed__Sequence * rhs);

/// Copy an array of msg/ReadLed messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_remote2025_messages
bool
remote2025_messages__msg__ReadLed__Sequence__copy(
  const remote2025_messages__msg__ReadLed__Sequence * input,
  remote2025_messages__msg__ReadLed__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // REMOTE2025_MESSAGES__MSG__DETAIL__READ_LED__FUNCTIONS_H_
