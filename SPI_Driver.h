/*
 * SPI_Driver.h
 *
 * Created: 5/16/2019 11:02:31 AM
 *  Author: Ahmed Kareem
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <avr/io.h>

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
void SPI_Send_Byte(const char Sensor_Select);
void SPI_Recive_Byte(const char Sensor_reading);

#endif /* SPI_DRIVER_H_ */