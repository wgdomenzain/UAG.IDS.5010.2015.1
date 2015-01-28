/*
 * main implementation: use this 'C' sample to create your own application
 * Author: Juan Abraham Porras
 */
#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
//prototype declaration
void cfgPorts(void);
int calculateAverage(int age1, int age2, int age3);
int main(void){
	//Ports configuration
	cfgPorts();
	//GPIOB_PDOR = 0xFFFBFFFF; Red
	//GPIOB_PDOR = 0xFFF7FFFF;GREEN pin 19
	//GPIOB_PDOR = 0xFFF3FFFF;//Yellow
	GPIOD_PDOR = 0xFFFFFFFD;//BLUE
	portB = 0xFFF3FFFF;//RED & GREEN
	for(;;) {	   
	   	
	}
	
	return 0;
}

void cfgPorts(void){
	//turn on clock for portB and portA and portD
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	//x|=0x01 es lo mismo que...
	//x=x|0x01
	//0x02=0000 0010
	//     0000 0001 OR
	//     0000 0011
	//select port mode: set pins of PORTB as GPIO by using ALT01
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1 = PORT_PCR_MUX(1);
	//configure port b as output
	GPIOB_PDDR = 0xFFFFFFFF; //1111 1111 1111 1111...
	GPIOD_PDDR = 0xFFFFFFFF;
}
int calculateAverage(int age1, int age2, int age3){
	int avg = age1 + age2 + age3;
	avg = avg/3;
	return avg;
}
