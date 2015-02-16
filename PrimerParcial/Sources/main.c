/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
#define portBIn GPIOB_PDIR
#define readPortB(x) ((GPIOB_PDIR >> (x)) & 0x0000001) 
#define portD GPIOD_PDOR  //Azul
#define turnRedLedOn 0xFFFBFFFF
#define turnBlueLedOn 0xFFFFFFFD //0x10010100 
#define turnGreenLedOn 0xFFF7FFFF //NARANJA 0x00000111
#define turnLedsOff  0xFFFFFFFF
#define oneSec 1600000
//Buttons
#define buttonPressed 0
#define ButtonNoPressed 1
#define buttonA readPortB(0)
#define buttonB readPortB(1)
#define buttonC readPortB(2)

void cfgPorts(void);
void Delay(int ms);



int main(void)
{
	cfgPorts();
		portB=turnLedsOff;
		portD=turnLedsOff;
		Delay(oneSec);
	
	for(;;) {
		
		if(buttonA==buttonPressed)
				{
					portB=turnRedLedOn;
					
					if(buttonA==buttonPressed){
						portB=turnLedsOff;
						portB=turnGreenLedOn;
					}
				}/*
				if(buttonB ==buttonPressed)
				{
					portB=turnGreenLedOn;
				}
				if(buttonC == buttonPressed)
				{
					portD=turnBlueLedOn;
				}*/
				portB=turnLedsOff;
				portD=turnLedsOff;
				
		if(buttonB==buttonPressed)
		{
			portB = turnRedLedOn;
			Delay(oneSec);
		    portB= turnLedsOff;
			Delay(oneSec);
			portB = turnRedLedOn;
		    Delay(oneSec);
		}
	}
	
	return 0;
}
void cfgPorts(void)
{
	// TURN ON CLOCK
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// SELECT PORT MODE: SET PINS OF PORTB AS GPIO
	PORTB_PCR0= PORT_PCR_MUX(1);
	PORTB_PCR1= PORT_PCR_MUX(1);
	PORTB_PCR2= PORT_PCR_MUX(1);
		
	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	// CONFIGURE PORTB FROM 31 TO 3 AS OUTPUT , 0-2 AS INPUT
	GPIOB_PDDR= 0xFFFFFFF8;
	GPIOD_PDDR= 0xFFFFFFFF;
}

void Delay(int ms)
{
	do
	{
		ms--;
	}
	while(ms!=0);
	
}


