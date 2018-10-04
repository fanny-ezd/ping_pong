#include "joystick.h"




void test1(){
    volatile char *p=(char *)0x1400;
    uint8_t val;
    val=*p;
}

void test2(){
    volatile char *p=(char *)0x1400;
    uint8_t valx,valy;
    *p=0x04;
    _delay_us(200);
    valx=*p-0xFF;
    _delay_us(200);
    *p=0x05;
    _delay_us(200);
    valy=*p-0xFF;
    _delay_us(200);
    printf("( %02d , %02d )\n\r", valx, valy);



}

void test3(){
    volatile char *p=(char *)0x1400;
    uint8_t valleft,valright;
    *p=0x06;
    _delay_us(200);
    valleft=*p-0xFF;
    _delay_us(200);
    *p=0x07;
    _delay_us(200);
    valright=*p-0xFF;
    _delay_us(200);
    printf("( %02d , %02d )\n\r", valleft, valright);


}

void test4(){
    volatile char *p=(char *)0x1400;
    uint8_t valleft,valright,valleft_Voltage,valright_Voltage;
    *p=0x06;
    _delay_us(200);
    valleft=*p-0xFF;
    valleft_Voltage= valleft*5/255;
    _delay_us(200);
    *p=0x07;
    _delay_us(200);
    valright=*p-0xFF;
    valright_Voltage=valright*5/255;
    _delay_us(200);
    printf("( %02d , %02d )\n\r", valleft_Voltage, valright_Voltage);


}

joystick return_pos (){
    volatile char *p=(char *)0x1400;
    uint8_t valx,valy;
    joystick a;
    *p=0x04;
    _delay_us(200);
    valx=*p-0xFF;
    _delay_us(200);
    *p=0x05;
    _delay_us(200);
    valy=*p-0xFF;
    _delay_us(200);
    a.X=((int)valx-0x80)*100/127;
    a.Y=((int)valy-0x80)*100/127;
    return a;
}
