/*
 * main implementation: use this 'C' sample to create your own application
 *
 */



#include "derivative.h" 
#include "stdio.h"/* include peripheral declarations */

void cfgPorts(void);
void parpadeo(void);

int main(void)
{
	cfgPorts();
	//para encender el led Rojo: 
	//Limpiar Puertos
	//GPIOD_PDOR = 0xFFFFFFFF;
	//GPIOB_PDOR = 0xFFFFFFFF;
	//
	
	//GPIOB_PDOR = 0xFFFBFFFF; //Rojo
	//GPIOB_PDOR = 0xFFF7FFFF; //Verde
	//GPIOB_PDOR = 0xFFF3FFFF; // Rojo+Verde (Amarillo)
	//GPIOB_PDOR = 0xFFFFFFFF; // Limpia todos los colores del puerto B
	//GPIOD_PDOR = 0xFFFFFFFD; // Azul
	//GPIOD_PDOR = 0x00000000;
	
	
	
	for(;;) 
	{	
		//limpia puertos
		GPIOD_PDOR = 0xFFFFFFFF;
		GPIOB_PDOR = 0xFFFFFFFF;
		//
		GPIOD_PDOR = 0xFFFFFFFD; // Azul
		parpadeo();
		GPIOD_PDOR = 0xFFFFFFFF;
		GPIOB_PDOR = 0xFFFFFFFF;
		parpadeo();
		GPIOB_PDOR = 0xFFFBFFFF; //Rojo
		parpadeo();
		GPIOD_PDOR = 0xFFFFFFFF;
		GPIOB_PDOR = 0xFFFFFFFF;
		parpadeo();
		GPIOB_PDOR = 0xFFF7FFFF; //Verde
		parpadeo();
		GPIOD_PDOR = 0xFFFFFFFF;
		GPIOB_PDOR = 0xFFFFFFFF;
		parpadeo();
		
	}
	
	return 0;
}
void cfgPorts(void)
{
	// enciende clock del puerto B
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;  //0x00000400;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK;
	
	
	//activa el modo del pin 
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1  = PORT_PCR_MUX(1);
	
	//CONFIGURE PORT B AS OUTPUT
	GPIOB_PDDR = 0xFFFFFFFF; // 0x00040000; //0xFFFBFFFF;
	// PORT D AS OUTPUT
	GPIOD_PDDR = 0xFFFFFFFF;
}

void parpadeo()
{
	int seg;
	for(seg=0;seg<1500000;seg++)
	{
		
	}
}
