/*
  ext.h

  Header file of extension methods
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#ifndef __EXT_H_
#define __EXT_H_

#include "libmrubyc_config.h"
#include "value.h"

#define RECV_BUFF_SIZE 1024

bool mrbc_trans_cppbool_value(mrb_vtype tt);

void define_arduino_class(void);
void define_serial_class(void);
#ifdef ARDUINO_M5Stack_Core_ESP32
void define_m5stack_class(void);
#ifdef USE_M5AVATAR
void define_m5avatar_class(void);
#endif
#endif

#endif
