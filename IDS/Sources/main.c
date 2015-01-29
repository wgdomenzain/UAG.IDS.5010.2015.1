/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
void cfgPorts(void);
int main(void)
{
	cfgPorts();
	
	//GPIOB_PDOR = 0xFFFBFFFF;// ASI ACTIVAMOS EL LED POQUE EL LED PRENDE CON 0     ROJO PRENDE
	//GPIOB_PDOR = 0xFFF7FFFF;PRENDE VERDE
	portB = 0xFFFBFFFF;
	GPIOB_PDOR &= 0xFFF7FFFF;
	GPIOD_PDOR = 0xFFFFFFFD;
	for(;;) {	   
	   	
	}
	
	return 0;
}
void cfgPorts(void){
	
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK;
	
	//ACTIVA EL MODO DEL PIN 
	PORTB_PCR18 = PORT_PCR_MUX(1);// 1 es el modulo de la tabla la columna de funcionalidad
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1  = PORT_PCR_MUX(1);// MODO 1
	
	//CONFIGURE PORT B AS OUTPUT buscar capitulo GPIO
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOD_PDDR = 0xFFFFFFFF;
}
