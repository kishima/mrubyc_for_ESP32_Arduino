/*
  ext_m5stack.cpp

  Defining extension methods of Arduino
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/
#ifdef ARDUINO_M5Stack_Core_ESP32

#include "mrubyc_for_ESP32_Arduino.h"
#include "ext.h"
#include <M5Stack.h>

static uint16_t sym_to_colorcode(mrb_sym sym_in){
	uint16_t col = BLACK;

	if(sym_in == str_to_symid("WHITE")){
		col = WHITE;
	}else if(sym_in == str_to_symid("RED")){
		col = RED;
	}else if(sym_in == str_to_symid("GREEN")){
		col = GREEN;
	}else if(sym_in == str_to_symid("BLUE")){
		col = BLUE;
	}else if(sym_in == str_to_symid("BLACK")){
		col = BLACK;
	}
	return col;
}
static void class_m5_update(mrb_vm *vm, mrb_value *v, int argc ){
	M5.update();
	SET_NIL_RETURN();
}

static void class_lcd_width(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_lcd_height(mrb_vm *vm, mrb_value *v, int argc ){

}

static void class_lcd_fillScreen(mrb_vm *vm, mrb_value *v, int argc ){
	mrb_sym sym_in = 0;
	if(argc==0){
		sym_in = str_to_symid("BLACK");
	}else{
		if(GET_TT_ARG(1) == MRB_TT_SYMBOL){
			sym_in = GET_INT_ARG(1);
		}else if(GET_TT_ARG(1) == MRB_TT_STRING){
			sym_in = str_to_symid((const char *)GET_STRING_ARG(1));
		}else{
			SET_FALSE_RETURN();
			return;
		}
	}
	uint16_t col = sym_to_colorcode( sym_in );
	M5.Lcd.fillScreen(col);
	SET_TRUE_RETURN();
}

static void class_lcd_setCursor(mrb_vm *vm, mrb_value *v, int argc ){
	if(argc!=4){
		SET_FALSE_RETURN();
		return;
	}
	int16_t x=0, y=0;
	M5.Lcd.setCursor(x, y);
	SET_NIL_RETURN();
}
static void class_lcd_set_text_color(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_lcd_set_text_size(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_lcd_printf(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_lcd_draw_rect(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_lcd_fill_rect(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_draw_circle(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_fill_circle(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_draw_triangle(mrb_vm *vm, mrb_value *v, int argc ){

}
static void class_fill_triangle(mrb_vm *vm, mrb_value *v, int argc ){

}
void define_m5stack_class(void){
	M5.begin();
	mrb_class *class_m5;
	class_m5 = mrbc_define_class(0, "M5", mrbc_class_object);
	mrbc_define_method(0, class_m5, "update", class_m5_update);

	mrb_class *class_lcd;
	class_lcd = mrbc_define_class(0, "Lcd", class_m5);
	mrbc_define_method(0, class_lcd, "width", class_lcd_width);
	mrbc_define_method(0, class_lcd, "height", class_lcd_height);
	mrbc_define_method(0, class_lcd, "fill_screen", class_lcd_fillScreen);
	mrbc_define_method(0, class_lcd, "set_cursor", class_lcd_setCursor);
	mrbc_define_method(0, class_lcd, "set_text_color", class_lcd_set_text_color);
	mrbc_define_method(0, class_lcd, "set_text_size", class_lcd_set_text_size);
	mrbc_define_method(0, class_lcd, "printf", class_lcd_printf);
	mrbc_define_method(0, class_lcd, "draw_rect", class_lcd_draw_rect);
	mrbc_define_method(0, class_lcd, "fill_rect", class_lcd_fill_rect);
	mrbc_define_method(0, class_lcd, "draw_circle", class_draw_circle);
	mrbc_define_method(0, class_lcd, "fill_circle", class_fill_circle);
	mrbc_define_method(0, class_lcd, "draw_triangle", class_draw_triangle);
	mrbc_define_method(0, class_lcd, "fill_triangle", class_fill_triangle);

}

#endif //ARDUINO_M5Stack_Core_ESP32

