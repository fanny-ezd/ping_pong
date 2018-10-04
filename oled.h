#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#define F_CPU 4915200
#include <util/delay.h>
//#include "fonts.h"


void clean();
void test_oled_2();
void oled_init();
void test_oled();
void oled_reset();
void go_to_column(char);
void go_to_line(char);
void oled_pos(char,char);
void write_letter(const char);
void oled_print(const char *);
