#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#define F_CPU 4915200
#include <util/delay.h>

typedef struct joystick_position {
    int X;
    int Y;
} joystick;


void test1();
void test2();
void test3();
void test4();
joystick return_pos();
