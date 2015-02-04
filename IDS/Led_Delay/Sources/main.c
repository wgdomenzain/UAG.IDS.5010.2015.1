/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#define portB			 GPIOB_PDOR
#define portD 			 GPIOD_PDOR
#define turnRedLedOn 	 0xFFFBFFFF 
#define turnLedGreenOn	 0xFFF7FFFF
#define turnLedBlueOn	 0xFFFFFFFD
#define turnLedsOff		 0xFFFFFFFF

//Time Constants
#define n1sec 			1600000
#define n2sec			n1sec*2
#define nHalfSec		n1sec/2

void cfgPorts(void);
void Delay(long ms);
void apagarLeds(void);


int main(void)
{
	cfgPorts();
	portB = turnLedsOff;
	portD = turnLedsOff;
	
	for(;;) {	
		portB = turnRedLedOn;
		Delay(1600000);
		portB = turnLedsOff;
		Delay(1600000);
		portB = turnLedGreenOn;
		Delay(1600000);
		portB = turnLedsOff;
		Delay(1600000);
		portD = turnLedBlueOn;
		Delay(1600000);
		portD = turnLedsOff;
		Delay(1600000);
	}
	
	return 0;
}

void apagarLeds(void)
{
	GPIOB_PDOR = 0xFFFFFFFF; //Rojo Verde
	GPIOD_PDOR = 0xFFFFFFFF; //Azul
}

void cfgPorts(void)
{
	//Clock
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	//Pin mode
	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	//Configure port as output
	GPIOB_PDDR= 0xFFFFFFFF;
	GPIOD_PDDR= 0xFFFFFFFF;
}

void Delay(long ms)
{
	do
	{
		ms--;
	}
	while(ms!=0);
	
}
