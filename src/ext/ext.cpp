/*
  ext.cpp

  Defining extension methods for ESP32
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "mrubyc_for_ESP32_Arduino.h"
#include "ext.h"

bool mrbc_trans_cppbool_value(mrb_vtype tt)
{
	if(tt==MRB_TT_TRUE){
		return true;
	}
	return false;
}

void mrbc_define_methods(void)
{
	define_arduino_class();
	define_serial_class();
	//define_esp32_class();
}

