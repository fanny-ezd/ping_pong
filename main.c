#define F_CPU 4915200

#include "UARTdriver.h"
#include <util/delay.h>
#include <stdio.h>
#include "latch.h"
#include "joystick.h"
#include "oled.h"


void main()
{
    USART_Init(MYUBRR);
   en_eMem();
   joystick test;
 oled_init();
while (1){

   test_oled_2();

}


  // setup_oled();


//    while(1){
//      printf("Hello world %d\n\r", 42);
//    }
/*
    //  p=(char *)0xFFFF;
      //*p=0xFF;
      //_delay_ms(1000);

    //  p=(char *)0xFF00;
    //  *p=0x00;
     _delay_ms(2000);
*/

//    char *a=(char *)0x12FF;



/*while(1){
    printing();
    printf("a");
//}
    //printing();

    //test=return_pos();
    //printf("(X = %d , Y = %d )\n\r",test.X,test.Y );
    //_delay_ms(500);
    //test1();
      //SRAM_test();
}
/*while (1){
p=0x1800;
*p=FF;
_delay_ms(2000);
p=0x1400;
*p=FF;
_delay_ms(2000);
}*/

}
