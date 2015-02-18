/*
@author: 		Alan DeMiguel García
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
#define nt150_msec		nt15_msec*90
#define nt1500_msec		nt15_msec*100
#define nt3_sec			nt1500_msec*3

//LCD Control
#define nIns	0
#define nData	1

#define PortLCD    	GPIOC_PDOR
//Enable connected to portb_01
#define Enable_1	GPIOB_PDOR |= 0x01
#define Enable_0	GPIOB_PDOR &= 0xFE
#define RS_1   		GPIOB_PDOR |= 0x02
#define RS_0   		GPIOB_PDOR &= 0xFD
#define upperRow  0x80
#define lowerRow  0xc0



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
void printText (unsigned int Coord, char* Array);
void centerText (int Row, char Text[]);
void guardar (void);
void tortuga (void);
void mono2 (void);
void tortuga2 (void);
void tortuga3 (void);
void caja (void);
void caja2 (void);
void monoBrincando (void);
void clearScreen(int Coord);
void clearAllDisplay(void);

/*@description: Initial Port Cfg 
*/
			
int main(void)
{
	//Configure ports
	cfgPorts();
	//Initialize LCD
	initLCD();
	//Set position to print character
	//sendCode(nIns, 0x00);
	
	//Print characters
	clearAllDisplay();
	tortuga();
	sendCode(nIns, 0x0C6);
	sendCode (nData,0x01);
	delay(nt1500_msec);
	clearScreen(0x0C6);
				
	//char myName[] = {"Alan Dm"};
	//centerText (0x80, myName);
	for(;;)
	{
		caja();
		sendCode(nIns, 0x088);
		sendCode (nData,0x04);
		tortuga();
		sendCode(nIns, 0x0CD);
		sendCode (nData,0x01);
		
		tortuga();
		sendCode(nIns, 0x0C6);
		sendCode (nData,0x01);
		delay(nt1500_msec);
		
			guardar();
			sendCode(nIns, 0x0C0);
			sendCode (nData,0x00);
			
			clearScreen(0x0C6);
			clearScreen(0x0C0);
			
			guardar();
			sendCode(nIns, 0x0C1);
			sendCode (nData,0x00);
			tortuga();
			sendCode(nIns, 0x0C5);
			sendCode (nData,0x01);
			delay(nt1500_msec);
			clearScreen(0x0C5);
			clearScreen(0x0C1);
			
			guardar();
			sendCode(nIns, 0x0C2);
			sendCode (nData,0x00);
			tortuga();
			sendCode(nIns, 0x0C4);
			sendCode (nData,0x01);
			delay(nt1500_msec);
			clearScreen(0x0C2);
			
			guardar();
			sendCode(nIns, 0x0C3);
			sendCode (nData,0x00);
			delay(nt15_msec);
			clearScreen(0x0C3);
			
			guardar();
			sendCode(nIns, 0x084);
			sendCode (nData,0x00);
			delay(nt1500_msec);
			clearScreen(0x084);
			
			clearScreen(0x0C4);
			mono2();
			sendCode(nIns, 0x0C4);
			sendCode (nData,0x02);
			delay(nt1500_msec);
			
			tortuga2();
			sendCode(nIns, 0x0C5);
			sendCode (nData,0x03);
			tortuga2();
			sendCode(nIns, 0x0C3);
			sendCode (nData,0x03);
			clearScreen(0x0C5);
			clearScreen(0x0C3);
			tortuga3();
			sendCode(nIns, 0x0C5);
			sendCode (nData,0x03);
			tortuga3();
			sendCode(nIns, 0x0C3);
			sendCode (nData,0x03);
			
			delay(nt1500_msec);
			clearScreen(0x0C4);
			guardar();
			sendCode(nIns, 0x0C6);
			sendCode (nData,0x00);
			delay(nt1500_msec);
			clearScreen(0x0C6);
			guardar();
			sendCode(nIns, 0x0C7);
			sendCode (nData,0x00);
			delay(nt1500_msec);
			
			clearScreen(0x0C7);
			guardar();
			sendCode(nIns, 0x0C8);
			sendCode (nData,0x00);
			delay(nt15_msec);
			
			clearScreen(0x0C7);
			monoBrincando();
			sendCode(nIns, 0x0C8);
			sendCode (nData,0x05);
			delay(nt150_msec);
			clearScreen(0x088);
			caja2();
			sendCode(nIns, 0x088);
			sendCode (nData,0x04);
			
		
			sendCode(nIns, 0x80);
			char myName[] = {"BONUS"};
			printText (0x80, myName);
			delay(nt1500_msec);
			clearScreen(0x088);
			caja();
			sendCode(nIns, 0x088);
			sendCode (nData,0x04);
			delay(nt1500_msec);
			clearScreen(0x0c8);
			
			guardar();
			sendCode(nIns, 0x0C8);
			sendCode (nData,0x00);
			delay(nt150_msec);
			clearScreen(0x0c8);
			
			guardar();
			sendCode(nIns, 0x0C9);
			sendCode (nData,0x00);
			delay(nt150_msec);
			clearScreen(0x0c9);
			
			guardar();
			sendCode(nIns, 0x0CA);
			sendCode (nData,0x00);
			delay(nt150_msec);
			clearScreen(0x0CA);
			
			guardar();
			sendCode(nIns, 0x0CB);
			sendCode (nData,0x00);
			delay(nt150_msec);
			clearScreen(0x0CB);
			
			guardar();
			sendCode(nIns, 0x0CC);
			sendCode (nData,0x00);
			delay(nt150_msec);
			clearScreen(0x0CC);
			delay(nt150_msec);
			
			mono2();
			sendCode(nIns, 0x0CC);
			sendCode (nData,0x02);
			delay(nt1500_msec);
			delay(nt1500_msec);
			clearAllDisplay();
			char myName2[] = {"GAME OVER"};
			centerText (0x80, myName2);
			
			delay(nt150_msec);
			delay(nt150_msec);
			delay(nt150_msec);
			clearAllDisplay();
			
			
			
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
void printText (unsigned int Coord, char* Array)
{
	sendCode (nIns,Coord);
	sendCode (nIns,Coord);
	
	int x,lenght ;
	
	for ( x = 0; Array[x]!= 0l; x++)
	{	lenght =x;
		sendCode (nData,Array[x]);
		
	}
}
void centerText (int Row, char Text[])
{
	
	int lon =0;
	while (Text [lon]!=0l)
	{
		lon ++;
	}
	lon = 16-lon;
	int center = lon /2;
	int coord = Row + center;
	printText (coord, Text);
}
void guardar (void)
{
	sendCode (nIns,0x40);
	sendCode (nData, 0x0E);
	sendCode (nIns,0x41);
	sendCode (nData, 0x0E);
	sendCode (nIns,0x42);
	sendCode (nData, 0x0E);
	
	sendCode (nIns,0x43);
	sendCode (nData, 0x04);
	
	sendCode (nIns,0x44);
	sendCode (nData, 0x1F);
	
	sendCode (nIns,0x45);
	sendCode (nData, 0x04);
	
	sendCode (nIns,0x46);
	sendCode (nData, 0x0A);
	
	sendCode (nIns,0x47);
	sendCode (nData, 0x11);

}
void clearScreen(int Coord){
	sendCode(nIns, Coord);
	sendCode(nData, 0x20);
}
void tortuga (void)
{	
		sendCode (nIns,0x48);
		sendCode (nData, 0x00);
		sendCode (nIns,0x49);
		sendCode (nData, 0x00);
		sendCode (nIns,0x4A);
		sendCode (nData, 0x00);
		sendCode (nIns,0x4B);
		sendCode (nData, 0x00);
		sendCode (nIns,0x4C);
		sendCode (nData, 0x00);
		sendCode (nIns,0x4D);
		sendCode (nData, 0x1F);
		//4F  50-57  58 5F
		sendCode (nIns,0x4E);
		sendCode (nData, 0x0A);
		
		sendCode (nIns,0x4F);
		sendCode (nData, 0x1F);
}
void mono2 (void)
{
		sendCode (nIns,0x50);
		sendCode (nData, 0x0E);
		sendCode (nIns,0x51);
		sendCode (nData, 0x0E);
		sendCode (nIns,0x52);
		sendCode (nData, 0x0E);
		
		sendCode (nIns,0x53);
		sendCode (nData, 0x15);
		
		sendCode (nIns,0x54);
		sendCode (nData, 0x0E);
		
		sendCode (nIns,0x55);
		sendCode (nData, 0x04);
		
		sendCode (nIns,0x56);
		sendCode (nData, 0x0A);
		
		sendCode (nIns,0x57);
		sendCode (nData, 0x1F);

}
void tortuga2 (void)
{
			sendCode (nIns,0x58);
			sendCode (nData, 0x00);
			sendCode (nIns,0x59);
			sendCode (nData, 0x00);
			sendCode (nIns,0x5A);
			sendCode (nData, 0x00);
			sendCode (nIns,0x5B);
			sendCode (nData, 0x00);
			sendCode (nIns,0x5C);
			sendCode (nData, 0x00);
			sendCode (nIns,0x5D);
			sendCode (nData, 0x00);
			//4F  50-57  58 5F
			sendCode (nIns,0x5E);
			sendCode (nData, 0x01);
			
			sendCode (nIns,0x5F);
			sendCode (nData, 0x00);
}
void tortuga3 (void)
{
				sendCode (nIns,0x58);
				sendCode (nData, 0x00);
				sendCode (nIns,0x59);
				sendCode (nData, 0x00);
				sendCode (nIns,0x5A);
				sendCode (nData, 0x00);
				sendCode (nIns,0x5B);
				sendCode (nData, 0x00);
				sendCode (nIns,0x5C);
				sendCode (nData, 0x00);
				sendCode (nIns,0x5D);
				sendCode (nData, 0x00);
				//4F  50-57  58 5F
				sendCode (nIns,0x5E);
				sendCode (nData, 0x00);
				
				sendCode (nIns,0x5F);
				sendCode (nData, 0x01);
}
void caja (void)
{
		sendCode (nIns,0x60);
		sendCode (nData, 0x00);
		sendCode (nIns,0x61);
		sendCode (nData, 0x00);
		sendCode (nIns,0x62);
		sendCode (nData, 0x00);
		
		sendCode (nIns,0x63);
		sendCode (nData, 0x00);
		
		sendCode (nIns,0x64);
		sendCode (nData, 0x07);
		
		sendCode (nIns,0x65);
		sendCode (nData, 0x07);
		
		sendCode (nIns,0x66);
		sendCode (nData, 0x07);
		
		sendCode (nIns,0x67);
		sendCode (nData, 0x00);
}
void monoBrincando (void)
{
		sendCode (nIns,0x68);
		sendCode (nData, 0x0E);
		sendCode (nIns,0x69);
		sendCode (nData, 0x0E);
		sendCode (nIns,0x6A);
		sendCode (nData, 0x04);
		
		sendCode (nIns,0x6B);
		sendCode (nData, 0x1F);
		
		sendCode (nIns,0x6C);
		sendCode (nData, 0x04);
		
		sendCode (nIns,0x6D);
		sendCode (nData, 0x0A);
		
		sendCode (nIns,0x6E);
		sendCode (nData, 0x11);
		
		sendCode (nIns,0x6F);
		sendCode (nData, 0x00);
}
void caja2 (void)
{
			sendCode (nIns,0x60);
			sendCode (nData, 0x01);
			sendCode (nIns,0x61);
			sendCode (nData, 0x01);
			sendCode (nIns,0x62);
			sendCode (nData, 0x00);
			
			sendCode (nIns,0x63);
			sendCode (nData, 0x00);
			
			sendCode (nIns,0x64);
			sendCode (nData, 0x07);
			
			sendCode (nIns,0x65);
			sendCode (nData, 0x07);
			
			sendCode (nIns,0x66);
			sendCode (nData, 0x07);
			
			sendCode (nIns,0x67);
			sendCode (nData, 0x0E);
}
void clearAllDisplay(void)
{
	sendCode(nIns,0x01);
}
