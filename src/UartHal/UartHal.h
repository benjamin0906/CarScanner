#include "../UartHal_Types.h"

extern void UartHal_InitUart(void);
extern void MyPutc(uint8 *data, uint8 Amount);
extern void MyGetc(uint8* data);
extern void UartHal_Handler(void);

extern dtUartHal UartHal;
