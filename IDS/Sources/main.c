/*
 * main implementation: use this 'C' sample to create your own application
 * Author: Juan Abraham Porras
 */
#include "derivative.h" /* include peripheral declarations */
#include "stdio.h"
//PORTs
#define portB		 		GPIOB_PDOR
#define portBinput			GPIOB_PDIR
#define readPortB(x)		((portBinput >> (x)) & 0x00000001)
#define portD				GPIOD_PDOR
#define turnRedLedOn 		0xFFFBFFFF
#define turnGreenLedOn 		0xFFF7FFFF
#define turnBlueLedOn 		0xFFFFFFFD
#define turnLedsOff 		0xFFFFFFFF
//TIME CONSTANTs
#define n1sec				24000
#define n2sec				n1sec*2
#define nHalfSec			n1sec/2
#define nThirdSec			n1sec/3
//BUTTONs
#define buttonPressed		0
#define buttonNotPressed	1
#define buttonA				readPortB(0)
#define buttonB				readPortB(1)
#define buttonC				readPortB(2)
void cfgPorts(void);
void delay(long time);
int main(void){
		cfgPorts();
		portB = turnLedsOff;
		portD = turnLedsOff;
		delay(nThirdSec);
		for(;;){
			if(buttonA == buttonPressed){
				portB = turnRedLedOn;
			}else{
				portB = turnLedsOff;
			}
			if(buttonB == buttonPressed){
				portB = turnGreenLedOn;
			}else{
				portB = turnLedsOff;
			}
			if(buttonC == buttonPressed){
				portD = turnBlueLedOn;
			}else{
				portD = turnLedsOff;
			}
		}
		return 0;
}
void cfgPorts(void){
	//turn on clock for portB and portD
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	//select port mode: set pins of PORTB as GPIO by using ALT01
	PORTB_PCR0 = PORT_PCR_MUX(1);
	PORTB_PCR1 = PORT_PCR_MUX(1);
	PORTB_PCR2 = PORT_PCR_MUX(1);
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1 = PORT_PCR_MUX(1);
	//configure from B3 to B31 as Output and B0 to B2 as input. D as output
	GPIOB_PDDR = 0xFFFFFFF8;
	GPIOD_PDDR = 0x00000002;
}
void delay(long time){
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
