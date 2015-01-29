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
		portB = 0xFFFBFFFF; // encender led rojo
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		portB = 0xFFF7FFFF; // encender led verde
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		portD = 0xFFFFFFFD; // encender el azul
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		
	}
	
	return 0;
}

void apagarLeds(void)
{
	portB = 0xFFFFFFFF; // apagar lods rojo y verde
	portD = 0xFFFFFFFF; // apagar led azul
}

void cfgPorts(void)
{
	// encender el reloj del puerto b y a
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// SELECT PORT MODE: SET PINS OF PORTB AS GPIO
	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	// COnfigure portb as output
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
