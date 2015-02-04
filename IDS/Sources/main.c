#include "derivative.h" /* include peripheral declarations */
#define portB 			GPIOB_PDOR
#define portBIn			GPIOB_PDIR
#define portD 			GPIOD_PDOR
#define turnRedLedOn 	0xFFFBFFFF
#define turnGreenLedOn 	0xFFF7FFFF
#define turnBlueLedOn 	0xFFFFFFFD
#define turnLedsOff 	0xFFFFFFFF
//time constants
#define n1Sec 			1800000
#define n2Sec			n1Sec*2
#define nHalfSec		n1Sec/2

void cfgPorts(void);
void retardo(long ms);


int main(void)
{
	cfgPorts();
	portB = turnLedsOff;
	portD = turnLedsOff;
	
	for(;;) {
		if(!(portBIn & 0x1)){
			portB = turnRedLedOn;
		}else if(!(portBIn & 0x2)){
			portB = turnGreenLedOn;
		}else if(!(portBIn & 0x4)){
			portD = turnBlueLedOn;
		}
		portB = turnLedsOff;
		portD = turnLedsOff;
		/*
		//prende  rojo
		portB = turnRedLedOn;
		retardo(n1Sec);
		//tiempo apagado
		portB = turnLedsOff;
		retardo(n1Sec);
		
		//prende verde
		portB = turnGreenLedOn;
		retardo(n1Sec);
		//tiempo apagado
		portB = turnLedsOff;
		retardo(n1Sec);
		
		//prende azul
		portD = turnBlueLedOn;
		retardo(n1Sec);
		//tiempo apagado
		portD = turnLedsOff;
		retardo(n1Sec);
		*/
	}
	
	return 0;
}
void retardo(long ms){
	do
	{
		ms--;
	}
	while(ms!=0);
	
}
void cfgPorts(void)
{
	//Activar Reloj Puerto A, B y D
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// Activar pines como GPIO
	PORTB_PCR0= PORT_PCR_MUX(1); //Activando GPIO 0, 1 y 2
	PORTB_PCR1= PORT_PCR_MUX(1);
	PORTB_PCR2= PORT_PCR_MUX(1);
	
	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	// Configure PORTB from 31 to 3 As Output and B0 to B2 as Input
	GPIOB_PDDR= 0xFFFFFFF8; //1000 = 8
	GPIOD_PDDR= 0xFFFFFFFF;
}
