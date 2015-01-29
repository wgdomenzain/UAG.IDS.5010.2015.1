/*
 * main implementation: use this 'C' sample to create your own application
 * Author: Juan Abraham Porras
 */
#include "derivative.h" /* include peripheral declarations */
#include "stdio.h"
//prototype declaration
void setClock(void);
void portMode(void);
void output(void);
void cfgPorts(void);
void delay(int time);
void setOutputs(void);
int main(void){
		setClock();
		portMode();
		output();
		GPIOB_PDOR = 0xFFFFFFFF;
		GPIOB_PDOR = 0xFFFFFFFF;
		GPIOD_PDOR = 0xFFFFFFFF;
		//Turn on Led
		//GPIOB_PDOR = 0xFFF3FFFF; //amrillo
		//GPIOB_PDOR = 0xFFF7FFFF; //verde
		//GPIOB_PDOR = 0xFFFBFFFF; //rojo
		for(;;){
			GPIOB_PDOR = 0xFFFBFFFF;//ROJO
			delay(24000);
			GPIOB_PDOR = 0xFFFFFFFF;
			delay(24000);
			GPIOD_PDOR = 0xFFFFFFFD;
			delay(24000);
			GPIOD_PDOR = 0xFFFFFFFF;
			delay(24000);
			//GPIOB_PDOR = 0xFFFFFFFF;
			//GPIOD_PDOR = 0xFFFFFFFD;//AZUL
			//GPIOB_PDOR = 0xFFFFFFFF;
		}
		return 0;
}
void setClock(void){
	//Ports configuration
	//cfgPorts();
	//turn on clock for portB and portD
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
}
void portMode(void){
	//select port mode: set pins of PORTB as GPIO by using ALT01
	PORTB_PCR18 = PORT_PCR_MUX(1);//RED
	PORTB_PCR19 = PORT_PCR_MUX(1);//GREEN
	PORTD_PCR1 = PORT_PCR_MUX(1);//BLUE		
}
void output(void){
	//configure port B and D as output
	GPIOB_PDDR = 0xFFFFFFFF;//0xFFF3FFFF==RED/GREEN DOWN - 0xFFF7FFFF==RED ON - 0xFFFBFFFF==GREEN ON
	GPIOD_PDDR = 0x00000002;
}
void cfgPorts(void){
	//turn on clock for portB and portD
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	//select port mode: set pins of PORTB as GPIO by using ALT01
	PORTB_PCR18 = PORT_PCR_MUX(1);//RED
	PORTB_PCR19 = PORT_PCR_MUX(1);//GREEN
	PORTD_PCR1 = PORT_PCR_MUX(1);//BLUE
	//configure port B and D as output
	GPIOB_PDDR = 0xFFFFFFFF; //1111 1111 1111 1111...
	GPIOD_PDDR = 0xFFFFFFF0;//
}
void delay(int time){
	int t;
	while(time){
		t = 100;
		while(t){
			t--;
		}
		time--;
	}
	return;
}
