#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_COMMON_CATHODE 0
#define SSD_COMMON_ANOD    1
typedef struct 
{
    /* data */
    u8 Type         ;
    u8 Data_Port    ;
    u8 Enable_Port  ;
    u8 Enable_Pin   ;
}SSD_Type;


void SSD_voidInit(SSD_Type Copy_structSSD_Config);
void SSD_voidSendNumber(SSD_Type Copy_structSSD_Config,u8 Copy_u8Number);
void SSD_voidEnable    (SSD_Type Copy_structSSD_Config);
void SSD_voidDisable   (SSD_Type Copy_structSSD_Config);


#endif