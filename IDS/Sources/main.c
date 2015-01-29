/*
 * Marco Antonio Angel Pérez
 * 
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */


//prototype declaration
void cfgPorts(void);
void delay(void);


int main(void)
{
	cfgPorts();

	//apagar puertos
		
	
		//cerrar el puerto 19 para que no encienda la luz verde
	GPIOD_PDOR = 0xFFFFFFFF;
	
	for(;;) 
	{	   
		//encender led rojo por puerto B18
		GPIOB_PDOR = 0xFFFBFFFF;
					//esperar un segundo 
		delay();
						//apagar led rojo por puerto B18
		GPIOB_PDOR = 0xFFFFFFFF;
					//esperar un segundo 
		delay();
		//encender led verde por puerto B19 previamente apagando el rojo para que no se convierta en magenta
		GPIOB_PDOR = 0xFFF7FFFF;
					//esperar un segundo
		delay();
						//apago el led verde
		GPIOB_PDOR = 0xFFFFFFFF;
					//esperar un segundo
		delay();
		////encender led azul por puerto D13 previamente apagando el rojo para que no se convierta en otro color
		GPIOD_PDOR = 0xFFFFFFFD;
					//esperar un segundo
		delay();
		//apagar led azul
		GPIOD_PDOR = 0xFFFFFFFF;
					//esperar un segundo
		delay();
		
	}
	
	return 0;
}

void cfgPorts(void)
{
	//URN ON CLOCK FOR PORTb AND pORTB
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	//Activate pin mode
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	PORTD_PCR1 = PORT_PCR_MUX(1);
	
	//Configure PORT 
	GPIOA_PDDR = 0xFFFFFFFF;
	GPIOB_PDDR = 0xFFFFFFFF; 
	GPIOD_PDDR = 0xFFFFFFFF; 
}	
void delay(void){
	
	{
	   int c;
	   for (c=1;c<1600000;c++)
	   {
		   
	   }
	   
	 
	  
	}
 }



