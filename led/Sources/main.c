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
	//Turn on Led
	//GPIOB_PDOR = 0xFFF3FFFF; //amrillo
	//GPIOB_PDOR = 0xFFF7FFFF; //verde
	//GPIOB_PDOR = 0xFFFBFFFF; //rojo
	
	portB = 0xFFF3FFFF; //amrillo
	portB &= 0xFFF7FFFF; //verde
	GPIOD_PDOR = 0xFFFFFFFD; //Azul
	
	
	for(;;) {	   
	   	
	}
	
	return 0;
}
void cfgPorts(void){
	//Turn on clock for portB
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK; 
	
	//Activate pin mode
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1 = PORT_PCR_MUX(1);
	
	//CONFIGURE PORTS AS OUTPUT
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOD_PDDR = 0xFFFFFFFF;
}
