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
#define FirstLine 0x80
#define SecondLine 0xC0




#define	Set_GPIOB_PDOR(x)	(GPIOB_PDOR |= (1 << (x-1)))

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
void printText(unsigned int Coord, char Text[]);
void centerText( int Row, char Text[]);
void clearDisplay(void);
void person(void);
void person2(void);
void print(int Coord,int character);
void erase (int Coord,int character);
void obstaculo(void);
void meta(void);
/*@description: Initial Port Cfg 
*/
void erase2(void);
			
int main(void)
{
	//Configure ports
	cfgPorts();
	//Initialize LCD
	initLCD();
	char myName[] = {"Juegos"};
	char myName2[] = {"Olimpicos"};
	char myName3[] = {"Medalla de Oro"};
	char myName4[] = {"MEXICO!!!"};
	centerText(FirstLine, myName);
	centerText(SecondLine,myName2);
	delay(2400000);
	clearDisplay();
	// record new Character
	//
	
	obstaculo();
	print(SecondLine+1,0x02);
	print(SecondLine+3,0x02);
	print(SecondLine+5,0x02);
	print(SecondLine+7,0x02);
	print(SecondLine+9,0x02);
	print(SecondLine+11,0x02);
	print(SecondLine+13,0x02);
	meta();
	print(SecondLine+15,0x03);
	
	person();
	print(SecondLine,0x00);
	delay(1400000);
	print(FirstLine+1,0x00);
	//delay(1400000);
    erase(SecondLine,0x01);
	erase2();
	delay(1400000);
	print(SecondLine+2,0x00);
	erase(FirstLine+1,0x01);
	
	delay(1400000);
	print(FirstLine+3,0x00);
	erase(SecondLine+2,0x01);
	
	delay(1400000);
	print(SecondLine+4,0x00);
	erase(FirstLine+3,0x01);
	print(SecondLine,0x00);
	
	delay(1400000);
	print(FirstLine+5,0x00);
	print(FirstLine+1,0x00);
	erase(SecondLine,0x01);
	erase(SecondLine+4,0x01);
	
	delay(1400000);
	print(SecondLine+6,0x00);
	print(SecondLine+2,0x00);
	erase(FirstLine+1,0x01);
	erase(FirstLine+5,0x01);
	
	delay(1400000);
	print(FirstLine+7,0x00);
	print(FirstLine+3,0x00);
	erase(SecondLine+2,0x01);
	erase(SecondLine+6,0x01);
	
	delay(1400000);
	print(SecondLine+8,0x00);
	print(SecondLine+4,0x00);
	erase(FirstLine+3,0x01);
	erase(FirstLine+7,0x01);
	
	delay(1400000);
	print(FirstLine+9,0x00);
	print(FirstLine+5,0x00);
	erase(SecondLine+4,0x01);
	erase(SecondLine+8,0x01);
	
	delay(1400000);
	print(SecondLine+10,0x00);
	print(SecondLine+6,0x00);
	erase(FirstLine+5,0x01);
	erase(FirstLine+9,0x01);

	delay(1400000);
	print(FirstLine+11,0x00);
	print(FirstLine+7,0x00);
	erase(SecondLine+6,0x01);
	erase(SecondLine+10,0x01);
	
	delay(1400000);
	print(SecondLine+12,0x00);
	print(SecondLine+8,0x00);
	erase(FirstLine+7,0x01);
	erase(FirstLine+11,0x01);
	
	delay(1400000);
	print(FirstLine+13,0x00);
	print(FirstLine+9,0x00);
	erase(SecondLine+8,0x01);
	erase(SecondLine+12,0x01);
	
	delay(1400000);
	print(SecondLine+14,0x00);
	print(SecondLine+10,0x00);
	erase(FirstLine+9,0x01);
	erase(FirstLine+13,0x01);
		
	delay(1400000);
	print(SecondLine+15,0x00);
	print(FirstLine+11,0x00);
	erase(SecondLine+10,0x01);
	erase(SecondLine+14,0x01);
	
	delay(1400000);
	print(SecondLine+12,0x00);
	erase(FirstLine+11,0x01);
	erase(SecondLine+15,0x01);
	print(SecondLine+15,0x03);
	
	delay(1400000);
	print(FirstLine+13,0x00);
	erase(SecondLine+12,0x01);
	
	delay(1400000);
	print(SecondLine+14,0x00);
	erase(FirstLine+13,0x01);
	
	delay(1400000);
	print(SecondLine+15,0x00);
	erase(SecondLine+14,0x01);
	
	delay(1400000);
	erase(SecondLine+15,0x01);
	print(SecondLine+15,0x03);
	
	delay(1900000);
	erase(SecondLine+1,0x01);
	erase(SecondLine+15,0x01);
	erase(SecondLine+13,0x01);
	centerText(FirstLine, myName3);
	centerText(SecondLine,myName4);
	

	for(;;)
	{
 
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
	
	
	//Initialize PortB
	GPIOB_PDOR = 0x00;
	
	//Initialize PortC
	GPIOC_PDOR = 0X00;

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

void printText(unsigned int Coord, char Text[])
{
	//Set position to print character
	sendCode(nIns, Coord);
	// print Data
		int i;
		for(i=0; Text[i]!=0l;i++)
		{
			sendCode(nData, Text[i]);
		}
}

void centerText( int Row, char Text[])
{
	int lon=0;
	while(Text[lon]!=0l)
	{
		lon++;
	}
	lon=16-lon;
	int center = lon/2;
	int coord=Row+center;
	printText(coord,Text);
	
}

void person(void)
{
	sendCode(nIns,0x40);
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


void print(int Coord,int character)
{
	sendCode(nIns,Coord);
	sendCode(nData,character);
}
void clearDisplay(void)
{
	sendCode(nIns,0x01);
}
void erase (int Coord,int character){
	sendCode(nIns,Coord);
	sendCode(nData,character);
}
void erase2(void){
	
		sendCode(nIns,0x48);
		sendCode(nData,0x00);
		sendCode(nIns,0x49);
		sendCode(nData,0x00);
		sendCode(nIns,0x4A);
		sendCode(nData,0x00);
		sendCode(nIns,0x4B);
		sendCode(nData,0x00);
		sendCode(nIns,0x4C);
		sendCode(nData,0x00);
		sendCode(nIns,0x4D);
		sendCode(nData,0x00);
		sendCode(nIns,0x4E);
		sendCode(nData,0x00);
		sendCode(nIns,0x4F);
		sendCode(nData,0x00);
}


void obstaculo(void){
		sendCode(nIns,0x50);
		sendCode(nData,0x00);
		sendCode(nIns,0x51);
		sendCode(nData,0x00);
		sendCode(nIns,0x52);
		sendCode(nData,0x1F);
		sendCode(nIns,0x53);
		sendCode(nData,0x1F);
		sendCode(nIns,0x54);
		sendCode(nData,0x1F);
		sendCode(nIns,0x55);
		sendCode(nData,0x1F);
		sendCode(nIns,0x56);
		sendCode(nData,0x1F);
		sendCode(nIns,0x57);
		sendCode(nData,0x1F);
	
}

void meta (void){
		sendCode(nIns,0x58);
		sendCode(nData,0x1F);
		sendCode(nIns,0x59);
		sendCode(nData,0x11);
		sendCode(nIns,0x5A);
		sendCode(nData,0x11);
		sendCode(nIns,0x5B);
		sendCode(nData,0x11);
		sendCode(nIns,0x5C);
		sendCode(nData,0x11);
		sendCode(nIns,0x5D);
		sendCode(nData,0x11);
		sendCode(nIns,0x5E);
		sendCode(nData,0x11);
		sendCode(nIns,0x5F);
		sendCode(nData,0x11);
}

