
/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */

#define portBIn GPIOB_PDIR
#define portB GPIOB_PDOR
#define portD GPIOD_PDOR
#define turnRedLedOn 0xFFFBFFFF
#define turnBlueLedOn 0xFFFFFFFD
#define turnGreenLedOn 0xFFF7FFFF
#define turnLedsOff  0xFFFFFFFF
#define oneSec 1600000


void cfgPorts(void);
void Delay(long miliseg);
void Max(long miliseg);//no la use

int pausa=1600000;

int main(void)
{
	cfgPorts();
	portB=turnLedsOff;
	portD=turnLedsOff;
	Delay(oneSec);
	int boton=0;
	int pausa=1600000;
	
	
	for(;;) 
	{
		if(!(portBIn & (0x00000001)))
		{
			boton=1;
		}
		if(!(portBIn & (0x00000002)))
			{
				boton=2;
				pausa=1600000;
			}
		if(!(portBIn & (0x00000004)))
			{
				
				pausa=pausa/2;
			}
		
		if(boton==1)
		{
			
				//Delay(oneSec);
				portB=turnGreenLedOn;
				Delay(oneSec);
				portB=turnLedsOff;
									
				portB=turnRedLedOn;
				Delay(oneSec);
				portB=turnLedsOff;
									
				portD=turnBlueLedOn;
				Delay(oneSec);
				portD=turnLedsOff;
											
			
		}
		if(boton==2)
		{
			
				
				/*portB=turnLedsOff;
							portD=turnLedsOff;
				portB=turnGreenLedOn;
							portB=turnRedLedOn;
							portD=turnBlueLedOn;
				
			portD=turnBlueLedOn;
			portB=turnGreenLedOn;
			portB=turnRedLedOn;
			Delay(oneSec);
			portB=turnLedsOff;
			portD=turnLedsOff;
			
			Delay(oneSec);
			portB=turnGreenLedOn;
			portB=turnRedLedOn;
			portD=turnBlueLedOn;
			Delay(oneSec);
			portB=turnLedsOff;
			portD=turnLedsOff;
			*/
				
				
				portB=0xFFF2FFFF;
				portD=turnBlueLedOn;
				Delay(pausa);
				
				portD=turnLedsOff;
				portB=turnLedsOff;
				Delay(pausa);
				
				
				
				
	
			
			
			
		}
		
		portB=turnLedsOff;
		portD=turnLedsOff;
		/*else
		{
			portB=turnLedsOff;
		}
		*/
		/*
		portB = 0xFFFBFFFF; //ROJO
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		portB = 0xFFF7FFFF; //VERDE
		Delay(1800000);
		apagarLeds();
		Delay(1800000);
		portD = 0xFFFFFFFD; //AZUL
		Delay(1800000);
		apagarLeds();
		Delay(1800000);*/
		
	}
	
	return 0;
}


void cfgPorts(void)
{
	// TURN ON CLOCK´S
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// TURN ON PIN MODE
	PORTB_PCR0= PORT_PCR_MUX(1);
	PORTB_PCR1= PORT_PCR_MUX(1);
	PORTB_PCR2= PORT_PCR_MUX(1);
	
	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	// CONFIGURE PORTB FROM 31 TO 3 AS OUTPUT AND 0-2 AS INPUT
	GPIOB_PDDR= 0xFFFFFFF8;
	GPIOD_PDDR= 0xFFFFFFFF;
}

void Delay(long miliseg)
{
	do
	{
		miliseg=miliseg-1;
	}
	while(miliseg!=0);
	
}

/*void Max(long miliseg)
{
	do
	{
		miliseg++;
	}
	while (miliseg!=0);
}*/
