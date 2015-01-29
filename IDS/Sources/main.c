/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */

void cfgPorts(void);
void Delay(long ms);
void apagarLeds(void);
int main(void)
{
	cfgPorts();
	apagarLeds();
	
	for(;;) {	   
		GPIOB_PDOR = 0xFFFBFFFF; 
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		GPIOB_PDOR = 0xFFF7FFFF; 
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		GPIOD_PDOR = 0xFFFFFFFD; 
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		
	}
	
	return 0;
}

void apagarLeds(void)
{
	GPIOB_PDOR = 0xFFFFFFFF; 
	GPIOD_PDOR = 0xFFFFFFFF; 
}
void cfgPorts(void)
{
	
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
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
