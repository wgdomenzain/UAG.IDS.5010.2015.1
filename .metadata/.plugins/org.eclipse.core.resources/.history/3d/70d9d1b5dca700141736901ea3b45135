/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
#define portD GPIOD_PDOR

void cfgPorts(void);
void delay(long ms);
void turnoff(void);

int main(void)
{
	cfgPorts();
	turnoff();
	
	for(;;) {	   
		portB = 0xFFFBFFFF;
		delay(2000000);
		turnoff();
		delay(2000000);
		portB = 0xFFF7FFFF; 
		delay(2000000);
		turnoff();
		delay(2000000);
		portD = 0xFFFFFFFD; 
		delay(2000000);
		turnoff();
		delay(2000000);
	}
	
	return 0;
}
void cfgPorts(void){
	
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK;
	
	//Activate pin mode
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1  = PORT_PCR_MUX(1);
	
	//Configure PortB and PortD as output
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOD_PDDR = 0xFFFFFFFF;
}
void delay(long ms) {
	do {
		ms = ms - 1;
	} while (ms != 0);
}
void turnoff(void) {
	portB = 0xFFFFFFFF;
	portD = 0xFFFFFFFF;
}

