/*
	Author: Rodrigo Orozco
	Date: 14/01/15
	Description: Initial application
	main implementation: use this 'C' sample to create your own application
 */





#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
#define portD GPIOD_PDOR

int CalculateAverage(int age1, int age2, int age3);
void cfgPorts(void);

int main(void)
{
	
	//port configuration 
	cfgPorts();
	
	// turn on led
  //  GPIOB_PDOR = 0xFFFBFFFF; // ENCIENDE EL LED ROJO
    // GPIOB_PDOR = 0xFFF7FFFF; // ENCIENDE EL LED VERDE
   // GPIOB_PDOR = 0xFFF3FFFF; // enciende led rojo y verde
	
	//GPIOB_PDOR = 0xFFFFFFFF; // apagar los leds del puerto B
	portB = 0xFFFBFFFF;
	portB &= 0xFFF7FFFF;
	portD = 0xFFFFFFFD; // encender el azul
	
	
	for(;;) {	
	}
	
	return 0;
}

int CalculateAverage(int age1, int age2, int age3)
{
	int average;
	average=(age1+age2+age3)/3;
	return average;
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

