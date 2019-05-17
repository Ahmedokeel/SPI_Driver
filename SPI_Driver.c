/*
 * SPI_Driver.c
 *
 * Created: 5/16/2019 11:02:10 AM
 *  Author: Ahmed Kareem
 */
 
 #include "SPI_Driver.h"


  void SPI_Master_Init(void)
 {
	 
	 /******** Configure SPI Master Pins *********
	 * SS(PB0)   --> Output
	 * SCK(PB1)  --> Output 
	 * MOSI(PB2) --> Output
	 * MISO(PB3) --> Input
	 ********************************************/
	DDRB |= (1<<PB0);
	DDRB |= (1<<PB1);
	DDRB |= (1<<PB2);
	DDRB &=~(1<<PB3);
	
	/* Enable SPI, Master, set clock rate fck/4 */
	SPCR = (1<<SPE)|(1<<MSTR);
 }	
 
 
 void SPI_Slave_Init(void)
 {
	/******** Configure SPI Slave Pins *********
	 * SS(PB0)   --> Input
	 * SCK(PB1)  --> INput 
	 * MOSI(PB2) --> Output
	 * MISO(PB3) --> Input
	 ********************************************/
	DDRB &=~(1<<PB0);
	DDRB &=~(1<<PB1);
	DDRB |= (1<<PB2);
	DDRB &=~(1<<PB3);
	
	/* Enable SPI, Slave */
	SPCR = (1<<SPE); 
 }
 
 /*********************************
 /*	this function responsible for select which sensor to read
 **********************************/
 
 void SPI_Send_Byte(const char Sensor_Select)
 {
	 SPDR = Sensor_Select;              //send data by SPI
	 while((SPSR & (1<<SPIF)) == 0){}    //wait until SPI interrupt flag=1 
 } 
 
 /*********************************
 /*	this function responsible for send sensor reading
 **********************************/
 
 void SPI_Recive_Byte(const char Sensor_reading)
 {
	while((SPSR & (1<<SPIF)) == 0){} //wait until SPI interrupt flag=1
	return SPDR;                     //return the received byte from SPI data register
 }
 
 
 
 
 
