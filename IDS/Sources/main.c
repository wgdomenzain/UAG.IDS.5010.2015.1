
/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
//#define portB GPIOB_PDOR// Para declarar una variable
#define portB GPIOB_PDOR
#define portD GPIOD_PDOR

void cfgPorts(void);
void Delay(long ms);
void TurnOffLeds(void);


int main(void)
{
	//PortConfiguration
	cfgPorts();
	TurnOffLeds();
	
	for(;;) {	   
		portB = 0xFFF7FFFF; //led verde
		Delay(2000000);
		TurnOffLeds();
		Delay(2000000);
		portD = 0xFFFFFFFD; // led azul
		Delay(2000000);
		TurnOffLeds();
		Delay(2000000);
		portB = 0xFFFBFFFF; //led rojo
		Delay(2000000);
		TurnOffLeds();
		Delay(2000000);
		
	}
	
	return 0;
}

void TurnOffLeds(void)
{
	portB = 0xFFFFFFFF; // turn off red&green leds
	portD = 0xFFFFFFFF; // turn off blue led
}

void cfgPorts(void)
{
	//Turn on Clock for portB and portC
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	//Select Port mode : set Pins of PORTs an GPIo(in and out of general purpose)
	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	//Configure PortB as Output
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
