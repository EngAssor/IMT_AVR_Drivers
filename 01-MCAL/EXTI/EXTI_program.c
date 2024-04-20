
/**
 * created on : Apr 20 ,2024
 * Author : Asser Tanatwy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_confiig.h"

void (*EXTI_CallBack[3])(void) = {NULL};
void EXTI_voidSetCallBack(void (*Cop_pvoidCallBack)(void), u8 Copy_u8EXTILine)
{
    if (Cop_pvoidCallBack != NULL)
    {
        EXTI_CallBack[Copy_u8EXTILine] = Cop_pvoidCallBack;
    }
}

/* Interrupt service routine prototype ISR */
void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
    if (EXTI_CallBack[0] != NULL)
    {
        EXTI_CallBack[0]();
    }
}
void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
    if (EXTI_CallBack[1] != NULL)
    {
        EXTI_CallBack[1]();
    }
}
oid __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
    if (EXTI_CallBack[2] != NULL)
    {
        EXTI_CallBack[2]();
    }
}