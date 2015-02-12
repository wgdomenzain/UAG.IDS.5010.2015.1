/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#define portB GPIOB_PDOR
#define portBIn GPIOB_PDIR
#define readPortB(x) (((portBIn >> (x)))&0x00000001)
#define portD GPIOD_PDOR
#define turnRedLedOn 0xFFFBFFFF
#define turnBlueLedOn 0xFFFFFFFD
#define turnGreenLedOn 0xFFF7FFFF
#define turnLedsOff  0xFFFFFFFF
#define oneSec 1600000

// BUTTONS
#define buttonPressed 0
#define buttonNotPressed 1


void cfgPorts(void);
void Delay(long ms);
int check();


int main(void)
{
	int opc=0;
	int colorCase1=0;
	int delayCase2=oneSec;
	int counter=0;
	int i =0;
	cfgPorts();
	portB=turnLedsOff;
	portD=turnLedsOff;
	
	
	for(;;) {
		
		if(!readPortB(0) && readPortB(1) && readPortB(2))
		{
			opc=1;
			Delay(oneSec/2);
		}
		if(!readPortB(1) && readPortB(0) && readPortB(2))
		{
			opc=2;
			Delay(oneSec/2);
		}
		if(!readPortB(2) && readPortB(0) && readPortB(1))
		{
			opc=3;
			Delay(oneSec/2);
		}
		if(!(readPortB(0)) && !readPortB(1) && readPortB(2))
		{
				opc=4;			
			
		}
		if(!(readPortB(1)) && !readPortB(2) && readPortB(0))
		{	
				opc=5;
				
				Delay(oneSec/2);		
		}
		if(!(readPortB(1)) && !readPortB(2) && !readPortB(0) && opc!=4)
		{
			opc=6;
			Delay(oneSec);
			if(!(readPortB(1)) && !readPortB(2) && !readPortB(0) && opc!=4)
			{
				Delay(oneSec);
				if(!(readPortB(1)) && !readPortB(2) && !readPortB(0) && opc!=4)
				{
					Delay(oneSec);
					if(!(readPortB(1)) && !readPortB(2) && !readPortB(0) && opc!=4)
					{
						Delay(oneSec);
						if(!(readPortB(1)) && !readPortB(2) && !readPortB(0) && opc!=4)
						{
							Delay(oneSec);
							if(!(readPortB(1)) && !readPortB(2) && !readPortB(0) && opc!=4)
							{
								opc=7;
							}
							else
										{
											opc=6;
										}
							
						}
						else
									{
										opc=6;
									}
							
					}
					else
								{
									opc=6;
								}
					
				}
				else
							{
								opc=6;
							}
			}
			else
			{
				opc=6;
			}
		}
		
		
		switch(opc)
		{
			case 1:
				if(colorCase1==2)
				{
					portB=turnLedsOff;
					portD=turnLedsOff;
					portD=turnBlueLedOn;
					colorCase1=0;
					opc=0;
					break;
				}
				if(colorCase1==1)
				{
					portB=turnLedsOff;
					portD=turnLedsOff;
					portB=turnGreenLedOn;
					colorCase1=2;
					opc=0;
					break;
				}
				if(colorCase1==0)
				{
					portB=turnLedsOff;
					portD=turnLedsOff;
					portB=turnRedLedOn;
					colorCase1=1;
					opc=0;
					break;
				}
				
				
				break;
				
			case 2:
				portB=turnLedsOff;
				portD=turnLedsOff;
				
				portB=turnRedLedOn;
				if(check())
				break;
				Delay(delayCase2/2);
				if(check())
				break;
				Delay(delayCase2/2);
				if(check())
				break;
				portB=turnLedsOff;
				if(check())
				break;
				Delay(delayCase2/2);
				if(check())
				break;
				Delay(delayCase2/2);
				break;
				
			case 3:
				delayCase2=delayCase2/2;
				opc=2;
				break;
				
			case 4:
				if(!readPortB(2))
				{
					Delay(oneSec/4);
					counter++;
					
				}
				opc=4;
				break;
				
			case 5:
				if(counter==0)
				{
					portB=turnLedsOff;
					portB=turnLedsOff;
					portD=turnBlueLedOn;
					portB=turnGreenLedOn;
					portB=turnRedLedOn;
					opc=0;
					Delay(oneSec/4);
				}
				else
				{
					portB=turnLedsOff;
					portD=turnLedsOff;
					
					for(i=0;i<counter;i++)
					{
						portB=turnRedLedOn;
						if(check())
										break;
										Delay(oneSec/2);
										if(check())
										break;
										Delay(oneSec/2);
						portB=turnLedsOff;
						if(check())
										break;
										Delay(oneSec/2);
										if(check())
										break;
										Delay(oneSec/2);
					}
					for(i=0;i<counter;i++)
					{
						portB=turnGreenLedOn;
						if(check())
										break;
										Delay(oneSec/2);
										if(check())
										break;
										Delay(oneSec/2);
						portB=turnLedsOff;
						if(check())
										break;
										Delay(oneSec/2);
										if(check())
										break;
										Delay(delayCase2/2);
					}
					for(i=0;i<counter;i++)
					{
						portD=turnBlueLedOn;
						if(check())
										break;
										Delay(oneSec/2);
										if(check())
										break;
										Delay(oneSec/2);
						portD=turnLedsOff;
						if(check())
										break;
										Delay(oneSec/2);
										if(check())
										break;
										Delay(oneSec/2);
					}
				}
				opc=0;
				break;
				
			case 6:
				portB=turnLedsOff;
				portD=turnLedsOff;
				portB=turnGreenLedOn;
				portB=turnRedLedOn;
				portD=turnBlueLedOn;
				opc=0;
				
				break;
				
			case 7:
				portB=turnLedsOff;
				portD=turnLedsOff;
				counter=0;
				opc=0;
				
				for(i=0;i<3;i++)
				{
					portB=turnRedLedOn;
					Delay(oneSec);
					portB=turnLedsOff;
					Delay(oneSec);
				}
				for(i=0;i<3;i++)
				{
					portB=turnGreenLedOn;
					if(check())
															break;
															Delay(oneSec/2);
															if(check())
															break;
															Delay(oneSec/2);
					portB=turnLedsOff;
					if(check())
															break;
															Delay(oneSec/2);
															if(check())
															break;
															Delay(oneSec/2);
				}
				for(i=0;i<3;i++)
				{
					portD=turnBlueLedOn;
					if(check())
															break;
															Delay(oneSec/2);
															if(check())
															break;
															Delay(oneSec/2);
					portD=turnLedsOff;
					if(check())
															break;
															Delay(oneSec/2);
															if(check())
															break;
															Delay(oneSec/2);
				}
				
				break;
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

int check()
{
	if(!(readPortB(1)) || !readPortB(2) || !readPortB(0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Delay(long ms)
{
	do
	{
		ms--;
	}
	while(ms!=0);
	
}
