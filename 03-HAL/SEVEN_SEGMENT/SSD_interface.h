#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#define SSD_COMMON_CATHOD    0
#define SSD_COMMON_ANOD      1
typedef struct 
{
    /* data */
    u8 Type         ;
    u8 DataPort     ;
    u8 EnablePORT   ;
    u8 EnablePin    ;

}SSD_Type;



u8 SSD_voidSendNumber (SSD_Type Copy_structConfig, Copy_u8Number);
void SSD_voidEnable   (SSD_Type Copy_structConfig);
void SSD_voidDisable  (SSD_Type Copy_structConfig);


#endif