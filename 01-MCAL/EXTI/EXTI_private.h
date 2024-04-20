
/**
 * created on : Apr 20 ,2024
 * Author : Asser Tanatwy
*/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR_REG     *((volatile u8 *)0x55)
#define MCUCSR_REG    *((volatile u8 *)0x54)
#define GICR_REG      *((volatile u8 *)0x5B)
#define GIFR_REG      *((volatile u8 *)0x5A )

#define NULL 0

#endif