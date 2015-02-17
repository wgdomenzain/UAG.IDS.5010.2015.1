/*
@author: 		Walter Gonzalez Domenzain
@description: 	8020 Group
@functions:		None
@environment: 	KL25Z
@date: 			22/01/2014
@comments:		
@version:		1.0 - Initial
*/

#include "derivative.h" /* include peripheral declarations */


#define GPIO_PIN_MASK 0x1Fu
#define GPIO_PIN(x) (((1)<<(x & GPIO_PIN_MASK)))

#define	nBit0	0x01	//'00000001'
#define	nBit1	0x02	//'00000010'
#define	nBit2	0x04	//'00000100'
#define	nBit3	0x08	//'00001000'
#define	nBit4	0x10	//'00010000'
#define	nBit5	0x20	//'00100000'
#define	nBit6	0x40	//'01000000'
#define	nBit7	0x80	//'10000000'

//Time definitions
#define nt15_msec	10000
#define nt40_usec	3500

//LCD Control
#define nIns	0
#define nData	1

#define PortLCD    	GPIOC_PDOR
//Enable connected to portb_01
#define Enable_1	GPIOB_PDOR |= 0x01
#define Enable_0	GPIOB_PDOR &= 0xFE
#define RS_1   		GPIOB_PDOR |= 0x02
#define RS_0   		GPIOB_PDOR &= 0xFD
#define	Set_GPIOB_PDOR(x)	(GPIOB_PDOR |= (1 << (x-1)))
#define upperRow	0x80
#define lowerRow	0xC0

int int_Temp;

//Cursor Blink off initialization
const unsigned char InitializeLCD[5] = {0x38, 0x38, 0x38, 0x0C, 0x01};
//--------------------------------------------------------------
//Declare Prototypes
/* Functions */
void cfgPorts(void);
void initLCD(void);
void delay(long time);
void sendCode(int Code, int Data);
void printText(unsigned int Coord, char* Array);
void centerText(int Row, char Text[]);
void createPuppet();
/*@description: Initial Port Cfg 
*/
			
int main(void)
{
	//Configure ports
	cfgPorts();
	//Initialize LCD
	initLCD();
	//Set position to print character
	//sendCode(nIns, 0x80);
	//Print character
	//char myName[] = {"Donaldo"};
	//centerText(0x80, myName);
	//sendCode(nIns, 0x80);
	
	createPuppet();
	sendCode(nIns,0x80);
	sendCode(nData,0x00);

	for(;;)
	{/* The logic for the buttons works if a pull-down 
		resistor is used */
		/*
		if ((GPIOC_PDIR && 0x0F) == 0x00)
		{// No button is pressed
			//do noting
		}
		else if ((GPIOC_PDIR && 0x0F) == 0x01)
		{// Button 1 has been pressed
			sendCode(nData, '1');
		}
		else if ((GPIOC_PDIR && 0x0F) == 0x02)
		{// Button 2 has been pressed
			sendCode(nData, '2');
		}
		else if ((GPIOC_PDIR && 0x0F) == 0x04) 
		{// Button 3 has been pressed
			sendCode(nData, '3');
		}
		else if ((GPIOC_PDIR && 0x0F) == 0x08) 
		{// Button 4 has been pressed
			sendCode(nData, '4');	
		}
		else if ((GPIOC_PDIR && 0x0F) == 0x03) 
		{// Buttons 1&2 have been pressed
			
		}
		else if ((GPIOC_PDIR && 0x0F) == 0x07) 
		{// Buttons 1&2&3 have been pressed
			
		}
		else if ((GPIOC_PDIR && 0x0F) == 0x0F) 
		{// Buttons 1&2&3&4 have been pressed
			
		}*/
 
	}
	
	return 0;
}

void cfgPorts(void)
{
	//Turn on clock for portb
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;	
	//Turn on clock for portd
	//SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;	
	////Turn on clock for portc
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	
	/* Set pins of PORTB as GPIO */
	PORTC_PCR0 = PORT_PCR_MUX(1);
	PORTC_PCR1 = PORT_PCR_MUX(1);
	PORTC_PCR2 = PORT_PCR_MUX(1);
	PORTC_PCR3 = PORT_PCR_MUX(1);
	PORTC_PCR4 = PORT_PCR_MUX(1);
	PORTC_PCR5 = PORT_PCR_MUX(1);
	PORTC_PCR6 = PORT_PCR_MUX(1);
	PORTC_PCR7 = PORT_PCR_MUX(1);
	
	/* Set pins of PORTC as GPIO */
	PORTB_PCR0= PORT_PCR_MUX(1);
	PORTB_PCR1= PORT_PCR_MUX(1);
	
	/* Set pins of PORTD as GPIO */
	/*PORTD_PCR0= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1);
	PORTD_PCR2=(0|PORT_PCR_MUX(1));
	PORTD_PCR3=(0|PORT_PCR_MUX(1));
	PORTD_PCR4=(0|PORT_PCR_MUX(1));
	PORTD_PCR5=(0|PORT_PCR_MUX(1));
	PORTD_PCR6=(0|PORT_PCR_MUX(1));
	PORTD_PCR7=(0|PORT_PCR_MUX(1));*/
	
	//Initialize PortB
	GPIOB_PDOR = 0x00;
	
	//Initialize PortC
	GPIOC_PDOR = 0x00;

	//Configure PortB as outputs
	GPIOB_PDDR = 0xFF;
	
	//Configure PortD as outputs
	//GPIOD_PDDR = 0xFF;
	
	//Configure PortC as outputs
	GPIOC_PDDR = 0xFF;
}

void initLCD(void)
{
	int i;
	delay(nt15_msec);
	
	/* Send initialization instructions */
	/* Loop for sending each character from the array */
	for(i=0;i<5;i++)
	{										
		sendCode(nIns, InitializeLCD[i]);	/* send initialization instructions */
	}
	
}

void sendCode(int Code, int Data)
{
	//Assign a value to pin RS
	/*HINT: When RS is 1, then the LCD receives a data
	when RS is 0, then the LCD receives an instruction */
	// Initialize RS and Enable with 0
	RS_0;
	Enable_0;
	//Assign the value we want to send to the LCD
	PortLCD = Data;	
	
	//We make the algorithm to establish if its an instruction we start with 0 on RS value, otherwise if its a data command we start with RS as 1;
	if (Code == nIns)
	{
		Enable_1;
		delay(nt40_usec);
		Enable_0;
		RS_0;
	}		
	else if(Code == nData)
	{
		RS_1;
		Enable_1;
		delay(nt15_msec);
		Enable_0;
		RS_0;
	}
}
void delay(long time)
{
	while (time > 0)
	{
		time--;
	}
}
void printText(unsigned int Coord, char* Array){
	sendCode(nIns, Coord);
	sendCode(nIns, Coord);
	int x, length;
	for(x = 0; Array[x]!=0l; x++){
		length=x;
		sendCode(nData, Array[x]);
	}
}
void centerText(int Row, char Text[]){
	int lon=0;
	while(Text[lon]!=0l){
		lon++;
	}
	lon=16-lon;
	int center = lon/2;
	int coord = Row+center;
	printText(coord,Text);
}
void createPuppet(){
	sendCode(nIns,0x39);
	sendCode(nData,0x0E);
	sendCode(nIns,0x41);
	sendCode(nData,0x0E);
	sendCode(nIns,0x42);
	sendCode(nData,0x0E);
	sendCode(nIns,0x43);
	sendCode(nData,0x04);
	sendCode(nIns,0x44);
	sendCode(nData,0x1F);
	sendCode(nIns,0x45);
	sendCode(nData,0x04);
	sendCode(nIns,0x46);
	sendCode(nData,0x0A);
	sendCode(nIns,0x47);
	sendCode(nData,0x11);
	
}
