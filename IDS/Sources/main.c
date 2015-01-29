/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" 
/* include peripheral declarations */

void cfgPorts(void);

void delay(void);
int main(void)
{

	cfgPorts();
	GPIOB_PDOR = 0xFFFFFFFF;
	GPIOB_PDOR = 0xFFFFFFFF;
	GPIOD_PDOR = 0xFFFFFFFF;
	int inf=0;
	while(inf==0){
		
		
		GPIOB_PDOR = 0xFFFBFFFF;
		delay();
		GPIOB_PDOR = 0xFFFFFFFF;
		delay();
		GPIOB_PDOR = 0xFFF7FFFF;
		delay();
		GPIOB_PDOR = 0xFFFFFFFF;
		delay();
		GPIOD_PDOR = 0xFFFFFFFD;
		delay();
		GPIOD_PDOR = 0xFFFFFFFF;
		delay();
	}
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
GPIOD_PDDR = 0x00000002;
}

void delay(void){
	
	{
	   int c = 1, d = 1;
	 
	   for ( c = 1 ; c <= 1250 ; c++ )
	       for ( d = 1 ; d <= 1250 ; d++ )
	       {}
	 
	  
	}
}


