/*
 * Marco Antonio Angel Pérez
 * 
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

//prototype declaration
void cfgPorts(void);

int main(void)
{
	//port configuration
	cfgPorts();
	//TURN ON LED RED
	//GPIOB_PDOR = 0xFFF3FFFF;
	//TURN ON LED GREEN
	//GPIOB_PDOR = 0xFFF3FFFF;
	//TURN ON LED BLUE
	GPIOD_PDOR = 0xFFFFFFFD;
		
	for(;;) 
	{	   
	
	}
	
	return 0;
}

void cfgPorts(void)
{
	//URN ON CLOCK FOR PORTb AND pORTB
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	//Activate pin mode
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1 = PORT_PCR_MUX(1);
	
	//Configure PORT B
	GPIOA_PDDR = 0xFFFFFFFF;
	GPIOB_PDDR = 0xFFFFFFFF; 
	GPIOD_PDDR = 0xFFFFFFFF; 
}	




