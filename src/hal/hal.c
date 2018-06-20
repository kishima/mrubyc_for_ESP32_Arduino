/*
  hal.c
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.
*/

#include "hal.h"

void hal_init(void)
{
}

int hal_write(int fd, const void *buf, int nbytes)
{
	char* t = (char*)buf;
	char tbuf[2];
	if(nbytes==1){
		tbuf[0]=*t;
		tbuf[1]='\0';
		hal_write_string(tbuf);
		return nbytes;
	}
	hal_write_string(t);
	return nbytes;
}

