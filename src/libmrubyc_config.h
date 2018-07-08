/*
  libmrubyc_config.h

  Header file for Arduino application
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/
#ifndef __LIBMRUBYC_CONFIG_H__
#define __LIBMRUBYC_CONFIG_H__

#define ESP32MRBC_VERSION "0.1.0"

/* Specific Devices */
//#define USE_GPS_NEO6M
//#define USE_RTC
#define USE_M5AVATAR

/* for remote mrib */
#define ENABLE_RMIRB

/* for debug */
#define ESP32_DEBUG

#ifdef ESP32_DEBUG
#define DEBUG_SERIAL_BAUDRATE 115200
#define DEBUG_PRINT(val)    Serial.print(val)
#define DEBUG_PRINTLN(val)  Serial.println(val)
#else
#define DEBUG_PRINT(val)
#define DEBUG_PRINTLN(val)
#endif

#endif

