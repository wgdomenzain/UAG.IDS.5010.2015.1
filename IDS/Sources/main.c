/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" 
/* include peripheral declarations */

void cfgPorts(void);


int main(void)
{

	cfgPorts();
	
	//PRende ROjo
GPIOB_PDOR = 0xFFFBFFFF;
GPIOB_PDOR &= 0xFFF7FFFF;
GPIOD_PDOR =0xFFFFFFFD;
	
for(;;) {	   
	   	
	
}
	
	
return 0;

}

void cfgPorts(void)
{
	
	
SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	
SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK; 

PORTB_PCR18 = PORT_PCR_MUX(1);
	
PORTB_PCR19 = PORT_PCR_MUX(1);
PORTD_PCR1 = PORT_PCR_MUX(1);	
	
GPIOB_PDDR = 0xFFFFFFFF;
GPIOD_PDDR = 0xFFFFFFFF;
}
