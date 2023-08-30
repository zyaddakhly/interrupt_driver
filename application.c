/* 
 * File:   application.c
 * Author: zyadi
 *
 * Created on August 18, 2023, 8:01 AM
 */

#include "application.h"

Std_ReturnType ret = 0;



led_t led1 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN0,
    .led_status = LED_ON
};
led_t led2 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN1,
    .led_status = LED_ON
};
led_t led3 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN2,
    .led_status = LED_ON
};

led_t led4 = 
{
    .port = PORTC_INDEX,
    .pin = GPIO_PIN3,
    .led_status = LED_ON
};







void Int0_ISR(void)
{
    led_toggle(&led1);
}
void Int1_ISR(void)
{
    led_toggle(&led2);
}
void Int2_ISR(void)
{
    led_toggle(&led3);
}

void RB4_ISR(void)
{
    led_toggle(&led4);
}


interrupt_RBx_t Rb0 = 
{
    .EXT_InterruptHandler = RB4_ISR,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin  = GPIO_PIN4,
    .mcu_pin.direction = GPIO_INPUT,
    .mcu_pin.logic = GPIO_LOW,
    .priority = INTERRUPT_LOW_PRIORITY,
    
    
};
interrupt_INTx_t Intx0 =
{
    .EXT_InterruptHandler = Int0_ISR,
    .edge = INTERRUPT_RASING_EDGE ,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin  = GPIO_PIN0,
    .mcu_pin.direction = GPIO_INPUT,
    .mcu_pin.logic = GPIO_LOW,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_INT0   
    
};
interrupt_INTx_t Intx1 =
{
    .EXT_InterruptHandler = Int1_ISR,
    .edge = INTERRUPT_FALLING_EDGE ,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin  = GPIO_PIN1,
    .mcu_pin.direction = GPIO_INPUT,
    .mcu_pin.logic = GPIO_LOW,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_INT1   
    
};
interrupt_INTx_t Intx2 =
{
    .EXT_InterruptHandler = Int2_ISR,
    .edge = INTERRUPT_RASING_EDGE ,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin  = GPIO_PIN2,
    .mcu_pin.direction = GPIO_INPUT,
    .mcu_pin.logic = GPIO_LOW,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_INT2   
    
};

int main() {
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    ret = led_initialize(&led3);
    ret = led_initialize(&led4);
    ret = interrupt_INTx_init(&Intx0);
    ret = interrupt_INTx_init(&Intx1);
    ret = interrupt_INTx_init(&Intx2);
    ret = interrupt_RBx_init(&Rb0);
    while(1)
    {
        
    }


    return 0;
}

