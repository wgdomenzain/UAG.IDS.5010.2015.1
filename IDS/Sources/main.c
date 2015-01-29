/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
//Prototype declaration
void cfgPorts(void);
void delay(long time);
void tl(void);
void abc(void);
int main(void)
{
	
	cfgPorts();
	tl();
	//GPIOB_PDOR = 0xFFFFFFFD;
	//portB = 0xFFF3FFFF; 
	
	//portB = 0xFFFBFFFF;//RED
	//portB = 0xFFF7FFFF;//VERDE
	//GPIOD_PDOR = 0xFFFBFFFD;//AZUL
	for(;;) {
		portB = 0xFFFBFFFF;
		abc();
		portB = 0xFFF7FFFF;
		abc();
		GPIOD_PDOR = 0xFFFFFFFD;
		abc();
		
	}	
	return 0;
}
void cfgPorts(void){
	//SIM_SCGC5 : RELOJ EL micro por default tiene apagado lso puertos.
	//funciones que se hacen en el gpio :memory map
	//por data direction register: le mandamos un 1 o 0
	
	SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK;
	
	//ACTIVATE PIN MODE	
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1 =  PORT_PCR_MUX(1);
	
	//CONFIGURE PORTB AS OUTPUT
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOD_PDDR = 0xFFFFFFFF;
	
}
void delay(long time){
	while(time!=0){
		time--;
	}
		
}

void tl(void){
	
	GPIOB_PDDR = 0xFFFFFFFF;
	GPIOD_PDDR = 0xFFFFFFFF;
}
void abc(void){
	delay(1000000);
	tl();
	delay(1000000);
	
	
}


//rojo pasae 1 segundo y luego green otro segundo y azul y luego otro segundo si n pasar nada

