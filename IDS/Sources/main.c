/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
//#define portB GPIOB_PDOR// Declara una variable 
void cfgPorts(void);

int main(void)
{
	
	//Port Configuration 
	cfgPorts();
	// Turn on Led
	GPIOB_PDOR = 0xFFFBFFFF; //Rojo
	GPIOB_PDOR = 0xFFF3FFFF; //Verde
	GPIOD_PDOR = 0xFFFFFFFD; //azul
	
	for(;;) 
	{
	   
	}
	
	return 0;
}
void cfgPorts(void)
{
	//Turn on Clock for portB and portC
	
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	//Select Port mode : set Pins of PORTs an GPIo(in and out of general )
	
	PORTB_PCR18  = PORT_PCR_MUX(1);
	PORTB_PCR19  = PORT_PCR_MUX(1);
	PORTD_PCR1   = PORT_PCR_MUX(1); 
	//Configure PortB as Output
	
	GPIOB_PDDR = 0xFFFFFFFF;     // 1111 1111 1111 .... 
	GPIOD_PDDR = 0xFFFFFFFF;
}
