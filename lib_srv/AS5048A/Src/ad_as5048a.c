

#include "../Inc/ad_as5048a.h"

//附加偶校验
#define READ_ANGLE            0xffff
#define READ_AGC              0x7ffd
#define READ_MAG              0x7ffe
#define READ_CLAER            0x4001
#define READ_NOP              0xc000

uint16_t AS5048A_Read(uint16_t TxData)
{
    static uint16_t RxData;

    AD_GPIO_Write(GPIOA, GPIO_PIN_4, GPIO_RESET);
    AD_SPI1_WriteRead((uint8_t *)&TxData,(uint8_t *)&RxData);
    AD_GPIO_Write(GPIOA, GPIO_PIN_4, GPIO_SET);

    return RxData;
}

float AS5048A_Get_Angle()
{
    return (((float)(AS5048A_Read(READ_ANGLE) & 0x3fff)* 360.0)/16384.0);
}
