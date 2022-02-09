#ifndef _GPIO_H
#define _GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum microcontrollers{
    AVR,
    ARM
}MControllers;

typedef enum digitalValue{
	LOW,
	HIGH
}Digital;

typedef enum pinMode{
    #ifdef AVR
    PINMODE_INPUT = 0,
    PINMODE_OUTPUT = 1
    #elif ARM
	PINMODE_OPENDRAIN = 0,
	PINMODE_INPUT = 2,
	PINMODE_PULLUP = 4,
	PINMODE_PULLDOWN = 8
    #endif
}PinMode;

#ifdef ARM
    typedef enum GPIO_Edge{
        EDGE_NONE,     
        GPIO_EDGE_RISING,   
        GPIO_EDGE_FALLING,  
        GPIO_EDGE_BOTH      
    } gpio_edge;
#endif

union Port{
	struct{
		char B0:1;
		char B1:1;
		char B2:1;
		char B3:1;
		char B4:1;
		char B5:1;
		char B6:1;
		char B7:1;
	}Pin;
	char Byte;
};

class GPIO{

    public:
    void GPIO_Init();
    void GPIO_DeInit();

    /* Setters */
    void GPIO_writePort(Port* gpio_port,PinMode mode);
    void GPIO_WritePin(Port* gpio_pin, Digital value);
    void GPIO_TogglePin(Port* gpio_pin);

    /* Getters */
    int GPIO_ReadPin(Port* gpio_pin);
    int GPIO_ReadPort(Port* gpio_port);

    /* Miscellaneous Properties */
    #ifdef ARM
    void GPIO_LockPin(Port* gpio_pin);
    #endif
};
/* Primary Functions */

#ifdef __cplusplus
}
#endif

#endif