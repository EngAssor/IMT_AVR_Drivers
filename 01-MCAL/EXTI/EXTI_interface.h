
/**
 * created on : Apr 20 ,2024
 * Author : Asser Tanatwy
 */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#define EXTI_LINE0 0
#define EXTI_LINE1 1
#define EXTI_LINE2 2

void EXTI_voidInit      (void);
void EXTI_voidEnable    (u8 Copy_SenceMode,u8 Copy_u8EXTILine);
void EXTI_voidDisable   (u8 Copy_u8EXTILine);
void EXTI_voidClearFlag (u8 Copy_u8EXTILine);


void EXTI_voidSetCallBack(void (*Cop_pvoidCallBack)(void), u8 Copy_u8EXTILine);

#endif