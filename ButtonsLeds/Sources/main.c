
/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations hj*/
#define portB GPIOB_PDOR
#define portBIn GPIOB_PDIR//pdir es de los registros de los puertos y se pone que entran
#define readPortB(x) ((GPIOB_PDIR>>(x))&0x00000001)
#define portD GPIOD_PDOR
#define turnRedLedOn 0xFFFBFFFF
#define turnBlueLedOn 0xFFFFFFFD
#define turnGreenLedOn 0xFFF7FFFF
#define turnLedsOff  0xFFFFFFFF
#define oneSec 1600000
//Buttons
#define buttonPressed 0
#define buttonNotPressed 1
#define buttonA readPortB(0)
#define buttonB readPortB(1)
#define buttonC readPortB(4)

void cfgPorts(void);
void Delay(long ms);
void delay (int time);


int main(void)
{
	cfgPorts();
	portB=turnLedsOff;
	portD=turnLedsOff;
	Delay(oneSec);
	int sec=1600000;
	int button=0;
	int counter=0;
	int color=1;
	int validacion=0;
	int val2=0;
	int val3=0;
	int val4=0;
	
	for(;;) {
		
		if(!(portBIn & (0x00000004))&&(buttonB == buttonPressed)&&(buttonA == buttonPressed))//si c, b y a
								{
									portB=turnRedLedOn;
									portB=turnGreenLedOn;
									portD=turnBlueLedOn;
									
									
								}		
		
		
		
		
		if(buttonA == buttonPressed)
		{
			portB=turnRedLedOn;
			Delay(oneSec);
			
		}
		if(buttonA == buttonPressed)
				{
			portB=turnGreenLedOn;
			Delay(oneSec);
						
				}
		if(buttonA == buttonPressed)
				{
			portD=turnBlueLedOn;
			Delay(oneSec);
						
				}
			/*portB=turnGreenLedOn;
			Delay(oneSec);
			portD=turnBlueLedOn;
			Delay(oneSec);*/
		/*else if(buttonA == buttonNotPressed)
		{
			portB=turnLedsOff;
			portD=turnLedsOff;
		}*/
		
		
		
		if(!(portBIn & (0x00000004))&&(buttonB == buttonPressed))//si c y ...
		{
					
		
					portB=turnRedLedOn;
					portB=turnGreenLedOn;
					portD=turnBlueLedOn;
			
		}
		
		
		
		
		if(buttonB==buttonPressed)
				{
					button=2;
					sec=1600000;
				}
		if((buttonA==buttonPressed)&&(buttonB==buttonPressed))
				{
					button=3;
					
				}
		
		
		if(button==2)
				{
					
					portB = turnRedLedOn;
					delay(sec);
					portB= turnLedsOff;
					delay(sec);
				}
		if(button==3)
				{
					do
					{
						delay(25000);
						if(buttonC==buttonPressed)
						{
							validacion=1;
						}
						delay(25000);
						if(buttonC==buttonPressed)
						{
							val2=1;
						}
						delay(25000);
						if(buttonC==buttonPressed)
						{
							val3=1;
						}
						delay(25000);
						if(buttonC==buttonPressed)
						{
							val4=1;
						}
						
						if((validacion==1)&&(val2==1)&&(val3==1)&&(val4==1))
						{
							counter=counter+1;
							validacion=0;
							val2=0;
							val3=0;
							val4=0;
						}
						
						
						
					}	
					while((((buttonA)&&(buttonB))==buttonPressed));
					
					button=0;
					
				}
		
		
		/*if(buttonB == buttonPressed)//parte buena de boton de 3 colores
		{
			sec=1600000;
			portB=turnRedLedOn;
			Delay(sec);
			portB=turnLedsOff;
			Delay(sec);
			
		}*/
		
		if(!(portBIn & (0x00000004)))
		{
			portB=turnRedLedOn;
			Delay(oneSec/2);
			portB=turnLedsOff;
			Delay(oneSec/2);
			sec=sec/2;
			
			portB=turnRedLedOn;
						Delay(oneSec/4);
						portB=turnLedsOff;
						Delay(oneSec/4);
						sec=sec/2;
		}
		
		
		/*if(!(portBIn & (0x00000004)))
				{
					portB=turnRedLedOn;
					Delay(oneSec/2);
					portB=turnLedsOff;
					Delay(oneSec/2);
				}*/
		
		
		
		
		
		portB=turnLedsOff;
		portD=turnLedsOff;
		/*else
		{
			portB=turnLedsOff;
		}
		*/
		/*
		portB = 0xFFFBFFFF; // encender led rojo
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		portB = 0xFFF7FFFF; // encender led verde
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		portD = 0xFFFFFFFD; // encender el azul
		Delay(1800000);
		apagarLeds();
		Delay(1800000);*/
		
	}
	
	return 0;
}


void cfgPorts(void)
{
	// TURN ON CLOCK
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK; // es para el reloj
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;//el or es para sumarle al puerto b el puerto a
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;//sim5 que es el registro 5
	
	// SELECT PORT MODE: SET PINS OF PORTB AS GPIO
	PORTB_PCR0= PORT_PCR_MUX(1);//el que esta en parentesis es el modo que queremos con el que funcione
	PORTB_PCR1= PORT_PCR_MUX(1);//esos 3 son los de los pines hacia el boton
	PORTB_PCR2= PORT_PCR_MUX(1);
	
	
	PORTB_PCR18= PORT_PCR_MUX(1);//esos 3 van hacia el boton del mircro
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	// CONFIGURE PORTB FROM 31 TO 3 AS OUTPUT , 0-2 AS INPUT
	GPIOB_PDDR= 0xFFFFFFF8;//IO porque puede ser input o output
	GPIOD_PDDR= 0xFFFFFFFF;
}

void Delay(long ms)
{
	do
	{
		ms--;
	}
	while(ms!=0);
	
}

void delay (int time)
{
	int i;
	for(i=0;i<time;i++)
	{
		
	}
}
