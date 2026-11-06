#include "ds18b20.h"
#include"stm32f103xb.h"
 int main(void)
{
    ds18b20_init();
    uint16_t temp;
    while(1){
 temp = ds18b20_get_temperature();
    }
}
