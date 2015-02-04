/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#define portB 			GPIOB_PDOR
#define portD 			GPIOD_PDOR
#define TurnRedLedOn 	0xFFFBFFFF
#define TurnGreenLedOn 	0xFFF7FFFF
#define TurnBlueLedOn 	0xFFFFFFFD
#define TurnLedsOff 	0xFFFFFFFF
//time constant
#define n1sec			1600000
#define n2sec			n1sec*2
#define nhalfsec		n1sec/2
void configPorts(void);
int main(void)
{
	//Ports configuration
	configPorts();
	portB= TurnLedsOff;
	portD= TurnLedsOff;
	
	for(;;)
	{	  
		if(!(GPIOB_PDIR & (0x00000001)))
		{
			portB = TurnRedLedOn;		
		}
		if(!(GPIOB_PDIR & (0x00000002)))
		{
			portB = TurnGreenLedOn;		
		}
		if(!(GPIOB_PDIR & (0x00000004)))
		{
			portD = TurnBlueLedOn;		
		}
		portB= TurnLedsOff;
		portD= TurnLedsOff;
			
	}
	
	return 0;
}
void configPorts(void)
{
	//Turn clock on
	//SIM_SCG5 = 0X00000400;
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	PORTB_PCR0 = PORT_PCR_MUX(1);
	PORTB_PCR1 = PORT_PCR_MUX(1);
	PORTB_PCR2 = PORT_PCR_MUX(1);
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	
	PORTD_PCR1 = PORT_PCR_MUX(1);
	
	//Configure portB  B0 to B2 as input
	//GPIOB_PDDR = 0xFFFFFFFF; //1111 1111 1111 1111
	
	GPIOB_PDDR = 0xFFFFFFF8;  
	GPIOD_PDDR = 0xFFFFFFFF;

	//SIM_SCG5
}
void delay (long time)
{
	int i;
	for(i=0;i<time;i++)
	{
		
	}
}
