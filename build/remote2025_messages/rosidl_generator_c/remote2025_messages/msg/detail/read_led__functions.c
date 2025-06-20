// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice
#include "remote2025_messages/msg/detail/read_led__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
remote2025_messages__msg__ReadLed__init(remote2025_messages__msg__ReadLed * msg)
{
  if (!msg) {
    return false;
  }
  // index
  // center_x
  // center_y
  // distance_x
  // distance_y
  return true;
}

void
remote2025_messages__msg__ReadLed__fini(remote2025_messages__msg__ReadLed * msg)
{
  if (!msg) {
    return;
  }
  // index
  // center_x
  // center_y
  // distance_x
  // distance_y
}

bool
remote2025_messages__msg__ReadLed__are_equal(const remote2025_messages__msg__ReadLed * lhs, const remote2025_messages__msg__ReadLed * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // index
  if (lhs->index != rhs->index) {
    return false;
  }
  // center_x
  if (lhs->center_x != rhs->center_x) {
    return false;
  }
  // center_y
  if (lhs->center_y != rhs->center_y) {
    return false;
  }
  // distance_x
  if (lhs->distance_x != rhs->distance_x) {
    return false;
  }
  // distance_y
  if (lhs->distance_y != rhs->distance_y) {
    return false;
  }
  return true;
}

bool
remote2025_messages__msg__ReadLed__copy(
  const remote2025_messages__msg__ReadLed * input,
  remote2025_messages__msg__ReadLed * output)
{
  if (!input || !output) {
    return false;
  }
  // index
  output->index = input->index;
  // center_x
  output->center_x = input->center_x;
  // center_y
  output->center_y = input->center_y;
  // distance_x
  output->distance_x = input->distance_x;
  // distance_y
  output->distance_y = input->distance_y;
  return true;
}

remote2025_messages__msg__ReadLed *
remote2025_messages__msg__ReadLed__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  remote2025_messages__msg__ReadLed * msg = (remote2025_messages__msg__ReadLed *)allocator.allocate(sizeof(remote2025_messages__msg__ReadLed), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(remote2025_messages__msg__ReadLed));
  bool success = remote2025_messages__msg__ReadLed__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
remote2025_messages__msg__ReadLed__destroy(remote2025_messages__msg__ReadLed * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    remote2025_messages__msg__ReadLed__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
remote2025_messages__msg__ReadLed__Sequence__init(remote2025_messages__msg__ReadLed__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  remote2025_messages__msg__ReadLed * data = NULL;

  if (size) {
    data = (remote2025_messages__msg__ReadLed *)allocator.zero_allocate(size, sizeof(remote2025_messages__msg__ReadLed), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = remote2025_messages__msg__ReadLed__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        remote2025_messages__msg__ReadLed__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
remote2025_messages__msg__ReadLed__Sequence__fini(remote2025_messages__msg__ReadLed__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      remote2025_messages__msg__ReadLed__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

remote2025_messages__msg__ReadLed__Sequence *
remote2025_messages__msg__ReadLed__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  remote2025_messages__msg__ReadLed__Sequence * array = (remote2025_messages__msg__ReadLed__Sequence *)allocator.allocate(sizeof(remote2025_messages__msg__ReadLed__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = remote2025_messages__msg__ReadLed__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
remote2025_messages__msg__ReadLed__Sequence__destroy(remote2025_messages__msg__ReadLed__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    remote2025_messages__msg__ReadLed__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
remote2025_messages__msg__ReadLed__Sequence__are_equal(const remote2025_messages__msg__ReadLed__Sequence * lhs, const remote2025_messages__msg__ReadLed__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!remote2025_messages__msg__ReadLed__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
remote2025_messages__msg__ReadLed__Sequence__copy(
  const remote2025_messages__msg__ReadLed__Sequence * input,
  remote2025_messages__msg__ReadLed__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(remote2025_messages__msg__ReadLed);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    remote2025_messages__msg__ReadLed * data =
      (remote2025_messages__msg__ReadLed *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!remote2025_messages__msg__ReadLed__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          remote2025_messages__msg__ReadLed__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!remote2025_messages__msg__ReadLed__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
