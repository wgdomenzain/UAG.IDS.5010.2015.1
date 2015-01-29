/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#define portB 			GPIOB_PDOR
#define portD 			GPIOD_PDOR
#define turnRedLedOn 	0xFFFBFFFF
#define turnGreenLedOn 	0xFFF7FFFF
#define turnBlueLedOn  	0xFFFFFFFD
#define turnLedsOff 	0xFFFFFFFF
//time constants
#define n1sec			1600000
#define n2sec			n1sec*2
#define	nhalfsec		n1sec/2



void cfgPorts(void);
void delay(long time);
void limpiar(void);
int main(void)
{
	cfgPorts();
	portB = turnLedsOff;
	portD = turnLedsOff;
	
	for(;;) {	
		portB = turnRedLedOn;
		delay(n1sec);
		portB = turnLedsOff;
		delay(n1sec);
		portB = turnGreenLedOn;
		delay(n1sec);
		portB = turnLedsOff;
		delay(n1sec);
		portD = turnBlueLedOn;
		delay(n1sec);
		portD = turnLedsOff;
		delay(n1sec);
	}
	
	return 0;
}
void delay(long time){
	long i;
	for(i = 0; i<time;i++){
		
	}
}
void limpiar(void){
	GPIOB_PDOR = 0xFFFFFFFF;
	GPIOD_PDOR = 0xFFFFFFFF;
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
//GPIOB_PDOR = 0xFFF3FFFF; //PRENDE Amarillo
//portB = 0x00000000;
//portB = 0xFFFFFFFD;	
