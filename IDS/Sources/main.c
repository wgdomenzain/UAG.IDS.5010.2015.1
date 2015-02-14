#include "derivative.h" /* include peripheral declarations */
#define portB 			GPIOB_PDOR
#define portBIn			GPIOB_PDIR
#define readPortB(x) ((portBIn >>(x)) & 0x00000001)
#define portD 			GPIOD_PDOR
#define turnRedLedOn 	0xFFFBFFFF
#define turnGreenLedOn 	0xFFF7FFFF
#define turnBlueLedOn 	0xFFFFFFFD
#define turnLedsOff 	0xFFFFFFFF
#define botonA			!readPortB(0)
#define botonB			!readPortB(1)
#define botonC			!readPortB(2)

//time constants
#define n1Sec 			1800000
#define n2Sec			n1Sec*2
#define nHalfSec		n1Sec/2

//buttons
#define buttonPressed 		0
#define buttonNotPressed 	1

void cfgPorts(void);
void retardo(long ms);


int main(void)
{
	int x = 0, ban2 = 0, ban3 = 0, counter = 0, counterR, counterG, counterB, y = 3, z = 1, w = 0;
	int banderaCase4 = 0;
	long freq = n1Sec;
	cfgPorts();
	portB = turnLedsOff;
	portD = turnLedsOff;
	
	for(;;) {
		if(botonA && !botonB && !botonC){ //case 1
			portB = turnLedsOff;
			portD = turnLedsOff;
			retardo(n1Sec/4);
			if(x == 0){
				portB = turnRedLedOn;
				x++;
			}else if(x == 1){
				portB = turnGreenLedOn;
				x++;
			}else if(x == 2){
				portD = turnBlueLedOn;
				x = 0;
			}
			ban2 = 0;
		}
		if(!botonA && botonB && !botonC){//case 2
			if(ban2 == 0){
				portB = turnLedsOff;
				portD = turnLedsOff;
				ban2 = 1;
			}
		}
		if(ban2 == 1){
			portB = turnLedsOff;
			portD = turnLedsOff;
			if(ban3 == 0){
				//prende  rojo
				portB = turnRedLedOn;
				retardo(freq);
				ban3 = 1;
			}
			else if(ban3 == 1){
				//tiempo apagado
				portB = turnLedsOff;
				retardo(freq);
				ban3 = 0;
			}
		}
		if(!botonA && !botonB && botonC){ // case 3: aumentar frecuencia de parpadeo
			freq = freq/2;
		}
		if(botonA && botonB && !botonC){// case 4: record mode counter value (A + B) Hold
			banderaCase4++;;
			retardo(n1Sec/5);
			ban2 = 0;
			portB = turnLedsOff;
			portD = turnLedsOff;
		}
		if(botonA && botonB && botonC && banderaCase4>0){
			counter++;
			banderaCase4 = 0;
		}
		if(!botonA && botonB && botonC){// case 5: led blink counter times (B + C) Hold
			ban2 = 0;
			if(counter == 0){
				portB = turnRedLedOn & turnGreenLedOn;
				portD = turnBlueLedOn;
			}else{
				portB = turnLedsOff;
				portD = turnLedsOff;
				counterR = counter;
				counterG = counter;
				counterB = counter;
				while(counterR != 0){
					//prende  rojo
					portB = turnRedLedOn;
					retardo(n1Sec);
					//tiempo apagado
					portB = turnLedsOff;
					retardo(n1Sec);
					counterR--;
				}
				portB = turnLedsOff;
				portD = turnLedsOff;
				while(counterG != 0){
					//prende  verde
					portB = turnGreenLedOn;
					retardo(n1Sec);
					//tiempo apagado
					portB = turnLedsOff;
					retardo(n1Sec);
					counterG--;
				}
				portB = turnLedsOff;
				portD = turnLedsOff;
				while(counterB != 0){
					//prende  azul
					portD = turnBlueLedOn;
					retardo(n1Sec);
					//tiempo apagado
					portD = turnLedsOff;
					retardo(n1Sec);
					counterB--;
				}
			}
			portB = turnLedsOff;
			portD = turnLedsOff;
		}
		if(botonA && botonB && botonC && banderaCase4 == 0){//case 6:
			ban2 = 0;
			
			portB = turnRedLedOn & turnGreenLedOn;
			portD = turnBlueLedOn;
			
			retardo(n1Sec*5);
			w = 1;
			z = 1;
			portB = turnLedsOff;
			portD = turnLedsOff;
		}
		if(botonA && botonB && botonC  && w){//case 7:
			portB = turnLedsOff;
			portD = turnLedsOff;
			while(z != 0){
				while(y != 0){
					//prende  rojo
					portB = turnRedLedOn;
					retardo(n1Sec);
					//tiempo apagado
					portB = turnLedsOff;
					retardo(n1Sec);
					y--;
				}
				portB = turnLedsOff;
				portD = turnLedsOff;
				y = 3;
				while(y != 0){
					//prende  verde
					portB = turnGreenLedOn;
					retardo(n1Sec);
					//tiempo apagado
					portB = turnLedsOff;
					retardo(n1Sec);
					y--;
				}
				y = 3;
				portB = turnLedsOff;
				portD = turnLedsOff;
				while(y != 0){
					//prende  azul
					portD = turnBlueLedOn;
					retardo(n1Sec);
					//tiempo apagado
					portD = turnLedsOff;
					retardo(n1Sec);
					y--;
				} 
				y = 3;
				portB = turnLedsOff;
				portD = turnLedsOff;
				z = 0;
			}
			w = 0;
		}

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
