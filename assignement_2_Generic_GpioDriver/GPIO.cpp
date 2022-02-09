#include "GPIO.h"


#ifdef __cplusplus
extern "C" {
#endif

/* Primary Functions */
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
void GPIO_LockPin();
#endif

#ifdef __cplusplus
}
#endif
