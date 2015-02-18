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
void recPer(void);
void recPer3(void);
void printSavedChar(int Coord,int character);
void clearDisplay(void);
void ats0(void);
void ats1(void);
void ats2(void);
void ats3(void);
void ats4(void);
void ats5(void);
void ball1(void);
void ball2(void);
void ball3(void);
void ball4(void);
void ball5(void);
void ball6(void);
void ball7(void);
void ball8(void);
void ball9(void);
void goal(void);

/*@description: Initial Port Cfg 
*/
			
int main(void)
{
	int i=0;
	int ban=0;
	int goals=0;
	char marcador[]={"ATS 0 - 0 AME"};
	
	//Configure ports
	cfgPorts();
	//Initialize LCD
	initLCD();
	marcador[4]=0x2F;

	//Print characters
	for(;;)
	{
		marcador[4]=marcador[4]+1;
		clearDisplay();
		centerText(FirstLine,marcador);
		goal();
		printSavedChar(SecondLine+15,0x06);
		ball1();
		printSavedChar(SecondLine+6,0x01);
		do
		{
			ban=i%2;
			if(ban==0)
			{
				recPer();
			}
			else
			{
				recPer3();
			}
			printSavedChar(SecondLine+i,0x00);	
			delay(1400000);
			printText(SecondLine+i," ");
			i++;
		}while(i!=6);
		recPer2();
		printSavedChar(SecondLine+5,0x00);
		delay(1400000);
		recPer();
		printSavedChar(SecondLine+5,0x00);
		delay(100000);
		printSavedChar(SecondLine+5,0x00);
		ball2();
		printSavedChar(SecondLine+6,0x01);
		delay(100000);
		ball3();
		printSavedChar(SecondLine+6,0x01);
		delay(100000);
		ball4();
		printSavedChar(SecondLine+6,0x01);
		delay(100000);
		
		i=7;
		do
		{
			printText(SecondLine+(i-1)," ");
			ball5();
			printSavedChar(SecondLine+i,0x01);
			delay(100000);
			ball6();
			printSavedChar(SecondLine+i,0x01);
			delay(100000);
			i++;
		}while(i!=14);
		
		printText(SecondLine+13," ");
		ball7();
		printSavedChar(SecondLine+14,0x01);
		delay(100000);
		ball8();
		printSavedChar(SecondLine+14,0x01);
		delay(100000);
		ball9();
		printSavedChar(SecondLine+14,0x01);
		delay(100000);
		clearDisplay();
		centerText(FirstLine,"Goool!!");
		delay(1400000);
		clearDisplay();
		ats0();
		ats1();
		ats2();
		ats3();
		ats4();
		ats5();
		printSavedChar(FirstLine+6,0x00);
		printSavedChar(FirstLine+7,0x01);
		printSavedChar(FirstLine+8,0x02);
		printSavedChar(SecondLine+6,0x03);
		printSavedChar(SecondLine+7,0x04);
		printSavedChar(SecondLine+8,0x05);
		delay(1700000);
		clearDisplay();
		centerText(FirstLine,"ATLAS");
		delay(1400000);
		clearDisplay();
		printSavedChar(FirstLine+6,0x00);
		printSavedChar(FirstLine+7,0x01);
		printSavedChar(FirstLine+8,0x02);
		printSavedChar(SecondLine+6,0x03);
		printSavedChar(SecondLine+7,0x04);
		printSavedChar(SecondLine+8,0x05);
		delay(1700000);
		clearDisplay();
		centerText(FirstLine,"ATLAS");
		delay(1400000);


		goals++;
		i=0;
		clearDisplay();
		
		if(goals>9)
		{
			goals=0;
			marcador[4]=0x2F;
		}
		
 
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

void recPer(void)
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
void recPer2(void)
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
	sendCode(nData,0x12);
}
void recPer3(void)
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
	sendCode(nData,0x0A);
}

void printSavedChar(int Coord,int character)
{
	sendCode(nIns,Coord);
	sendCode(nData,character);
}

void clearDisplay(void)
{
	sendCode(nIns,0x01);
}

void ats0(void)
{
	sendCode(nIns,0x40);
	sendCode(nData,0x00);
	sendCode(nIns,0x41);
	sendCode(nData,0x00);
	sendCode(nIns,0x42);
	sendCode(nData,0x00);
	sendCode(nIns,0x43);
	sendCode(nData,0x07);
	sendCode(nIns,0x44);
	sendCode(nData,0x0C);
	sendCode(nIns,0x45);
	sendCode(nData,0x08);
	sendCode(nIns,0x46);
	sendCode(nData,0x08);
	sendCode(nIns,0x47);
	sendCode(nData,0x08);
}

void ats1(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x04);
	sendCode(nIns,0x49);
	sendCode(nData,0x0A);
	sendCode(nIns,0x4A);
	sendCode(nData,0x11);
	sendCode(nIns,0x4B);
	sendCode(nData,0x04);
	sendCode(nIns,0x4C);
	sendCode(nData,0x0A);
	sendCode(nIns,0x4D);
	sendCode(nData,0x11);
	sendCode(nIns,0x4E);
	sendCode(nData,0x11);
	sendCode(nIns,0x4F);
	sendCode(nData,0x1F);
}

void ats2(void)
{
	sendCode(nIns,0x50);
	sendCode(nData,0x00);
	sendCode(nIns,0x51);
	sendCode(nData,0x00);
	sendCode(nIns,0x52);
	sendCode(nData,0x00);
	sendCode(nIns,0x53);
	sendCode(nData,0x1C);
	sendCode(nIns,0x54);
	sendCode(nData,0x0E);
	sendCode(nIns,0x55);
	sendCode(nData,0x02);
	sendCode(nIns,0x56);
	sendCode(nData,0x02);
	sendCode(nIns,0x57);
	sendCode(nData,0x02);
}
void ats3(void)
{
	sendCode(nIns,0x58);
	sendCode(nData,0x0C);
	sendCode(nIns,0x59);
	sendCode(nData,0x04);
	sendCode(nIns,0x5A);
	sendCode(nData,0x02);
	sendCode(nIns,0x5B);
	sendCode(nData,0x01);
	sendCode(nIns,0x5C);
	sendCode(nData,0x00);
	sendCode(nIns,0x5D);
	sendCode(nData,0x00);
	sendCode(nIns,0x5E);
	sendCode(nData,0x00);
	sendCode(nIns,0x5F);
	sendCode(nData,0x00);
}

void ats4(void)
{
	sendCode(nIns,0x60);
	sendCode(nData,0x11);
	sendCode(nIns,0x61);
	sendCode(nData,0x11);
	sendCode(nIns,0x62);
	sendCode(nData,0x11);
	sendCode(nIns,0x63);
	sendCode(nData,0x00);
	sendCode(nIns,0x64);
	sendCode(nData,0x00);
	sendCode(nIns,0x65);
	sendCode(nData,0x11);
	sendCode(nIns,0x66);
	sendCode(nData,0x0A);
	sendCode(nIns,0x67);
	sendCode(nData,0x04);
}

void ats5(void)
{
	sendCode(nIns,0x68);
	sendCode(nData,0x06);
	sendCode(nIns,0x69);
	sendCode(nData,0x04);
	sendCode(nIns,0x6A);
	sendCode(nData,0x08);
	sendCode(nIns,0x6B);
	sendCode(nData,0x10);
	sendCode(nIns,0x6C);
	sendCode(nData,0x00);
	sendCode(nIns,0x6D);
	sendCode(nData,0x00);
	sendCode(nIns,0x6E);
	sendCode(nData,0x00);
	sendCode(nIns,0x6F);
	sendCode(nData,0x00);
}

void ball1(void)
{
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
	sendCode(nData,0x18);
	sendCode(nIns,0x4F);
	sendCode(nData,0x18);
}

void ball2(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x00);
	sendCode(nIns,0x49);
	sendCode(nData,0x00);
	sendCode(nIns,0x4A);
	sendCode(nData,0x00);
	sendCode(nIns,0x4B);
	sendCode(nData,0x00);
	sendCode(nIns,0x4C);
	sendCode(nData,0x0C);
	sendCode(nIns,0x4D);
	sendCode(nData,0x0C);
	sendCode(nIns,0x4E);
	sendCode(nData,0x00);
	sendCode(nIns,0x4F);
	sendCode(nData,0x00);
}

void ball3(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x00);
	sendCode(nIns,0x49);
	sendCode(nData,0x00);
	sendCode(nIns,0x4A);
	sendCode(nData,0x06);
	sendCode(nIns,0x4B);
	sendCode(nData,0x06);
	sendCode(nIns,0x4C);
	sendCode(nData,0x00);
	sendCode(nIns,0x4D);
	sendCode(nData,0x00);
	sendCode(nIns,0x4E);
	sendCode(nData,0x00);
	sendCode(nIns,0x4F);
	sendCode(nData,0x00);
}
void ball4(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x03);
	sendCode(nIns,0x49);
	sendCode(nData,0x03);
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
void ball5(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x18);
	sendCode(nIns,0x49);
	sendCode(nData,0x18);
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
void ball6(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x03);
	sendCode(nIns,0x49);
	sendCode(nData,0x03);
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

void ball7(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x18);
	sendCode(nIns,0x49);
	sendCode(nData,0x18);
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

void ball8(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x00);
	sendCode(nIns,0x49);
	sendCode(nData,0x00);
	sendCode(nIns,0x4A);
	sendCode(nData,0x06);
	sendCode(nIns,0x4B);
	sendCode(nData,0x06);
	sendCode(nIns,0x4C);
	sendCode(nData,0x00);
	sendCode(nIns,0x4D);
	sendCode(nData,0x00);
	sendCode(nIns,0x4E);
	sendCode(nData,0x00);
	sendCode(nIns,0x4F);
	sendCode(nData,0x00);
}

void ball9(void)
{
	sendCode(nIns,0x48);
	sendCode(nData,0x00);
	sendCode(nIns,0x49);
	sendCode(nData,0x00);
	sendCode(nIns,0x4A);
	sendCode(nData,0x00);
	sendCode(nIns,0x4B);
	sendCode(nData,0x00);
	sendCode(nIns,0x4C);
	sendCode(nData,0x01);
	sendCode(nIns,0x4D);
	sendCode(nData,0x01);
	sendCode(nIns,0x4E);
	sendCode(nData,0x00);
	sendCode(nIns,0x4F);
	sendCode(nData,0x00);
}


void goal(void)
{
	sendCode(nIns,0x70);
	sendCode(nData,0x00);
	sendCode(nIns,0x71);
	sendCode(nData,0x1F);
	sendCode(nIns,0x72);
	sendCode(nData,0x11);
	sendCode(nIns,0x73);
	sendCode(nData,0x11);
	sendCode(nIns,0x74);
	sendCode(nData,0x11);
	sendCode(nIns,0x75);
	sendCode(nData,0x11);
	sendCode(nIns,0x76);
	sendCode(nData,0x11);
	sendCode(nIns,0x77);
	sendCode(nData,0x11);
}
