/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#define portB 			GPIOB_PDOR
#define portD 			GPIOD_PDOR
#define turnRedLedOn 	0xFFFBFFFF
#define turnGreenLedOn 	0xFFF7FFFF
#define turnBlueLedOn 	0xFFFFFFFD
#define turnLedsOff 	0xFFFFFFFF
//time constants
#define n1Sec			1600000
#define n2Sec			n1Sec*2
#define nhalfSec		n1Sec/2

void cfgPorts(void);
void delay(long ms);
void turnoff(void);

int main(void)
{
	
	cfgPorts();
	portB = turnLedsOff;
	PortD = turnLedsOff;
	
	for(;;) {
		/*
		portB = turnOnRedLedOn;
		delay(n1Sec);
		portB = turnLedsOff;
		delay(n1Sec);
		portB = turnGreenLedOn; 
		delay(n1Sec);
		portB= turnLedsOff;
		delay(n1Sec);
		portD = turnBlueLedOn; 
		delay(n1Sec);
		portB = turnLedsOff;
		delay(n1Sec);*/
		
		if (PortB == 0xFFFFFFFE) 
			PortB = turnRedLedOn;
		else
			 PortB = turnLedsOff;
			
	}
	
	return 0;
}

void cfgPorts(void){
	
	SIM_SCGC5 	= SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK;
	
	//Activate pin mode
	PORTB_PCR0 	= PORT_PCR_MUX(1);
	PORTB_PCR1 	= PORT_PCR_MUX(1);
	PORTB_PCR2 	= PORT_PCR_MUX(1);
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1  = PORT_PCR_MUX(1);
	
	//Configure PortB from 31 to 3 as output in b0 to b2 as input
	GPIOB_PDDR = 0xFFFFFFF8;
	GPIOD_PDDR = 0xFFFFFFFF;
}

void delay(long ms) {
	
	do {
		
		ms = ms--;
	} while (ms != 0);
}

