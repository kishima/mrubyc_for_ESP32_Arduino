/*
  ext_arduino.cpp

  Defining extension methods of Arduino on Wio LTE
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "libmrubyc.h"
#include "ext.h"

static void class_arduino_delay(mrb_vm *vm, mrb_value *v, int argc )
{
	int d=GET_INT_ARG(1);
	delay(d);
	SET_TRUE_RETURN();
}

static void class_arduino_pin_mode(mrb_vm *vm, mrb_value *v, int argc )
{
	int pin = 0;
	if(GET_TT_ARG(1) == MRB_TT_FIXNUM){
		pin = GET_INT_ARG(1);
	}else{
		SET_FALSE_RETURN();
		return;
	}
	
	WiringPinMode mode = INPUT;
	if(GET_TT_ARG(2) != MRB_TT_SYMBOL){
		SET_FALSE_RETURN();
		return;
	}
	mrb_sym sym_in = str_to_symid((const char *)GET_STRING_ARG(2));
	mrb_sym sym_INPUT = str_to_symid("INPUT");
	mrb_sym sym_OUTPUT = str_to_symid("OUTPUT");
	mrb_sym sym_INPUT_PULLUP = str_to_symid("INPUT_PULLUP");

	if(sym_in == sym_INPUT){
		mode = INPUT;
	}else if(sym_in == sym_OUTPUT){
		mode = OUTPUT;
	}else if(sym_in == sym_INPUT_PULLUP){
		mode = INPUT_PULLUP;
	}else{
		SET_FALSE_RETURN();
		return;
	}
	pinMode(pin,mode);
	SET_TRUE_RETURN();
}

void define_arduino_class()
{
	mrb_class *class_arduino;
	class_arduino = mrbc_define_class(0, "Arduino", mrbc_class_object);
	mrbc_define_method(0, class_arduino, "delay", class_arduino_delay);
	mrbc_define_method(0, class_arduino, "pin_mode", class_arduino_pin_mode);
	mrbc_define_method(0, class_arduino, "digital_wirte", NULL);
	mrbc_define_method(0, class_arduino, "digital_read", NULL);

}

static HardwareSerial* groveSerial = &Serial;

static void class_serial_begin(mrb_vm *vm, mrb_value *v, int argc )
{
	int baud = GET_INT_ARG(1);
	DEBUG_PRINT("groveSerial->begin baudrate=");
	DEBUG_PRINTLN(baud);
	groveSerial->begin(baud);
	SET_TRUE_RETURN();
}
static void class_serial_end(mrb_vm *vm, mrb_value *v, int argc )
{
	groveSerial->end();
	SET_TRUE_RETURN();
}
static void class_serial_available(mrb_vm *vm, mrb_value *v, int argc )
{
	int res = groveSerial->available();
	if(res!=0){
		SET_TRUE_RETURN();
	}else{
		SET_FALSE_RETURN();
	}
}
static void class_serial_readline(mrb_vm *vm, mrb_value *v, int argc )
{
	static char readbuff[120];
	static int readp=0;

	while (groveSerial->available()) {
		char data = groveSerial->read();
		if (data == '\r') continue;
		if (data == '\n') {
			readbuff[readp] = '\0';
			readp = 0;
			mrb_value string = mrbc_string_new_cstr(vm,(const char*)readbuff);
			SET_RETURN(string);
			return;
		}
		
		if (readp > sizeof (readbuff) - 1) { 
			readp = 0;
			DEBUG_PRINT("\nOVERFLOW\n");
			SET_FALSE_RETURN();
			return;
		}
		readbuff[readp++] = data;
	}
	SET_NIL_RETURN();
}
static void class_serial_write(mrb_vm *vm, mrb_value *v, int argc )
{
	
}

void define_serial_class()
{
	mrb_class *class_serial;
	class_serial = mrbc_define_class(0, "Serial", mrbc_class_object);
	mrbc_define_method(0, class_serial, "begin", class_serial_begin);
	mrbc_define_method(0, class_serial, "end", class_serial_end);
	mrbc_define_method(0, class_serial, "available", class_serial_available);
	mrbc_define_method(0, class_serial, "readline", class_serial_readline);
	mrbc_define_method(0, class_serial, "write", class_serial_write);
}

