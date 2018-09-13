#define F_CPU 4915200

#include "UARTdriver.h"
#include <util/delay.h>
#include <stdio.h>
#include "latch.h"



void main()
{
    USART_Init(MYUBRR);
   en_eMem();
    char *p;
    while(1){
      printf("Hello world %d\n\r", 42);
    }
/*
    //  p=(char *)0xFFFF;
      //*p=0xFF;
      //_delay_ms(1000);

    //  p=(char *)0xFF00;
    //  *p=0x00;
     _delay_ms(2000);

      SRAM_test();

*/


}
