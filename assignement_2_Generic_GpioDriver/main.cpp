
#include <iostream>
#include "GPIO.cpp"

int main(){
    MControllers microcontroller = AVR;
    Port *PORTA0;
    PinMode mode = PINMODE_INPUT;
    int portValue = 0;
    GPIO GPIOA; /* an object from GPIO class */

    GPIOA.GPIO_Init();

    GPIOA.GPIO_writePort(PORTA0,mode);

    portValue = GPIOA.GPIO_ReadPort(PORTA0);

    GPIOA.GPIO_DeInit();

    return 0;
}