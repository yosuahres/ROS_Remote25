// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from remote2025_messages:msg/ReadLed.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "remote2025_messages/msg/detail/read_led__struct.h"
#include "remote2025_messages/msg/detail/read_led__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool remote2025_messages__msg__read_led__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("remote2025_messages.msg._read_led.ReadLed", full_classname_dest, 41) == 0);
  }
  remote2025_messages__msg__ReadLed * ros_message = _ros_message;
  {  // index
    PyObject * field = PyObject_GetAttrString(_pymsg, "index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->index = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // center_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->center_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // center_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->center_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // distance_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // distance_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * remote2025_messages__msg__read_led__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ReadLed */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("remote2025_messages.msg._read_led");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ReadLed");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  remote2025_messages__msg__ReadLed * ros_message = (remote2025_messages__msg__ReadLed *)raw_ros_message;
  {  // index
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->center_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->center_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
