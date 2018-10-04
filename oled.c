#include "oled.h"
#include "fonts.h"
#define COMMAND 0x1000
#define DATA 0x1200



volatile uint8_t *p = 0x1000;
volatile uint8_t *q = 0x1200;








void write_c(uint8_t x){
  *p=x;
}

void write_d(uint8_t x){
  *q=x;
}


const unsigned char try[4]={0b00000000,0b01111100,0b00000000,0b00000000};



void oled_init(){
    write_c(0xae); // display off
    write_c(0xa1);//segment remap
    write_c(0xda);//common pads hardware: alternative
    write_c(0x12);
    write_c(0xc8); //common output scan direction:com63~com0
    write_c(0xa8);//multiplex ration mode:63
    write_c(0x3f);
    write_c(0xd5); //display  divide ratio/osc. freq. mode
    write_c(0x80);
    write_c(0x81);//contrast contro
    write_c(0x50);
    write_c(0xd9);//set pre-charge period
    write_c(0x21);
    write_c(0x20); //Set Memory Addressing Mode
    write_c(0x02);
    write_c(0xdb); //VCOM deselect level mod
    write_c(0x30);
    write_c(0xad);//master configuration
  //  write_c(0x00);//set lower column start adress
    write_c(0xa4); //out follows RAM content
    write_c(0xa6);//set normal display

    write_c(0xaf);// display on
}

void clean(){
  write_c(0xb0);
  write_c(0x00);
  write_c(0x10);
  for(uint8_t i=0;i<8;i++){
    write_c(0xb0 ¦ i);
    write_c(0x00);
    write_c(0x10);
    for(uint8_t j=0; i<128;){
      write_d(0xFF);
    }
  }
}

void test_oled(){
  for(int i=0;i<7;i++){
    oled_pos(i,0);
    for(int j=0; i<16;j++){
      write_letter('0');
    }
  }
}

void test_oled_2(){
  //write_c(0xb0);
  //write_c(0x00);
  //write_c(0x10);
  write_d(0xFF);
}

void oled_reset(){

}

void go_to_column(char column){
    volatile uint8_t higher, lower;
    higher=((uint8_t)column)>>4;
    higher=higher+0x10;
    lower=((uint8_t)column)<<4;
    lower=lower>>4;
    write_c(higher);
    write_c(lower);
    printf("HIGH %02X LOW %02X \n\r", higher, lower );
}

void go_to_line(char line){
    write_c(0xb0|(uint8_t)line);
}


void oled_pos(char row, char column){
    go_to_line(row);
    go_to_column(column);
    printf("ROW %c COLUMN %c \n\r",row,column );
}

void write_letter(const char letter){
    for(short int i=0;i<8;i++){
      write_d(font8[letter-' '][i]);
      printf("%b \n\r",font8[letter-' '][i]);
    }
}

void oled_print(const char *word){
  int i=0;
  while(word[i]!='\0'){
      write_letter(word[i]);
      i++;
  }
}



/*void printing(){
    volatile char *p=(char *)0x1200;
    /*uint16_t ext_ram_size=0x200;
    for(uint16_t i=0;i<ext_ram_size;i++){
        for(uint8_t j=0;j<4;j++){
            *p=try[j];
        }
    }
    *p=0xFF;
}*/
