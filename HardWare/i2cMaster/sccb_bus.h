
#ifndef _SCCB_BUS_H_
#define _SCCB_BUS_H_


#include "stm32f10x.h"
#include "sys.h"

#define SENSOR_ADDR 0xA0

#define I2C_TIM 5

#define SCCB_SIC_H()      PBout(10) =1	 	//SCL H
#define SCCB_SIC_L()      PBout(10) = 0	 	//SCL H
#define SCCB_SID_H()      PBout(11) = 1   //SDA	H
#define SCCB_SID_L()      PBout(11) = 0  //SDA	H 


#define SCCB_DATA_IN     {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=0X00008000;}
#define SCCB_DATA_OUT    {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=0X00003000;}
#define SCCB_SID_STATE	  PBin(11) 

void sccb_bus_init(void);
void sccb_bus_start(void);
void sccb_bus_stop(void);
void sccb_bus_send_noack(void);
void sccb_bus_send_ack(void);
uint8_t sccb_bus_write_byte(uint8_t data);
uint8_t sccb_bus_read_byte(void);
uint8_t wrSensorReg8_8(int regID, int regDat);
uint8_t rdSensorReg8_8(uint8_t regID, uint8_t* regDat);
uint8_t wrSensorReg16_8(int regID, int regDat);
uint8_t rdSensorReg16_8(uint16_t regID, uint8_t* regDat);
uint8_t rdSensorReg16_16(uint16_t regID, uint16_t* regDat);

#endif /* _SCCB_BUS_H_ */

/******************* (C) COPYRIGHT 2015 WangBao *****END OF FILE****/
