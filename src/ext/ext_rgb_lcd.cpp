/*
  ext_rgb_lcd.cpp

  Defining extension methods of Arduino

  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/
#include "mrubyc_config.h"

#ifdef USE_RGB_LCD

#include "mrubyc_for_ESP32_Arduino.h"
#include "ext.h"
#include <Wire.h>
#include <rgb_lcd.h>

static rgb_lcd* lcd=NULL;

static void class_rbg_lcd_initialize(mrb_vm *vm, mrb_value *v, int argc ){
	SET_NIL_RETURN();
	if(lcd!=NULL){
		DEBUG_PRINTLN("RGB_LCD is already existing!");
		return;
	}
	lcd = new rgb_lcd();
}

void define_rgb_lcd_class(void){
	mrb_class *class_rbg_lcd;
	class_rbg_lcd = mrbc_define_class(0, "RGB_LCD", mrbc_class_object);
	mrbc_define_method(0, class_rbg_lcd, "initialize", class_rbg_lcd_initialize);
	mrbc_define_method(0, class_rbg_lcd, "clear", class_rbg_lcd_initialize);
	mrbc_define_method(0, class_rbg_lcd, "display", class_rbg_lcd_initialize);
	mrbc_define_method(0, class_rbg_lcd, "set_cursor", class_rbg_lcd_initialize);
	mrbc_define_method(0, class_rbg_lcd, "write", class_rbg_lcd_initialize);
	mrbc_define_method(0, class_rbg_lcd, "set_rgb", class_rbg_lcd_initialize);
}


#endif //USE_RGB_LCD
