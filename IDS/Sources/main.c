/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR

void cfgPorts(void);
void delay(void);
void limpiar(void);
int main(void)
{
	cfgPorts();
	//ROJO
	//GPIOB_PDOR = 0xFFFBFFFF; //PRENDE ROJO
	//GPIOD_PDOR = 0xFFFFFFFF;
	//ROJO
	//VERDE
	GPIOD_PDOR = 0xFFFFFFFF;
	GPIOB_PDOR = 0xFFF7FFFF;
	delay();
	GPIOB_PDOR = 0xFFFFFFFF;
	GPIOD_PDOR = 0xFFFFFFFF;
	//VERDE
	
	
	
	
	//Azul
	//GPIOB_PDOR = 0xFFFFFFFFFF;
	//GPIOD_PDOR = 0xFFFFFFFD;
	//Azul
	for(;;) {	
		//Limpia
		GPIOB_PDOR = 0xFFFFFFFF;
		GPIOD_PDOR = 0xFFFFFFFF;
		//ROJO
		GPIOB_PDOR = 0xFFFBFFFF;
		GPIOD_PDOR = 0xFFFFFFFF;
		delay();
		limpiar();
		delay();
		
		//VERDE
		GPIOD_PDOR = 0xFFFFFFFF;
		GPIOB_PDOR = 0xFFF7FFFF;
		delay();
		limpiar();
		delay();
		//AZUL
		GPIOB_PDOR = 0xFFFFFFFF;
		GPIOD_PDOR = 0xFFFFFFFD;
		delay();
		limpiar();
		delay();
	   	
	}
	
	return 0;
}
void delay(void){
	int i;
	for(i = 0; i<1600000;i++){
		
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
