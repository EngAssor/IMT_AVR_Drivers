#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"
// all the numbers value frome 0 to 9 Common cathod
const u8 SSD_u8ArrNumbers[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x4F};
// function that sets the data and enables pin direction to output 
void SSD_voidInit(SSD_Type Copy_structSSD_Config)
{
    DIO_enumSetPortDirection(Copy_structSSD_Config.Data_Port,DIO_OUTPUT);
    DIO_enumSetPINDirection(Copy_structSSD_Config.Enable_Port,Copy_structSSD_Config.Enable_Pin,DIO_OUTPUT);

}
// function thats sends the value of a number on the data port
void SSD_voidSendNumber(SSD_Type Copy_structSSD_Config,u8 Copy_u8Number)
{
    if(Copy_structSSD_Config.Type == SSD_COMMON_CATHODE)
    {
        DIO_enumSetPortValue(Copy_structSSD_Config.Data_Port, SSD_u8ArrNumbers[Copy_u8Number]);

    }
    else if (Copy_structSSD_Config.Type == SSD_COMMON_ANOD)
    {
        DIO_enumSetPortValue(Copy_structSSD_Config.Data_Port, ~(SSD_u8ArrNumbers[Copy_u8Number]));


    }
}
// function that sets the enable pin to the value that makes the seven segments on
void SSD_voidEnable    (SSD_Type Copy_structSSD_Config)
{
      if(Copy_structSSD_Config.Type == SSD_COMMON_CATHODE)
    {
        DIO_enumSetPINValue(Copy_structSSD_Config.Enable_Port,Copy_structSSD_Config.Enable_Pin,DIO_LOW);

    }
    else if (Copy_structSSD_Config.Type == SSD_COMMON_ANOD)
    {
        DIO_enumSetPINValue(Copy_structSSD_Config.Enable_Port,Copy_structSSD_Config.Enable_Pin,DIO_HIGH);


    }
}
// function that sets the enable pin to the value that makes the seven segments off

void SSD_voidDisable   (SSD_Type Copy_structSSD_Config)
{
        if(Copy_structSSD_Config.Type == SSD_COMMON_CATHODE)
    {
        DIO_enumSetPINValue(Copy_structSSD_Config.Enable_Port,Copy_structSSD_Config.Enable_Pin,DIO_HIGH);

    }
    else if (Copy_structSSD_Config.Type == SSD_COMMON_ANOD)
    {
        DIO_enumSetPINValue(Copy_structSSD_Config.Enable_Port,Copy_structSSD_Config.Enable_Pin,DIO_LOW);


    }
}