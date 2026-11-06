#include "ds18b20.h"
int RI=0;
int RO=0;
uint8_t lsb;
uint8_t msb;
uint16_t tconv;
uint16_t temperatura;
 void ds18b20_init(){
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    GPIOB->CRL &=~(0XF<<(ds18b20_so_pin*4));
    GPIOB->CRL |=(0X4<<(ds18b20_so_pin*4));
    GPIOB->CRL &=~(0XF<<(ds18b20_usop_pin*4));
    GPIOB->CRL |=(0X5<<(ds18b20_usop_pin*4));
    GPIOB->CRL &=~(0XF<<(ds18b20_to_pin*4));
    GPIOB->CRL |=(0XB<<(ds18b20_to_pin*4));
    dq_output();
    dq_low();
 }
 void dq_output(void){
    if(ds18b20_dq_pin<8){
    ds18b20_puerto->CRL&=~(0XF<<(ds18b20_dq_pin*4));
    ds18b20_puerto->CRL |=(0XB<<(ds18b20_dq_pin*4));
    }else{
    ds18b20_puerto->CRH&=~(0XF<<((ds18b20_dq_pin%8)*4));
    ds18b20_puerto->CRH |=(0XB<<((ds18b20_dq_pin%8)*4));
    }
 }
void dq_input(void){
    if(ds18b20_dq_pin<8){
    ds18b20_puerto->CRL&=~(0XF<<(ds18b20_dq_pin*4));
    ds18b20_puerto->CRL |=(0XB<<(ds18b20_dq_pin*4));
    }else{
    ds18b20_puerto->CRH&=~(0XF<<((ds18b20_dq_pin%8)*4));
    ds18b20_puerto->CRH |=(0XB<<((ds18b20_dq_pin%8)*4));
    }
 }
void dq_low(void){
    ds18b20_puerto->BSRR |=(1<<ds18b20_dq_pin);
}
void dq_high(void){
    ds18b20_puerto->BSRR |=(1<<(ds18b20_dq_pin+16));
}
uint8_t ds18b20_reset(){
 dq_low();
    delay_us(480);
 dq_high();
}
void ds18b20_write_bit(uint8_t bit){
    dq_low();
    dq_output();
    for(uint16_t i=0;i<15;i++){
        if(bit & (1<<i)){
            delay_us(15);
        }else{
            delay_us(60);
        }
        }
        dq_high();
    }
uint8_t ds18b20_read_bit(){
    dq_low();
    delay_us(240);
}
void ds18b20_write_byte(uint8_t bit){
    dq_low();
    for(uint16_t i=0;i<<16;i++){
    if(bit&(1<<i)){
        dq_output();
    }else{
      dq_output();
    }
    dq_high();
    }
}
uint8_t ds18b20_read_byte(){
    dq_low();
    for(uint8_t i=0;i<8;i++){
        if(ds18b20_writte_byte()){
    uint8_t lsb= (1<<i);
    }else{
        uint8_t lsb=(0<<i);
    }
     for(uint8_t i=8;i<16;i++){
        if(ds18b20_writte_byte()){

    uint8_t msb= (1<<i);
    }else{
        uint8_t msb=(0<<i);
    }
}
}
}
void ds18b20_start_conversion(void){
    dq_reset();
    dq_input();
    delay_us(60);
    if(dq_read()){
        for(int i=6;i<8;i++){
 if(ds18b20_read_byte(ds18b20_readscratchpad)&(1<<6)){
    int RI= 1;
}else{
    int RI=0;
}
if(ds18b20_read_byte(ds18b20_readscratchpad)&(1<<7)){
           int R0= 1;
}else{
    int RO=0;
}
    }
}else{
     dq_output();
return 0;
}
    delay_us(70);
if(dq_read()){
        for(int i=0;i<2;i++){
            if(i==0){
 if(ds18b20_read_byte(ds18b20_writtescratchpad)&(1<<0)){
    int byte1= 1;
}else{
    int byt1=0;
}
            }
            if(i==1){
if(ds18b20_read_byte(ds18b20_writtescratchpad)&(1<<1)){
           int byte2= 1;
}else{
    int byte2=0;
}
    }
}
}else{
     dq_output();
return 0;
}
    if((RI==0)&(RO==0)){
 uint16_t tconv= ds18b20_read_bit(ds18b20_convert)/8;
delay_ms(93.75);
    }
    if((RI==0)&(RO==1)){
 uint16_t tconv= ds18b20_read_bit(ds18b20_convert)/4;
 delay_ms(187.5);
    }
    if((RI==1)&(RO==0)){
 uint16_t tconv=ds18b20_read_bit(ds18b20_convert)/2;
  delay_ms(375);
    }
    if((RI==1)&(RO==1)){
 uint16_t tconv=ds18b20_read_bit(ds18b20_convert);
 delay_ms(750);
    }
    if(ds18b20_read_byte(msb)){
        if(ds18b20_read_byte(lsb)){
        }
    }
}
uint8_t dq_read(void){
    ds18b20_write_bit(ds18b20_readromcommand);
}
float ds18b20_get_temperature(){
    for(uint8_t i=12;i<16;i++){
    if(msb &(i<<i)){
uint16_t temperatura= tconv-(msb<<8|lsb&0x0f);
}else{
 uint16_t temperatura= tconv+(msb<<8|lsb&0x0f);   
}
}
return temperatura;
}


