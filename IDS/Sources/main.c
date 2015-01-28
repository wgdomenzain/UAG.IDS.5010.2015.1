/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR

void cfgPorts(void);

int main(void)
{
	cfgPorts();
	
	//GPIOB_PDOR = 0xFFFBFFFF; //PRENDE ROJO
	//GPIOB_PDOR = 0xFFF7FFFF; //PRENDE VERDE
	//GPIOB_PDOR = 0xFFF3FFFF; //PRENDE Amarillo
	portB = 0x00000000;
	portB = 0xFFFFFFFD;		
	
	for(;;) {	  
	   	
	}
	
	return 0;
}
void cfgPorts(void){
	
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK; 
	
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1 = PORT_PCR_MUX(1);
	
	//CONFIGURE PORT: B AS OUTPUT
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOD_PDDR = 0xFFFFFFFF;
	
}
