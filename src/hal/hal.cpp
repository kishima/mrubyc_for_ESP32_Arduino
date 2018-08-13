/*
  hal.cpp

  mruby/c hardware abstract layer for EPS32
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include <Arduino.h>
#include "hal.h"
#include "libmrubyc_config.h"

extern "C" void hal_init_cpp(void){
#ifdef USE_USB_SERIAL_FOR_STDIO
  Serial.begin(DEBUG_SERIAL_BAUDRATE);
#endif
}

extern "C" void hal_write_string(char* text){
#ifdef USE_USB_SERIAL_FOR_STDIO
  Serial.print(text);
#endif
}

extern "C" void hal_delay(unsigned long t){
#ifdef USE_USB_SERIAL_FOR_STDIO
  delay(t);
#endif
}


