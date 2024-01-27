<<<<<<< HEAD
#ifndef DIO_BIT_MATH_H_
#define DIO_BIT_MATH_H_
#define SET_BIT(reg,n) (reg |=(1<<n));
#define CLR_BIT(reg,n) (reg &=~(1<<n));
#define TOG_BIT(reg,n) (reg ^=(1<<n));
#define GET_BIT(reg,n) ((reg >>n)&1);
=======
#ifndef DIO_BIT_MATH_H_
#define DIO_BIT_MATH_H_
#define SET_BIT(reg,n) (reg |=(1<<n));
#define CLR_BIT(reg,n) (reg &=~(1<<n));
#define TOG_BIT(reg,n) (reg ^=(1<<n));
#define GET_BIT(reg,n) ((reg >>n)&1);
>>>>>>> fca915e69118b74ca1290cd99c27e22af0acde7d
#endif