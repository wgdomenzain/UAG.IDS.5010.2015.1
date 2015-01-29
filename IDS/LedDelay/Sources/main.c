/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
#define portD GPIOD_PDOR

void cfgPorts(void);
void Delay(long ms);
void apagarLeds(void);


int main(void)
{
	cfgPorts();
	apagarLeds();
	
	for(;;) {	
		//Turn on Led
		GPIOB_PDOR = 0xFFFBFFFF; //Red
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		GPIOB_PDOR = 0xFFF7FFFF; //Green
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		GPIOD_PDOR = 0xFFFFFFFD; //Blue
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		
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
