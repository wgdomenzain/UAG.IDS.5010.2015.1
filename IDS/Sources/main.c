/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR

//prototype declaration 
void cfgPorts(void);

int main(void)
{
	//Ports Configuration
	cfgPorts();
	//Turn on Led
	//GPIOB_PDOR = 0xFFFBFFFF; Red
	portB = 0xFFFBFFFF;
	GPIOB_PDOR &= 0xFFF7FFFF;
	GPIOD_PDOR = 0xFFFFFFFD; 
	
	
	for(;;) {	   
	   	
	}
	
	return 0;
}

void cfgPorts(void){
	//Turn on clock for portB
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;  // 0x00000400;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK; 

	
	//Activate pin mode
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1  = PORT_PCR_MUX(1);
	
	//Configure portB as output	
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOB_PDDR = 0xFFFFFFFF;  //0x00040000	
	GPIOD_PDDR = 0xFFFFFFFF;
}
