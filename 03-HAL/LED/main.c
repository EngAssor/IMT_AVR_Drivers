#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_interface.h"
#include "LED_interface.h"
void DIO_Delay(u32 ticks)
{
u32 x;
for(x=0;x<ticks;x++);

}
int main(void)
{
LED_Type led1={DIO_PORTA,DIO_PIN0,ACTIVE_HIGH};
LED_voidInit(led1);
while(1)
{
	DIO_Delay(60000);
	LED_voidOn(led1);
	DIO_Delay(60000);
	LED_voidOff(led1);

}
return 0;
}
