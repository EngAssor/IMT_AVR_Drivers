#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

// Array: Display numbers on a seven-segment display in common cathode configuration
const u8 SSD_arrNumbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x4F};

u8 SSD_voidSendNumber(SSD_Type Copy_structConfig, u8 Copy_u8Number)
{
    if (Copy_structConfig.Type == SSD_COMMON_CATHOD)
    {
        DIO_enumSetPortValue(Copy_structConfig.DataPort, SSD_arrNumbers[Copy_u8Number]);
    }
    else if (Copy_structConfig.Type == SSD_COMMON_ANOD)
    {
        // coomon cathod is the reverse of the cooman anod so we just compliment the data
        DIO_enumSetPortValue(Copy_structConfig.DataPort, ~(SSD_arrNumbers[Copy_u8Number]));
    }
}
void SSD_voidEnable(SSD_Type Copy_structConfig)
{
    if (Copy_structConfig.Type == SSD_COMMON_CATHOD)
    {
        DIO_enumSetPINValue(Copy_structConfig.EnablePORT, Copy_structConfig.EnablePin, DIO_LOW);
    }
    else if (Copy_structConfig.Type == SSD_COMMON_ANOD)
    {
        // common cathod is the reverse of the cooman anod so we just compliment the enable
        DIO_enumSetPINValue(Copy_structConfig.EnablePORT, Copy_structConfig.EnablePin, DIO_HIGH);
    }
}
void SSD_voidDisable(SSD_Type Copy_structConfig)
{
    if (Copy_structConfig.Type == SSD_COMMON_CATHOD)
    {
        DIO_enumSetPINValue(Copy_structConfig.EnablePORT, Copy_structConfig.EnablePin, DIO_HIGH);
    }
    else if (Copy_structConfig.Type == SSD_COMMON_ANOD)
    {
        // common cathod is the reverse of the cooman anod so we just compliment the disable
        DIO_enumSetPINValue(Copy_structConfig.EnablePORT, Copy_structConfig.EnablePin, DIO_LOW);
    }
}
}