/*
  hal.cpp

  mruby/c hardware abstract layer for EPS32
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include <Arduino.h>
#include "hal.h"

extern "C" void hal_write_string(char* text){
  Serial.print(text);
}

extern "C" void hal_delay(unsigned long t){
  delay(t);
}


