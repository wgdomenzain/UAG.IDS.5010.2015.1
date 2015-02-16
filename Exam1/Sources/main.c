#include "derivative.h" /* include peripheral declarations */
#define portB 			GPIOB_PDOR
#define portD 			GPIOD_PDOR
#define portBin			GPIOB_PDIR
#define readPortB(x)	((GPIOB_PDIR>>(x))&0x00000001)

#define turnRedLedOn 	0xFFFBFFFF
#define turnGreenLedOn 	0xFFF7FFFF
#define turnBlueLedOn 	0xFFFFFFFD
#define turnLedsOff 	0xFFFFFFFF
#define n1sec			1600000
#define n2sec			n1sec*2
#define nhalfsec		n1sec/2

//Buttons
#define buttonPressed 	0
#define buttonNotPressed 1
#define buttonA readPortB(0)
#define buttonB readPortB(1)
#define buttonC readPortB(2)

void delay (long time);
void configPorts(void);
int main(void)
{
	//Ports configuration
	configPorts();
	portB= turnLedsOff;
	portD= turnLedsOff;
	int s=1600000;
	int button=0;
	int button1=0;
	int button2=0;
	int count=0;
	int bAB=0;
	int bBC=0;
	int bABC=0;
	int counterS=0;
	int countC=0;

	
	for(;;)
	{	  
		
		if(buttonA==buttonPressed)
		{	
			button=1;	
		}
		
		if(buttonB==buttonPressed)
		{
			button1=1;
			s=1600000;
		}
		
		if(buttonC==buttonPressed)
		{
			s=s/4;
		}

		if(button==1)
		{ 
			if(countC==0)
						{
				 	 	 portD= turnLedsOff;
				 	 	portB= turnLedsOff;
						portB=turnRedLedOn;
						delay(s);
						countC++;
						}
						else if(countC==1)
							{
							portB=turnGreenLedOn;
							delay(s);
							countC++;
							}
						else if(countC==2)
								{
								portB=turnLedsOff;
								portD=turnBlueLedOn;
								delay(n1sec);
								countC=0;
								}
					button=0;
					
		}
		
	
		
			/*delay(n1sec);
		    portB= turnLedsOff;
			delay(n1sec);
			portB = turnGreenLedOn;
			delay(n1sec);
			portB= turnLedsOff;
			delay(n1sec);
			portD = turnBlueLedOn;	
			delay(n1sec);
			portD= turnLedsOff;
			delay(n1sec);
			*/

		if(button1==1)
		{
			delay(s);
			portB = turnRedLedOn;
			portD = turnLedsOff;
			delay(s);
			portD= turnLedsOff;
			portB= turnLedsOff;
			delay(s);
		}
		if((buttonB==buttonPressed) && (buttonC==buttonPressed) && (buttonA==buttonPressed))
		{
			bABC=1;
		}
						
		if((buttonA==buttonPressed) && (buttonB==buttonPressed))
		{
				bAB=1;
		}
		
		if(bAB==1)
		{
			if(buttonC==buttonPressed)
			{
			count++;
			}
		}
		
		if((buttonB==buttonPressed) && (buttonC==buttonPressed))
		{
				bBC=1;
		}
		
		if(bBC==1)
		{
			if(count!=0)
		{
			int x=0,y=0,z=0;
			do{
				portB=turnRedLedOn;
				delay(n1sec);
				portB=turnLedsOff;
				delay(n1sec);
				x=x+1;
			}while(x<count);
			do
			{
				portB=turnGreenLedOn;
				delay(n1sec);
				portB=turnLedsOff;		
				delay(n1sec);
				y=y+1;
			}while(y<count);
			do
			{
				portD=turnBlueLedOn;
				delay(n1sec);
				portD=turnLedsOff;
				delay(n1sec);
				z=z+1;
				} while(z<count);
					}
					else
					{
						portB=0xFFF2FFFF;
						portD=turnBlueLedOn;
						delay(n1sec);
					}
					button=0;
					}
			
		
		if(bABC==1)
		{
			while(n1sec<7200000){
			portB=turnRedLedOn;
			portB=turnGreenLedOn;
			portD=turnBlueLedOn;
			}
			
		}

				//portB= turnLedsOff;
				//portD= turnLedsOff;
			
		}

	return 0;
}


void configPorts(void)
{
	//Turn clock on
	//SIM_SCG5 = 0X00000400;
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	PORTB_PCR0 = PORT_PCR_MUX(1);
	PORTB_PCR1 = PORT_PCR_MUX(1);
	PORTB_PCR2 = PORT_PCR_MUX(1);
	PORTB_PCR18 = PORT_PCR_MUX(1);
	PORTB_PCR19 = PORT_PCR_MUX(1);
	
	PORTD_PCR1 = PORT_PCR_MUX(1);
	
	//Configure portB  B0 to B2 as input
	//GPIOB_PDDR = 0xFFFFFFFF; //1111 1111 1111 1111
	
	GPIOB_PDDR = 0xFFFFFFF8;  
	GPIOD_PDDR = 0xFFFFFFFF;

	//SIM_SCG5
}
void delay (long time)
{
	int i;
	for(i=0;i<time;i++)
	{
		
	}
}
