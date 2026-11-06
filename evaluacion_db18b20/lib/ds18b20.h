#ifndef ds18b20_h
#define ds18b20_h
#include "stm32f103xb.h"
#define ds18b20_convert 0x44
#define ds18b20_readscratchpad 0xBE
#define ds18b20_writtescratchpad 0x4E
#define ds18b20_readromcommand 0x33
#define ds18b20_puerto GPIOB
#define ds18b20_so_pin 4
#define ds18b20_usop_pin 1
#define ds18b20_to_pin 2
#define ds18b20_dq_pin 14



void ds18b20_init(void);
uint8_t ds18b20_reset();
void ds18b20_write_bit(uint8_t bit);
uint8_t ds18b20_read_bit();
void ds18b20_write_byte(uint8_t bit);
uint8_t ds18b20_read_byte();
void ds18b20_start_conversion();
float ds18b20_get_temperature();

void dq_output(void);
void dq_input(void);
void dq_low(void);
uint8_t dq_read(void);
void delay_ms();
void delay_us();
 #endif;