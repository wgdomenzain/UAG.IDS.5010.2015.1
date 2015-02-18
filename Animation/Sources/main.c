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
void clearDisplay(void);
void printSavedChar(int Coord,int character);
void createChar(void);
void pacman(void);
void matonpacman(void);
void disparo(void);
void defensorpacman(void);
void impacto(void);

/*@description: Initial Port Cfg 
*/
			
int main(void)
{
	int i=0;
	//Configure ports
	cfgPorts();
	//Initialize LCD
	initLCD();
	//Set position to print character
	//sendCode(nIns, 0x80);
	//Print character
	//char up[] = {"moises"};
	//char down[] = {"gonzalez"};
	//printText(0x83,"Moises");
	//printText(0xC0,down);
	
	//centerText(0x80, myName);
	//sendCode(nData, 0x80);
	
	
	for(;;)
	{
			
		//createChar();
		//sendCode(nIns,0x80);
		//sendCode(nData,0x00);
		
		//createChar2();
		//sendCode(nIns,0x8F);
		//sendCode(nData,0x00);
		
		//pacman();
		//sendCode(nIns,0x80);
		//sendCode(nData,0x00);
		
		//matonpacman();
		//sendCode(nIns,0x80);
		//sendCode(nData,0x00);
		
		//disparo();
		//sendCode(nIns,0x80);
		//sendCode(nData,0x00);
		
		//defensorpacman();
		//sendCode(nIns,0x80);
		//sendCode(nData,0x00);
		
		//impacto();
		//sendCode(nIns,0x80);
		//sendCode(nData,0x00);
		
		//clearDisplay();
		//delay(140000);
		
		
		printText(0xC0,"z");
		delay(1000000);
		clearDisplay();
		
		printText(0x80,"s");
		printText(0xC0,"ez");
		delay(1000000);
		clearDisplay();
		
		printText(0x80,"es");
		printText(0xC0,"lez");
		delay(1000000);
		clearDisplay();
		
		printText(0x80,"ses");
		printText(0xC0,"alez");
		delay(1000000);
		clearDisplay();
		
		printText(0x80,"ises");
		printText(0xC0,"zalez");
		delay(1000000);
		clearDisplay();
				
		printText(0x80,"oises");
		printText(0xC0,"nzalez");
		delay(1000000);
		clearDisplay();
		
		printText(0x80,"Moises");
		printText(0xC0,"onzalez");
		delay(1000000);
		clearDisplay();
		
		printText(0x81,"Moises");
		printText(0xC0,"Gonzalez");
		delay(1000000);
		clearDisplay();
				
		printText(0x82,"Moises");
		printText(0xC1,"Gonzalez");
		delay(1000000);
		clearDisplay();
						
		printText(0x83,"Moises");
		printText(0xC2,"Gonzalez");
		delay(1000000);
		clearDisplay();
								
		printText(0x84,"Moises");
		printText(0xC3,"Gonzalez");
		delay(1000000);
		clearDisplay();
										
		printText(0x85,"Moises");
		printText(0xC4,"Gonzalez");
		delay(1400000);
		delay(1400000);
		delay(1400000);
		clearDisplay();
		
		printText(0x86,"Moises");
		printText(0xC5,"Gonzalez");
		delay(1000000);
		clearDisplay();
				
		printText(0x87,"Moises");
		printText(0xC6,"Gonzalez");
		delay(1000000);
		clearDisplay();
						
		printText(0x88,"Moises");
		printText(0xC7,"Gonzalez");
		delay(1000000);
		clearDisplay();
								
		printText(0x89,"Moises");
		printText(0xC8,"Gonzalez");
		delay(1000000);
		clearDisplay();
										
		printText(0x8A,"Moises");
		printText(0xC9,"Gonzalez");
		delay(1000000);
		clearDisplay();
												
		printText(0x8B,"Moises");
		printText(0xCA,"Gonzalez");
		delay(1000000);
		clearDisplay();
														
		printText(0x8C,"Moises");
		printText(0xCB,"Gonzalez");
		delay(1000000);
		clearDisplay();
																
		printText(0x8D,"Moises");
		printText(0xCC,"Gonzalez");
		delay(1000000);
		clearDisplay();
																		
		printText(0x8E,"Moises");
		printText(0xCD,"Gonzalez");
		delay(1000000);
		clearDisplay();
																				
		printText(0x8F,"Moises");
		printText(0xCE,"Gonzalez");
		delay(1000000);
		clearDisplay();
		
		printText(0xCF,"Gonzalez");
		delay(1000000);
		clearDisplay();
		
		printText(0x84,"PRESENTA");
		/*pacman();
		sendCode(nIns,0x80);
		sendCode(nData,0x00);*/
		printSavedChar(0x80,0x01);//pacman es el 0x01 caracter guardado
		delay(1400000);
		delay(1400000);
		clearDisplay();
		
		printText(0x84,"PRESENTA");
		printSavedChar(0x81,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x84,"PRESENTA");
		printSavedChar(0x82,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x84,"PRESENTA");
		printSavedChar(0x83,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x85,"RESENTA");
		printSavedChar(0x84,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x86,"ESENTA");
		printSavedChar(0x85,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x87,"SENTA");
		printSavedChar(0x86,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x88,"ENTA");
		printSavedChar(0x87,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x89,"NTA");
		printSavedChar(0x88,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x8A,"TA");
		printSavedChar(0x89,0x01);
		delay(1400000);
		clearDisplay();
		
		printText(0x8B,"A");
		printSavedChar(0x8A,0x01);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8B,0x01);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8B,0x01);
		printSavedChar(0x8F,0x02);
		delay(1400000);
		clearDisplay();
					
		printSavedChar(0x8B,0x01);
		printSavedChar(0x8F,0x02);
		printSavedChar(0x8E,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8B,0x01);
		printSavedChar(0x8F,0x02);
		printSavedChar(0x8D,0x03);
		delay(1400000);
		clearDisplay();
					
		printSavedChar(0x8B,0x01);
		printSavedChar(0x8F,0x02);
		printSavedChar(0x8C,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8F,0x02);
		printSavedChar(0xC0,0x04);
		printText(0x81,"Maldito");
		delay(1400000);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8F,0x02);
		printSavedChar(0xC0,0x04);
		printText(0x81,"lo mataste");
		delay(1400000);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCF,0x02);
		printSavedChar(0xC1,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCE,0x02);
		printSavedChar(0xC2,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xCC,0x03);
		printSavedChar(0xC3,0x04);
		printSavedChar(0xC4,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xCB,0x03);
		printSavedChar(0xC3,0x04);
		printSavedChar(0xC5,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xCA,0x03);
		printSavedChar(0xC3,0x04);
		printSavedChar(0xC6,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC9,0x03);
		printSavedChar(0xC3,0x04);
		printSavedChar(0xC7,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0xC8,0x05);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x80,0x04);
		printSavedChar(0xC4,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x81,0x04);
		printSavedChar(0xC5,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x82,0x04);
		printSavedChar(0xC6,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x83,0x04);
		printSavedChar(0xC7,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x84,0x04);
		printSavedChar(0xC8,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x85,0x04);
		printSavedChar(0xC9,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x86,0x04);
		printSavedChar(0xCA,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x87,0x04);
		printSavedChar(0xCB,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x88,0x04);
		printSavedChar(0xCC,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8D,0x02);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x89,0x04);
		printSavedChar(0xCD,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8D,0x02);
		printSavedChar(0x8C,0x03);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x8A,0x04);
		printSavedChar(0xCE,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8D,0x02);
		printSavedChar(0x8B,0x03);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x89,0x04);
		printSavedChar(0xCF,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCD,0x02);
		printSavedChar(0x8A,0x03);
		printSavedChar(0xC4,0x04);
		printSavedChar(0x89,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCC,0x02);
		printSavedChar(0x89,0x05);
		printSavedChar(0xC4,0x04);
		printSavedChar(0xC5,0x03);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCB,0x02);
		printSavedChar(0xC4,0x04);
		printSavedChar(0xC6,0x03);
		printSavedChar(0x80,0x04);
		printSavedChar(0xC0,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCB,0x02);
		printSavedChar(0xC4,0x04);
		printSavedChar(0xC7,0x03);
		printSavedChar(0x81,0x04);
		printSavedChar(0xC1,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCB,0x02);
		printSavedChar(0xCA,0x03);
		printSavedChar(0xC4,0x04);
		printSavedChar(0xC8,0x03);
		printSavedChar(0x82,0x04);
		printSavedChar(0xC2,0x04);
		printSavedChar(0x80,0x04);
		printSavedChar(0xC0,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCB,0x02);
		printSavedChar(0xC9,0x05);
		printSavedChar(0xC4,0x04);
		printSavedChar(0x83,0x04);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x81,0x04);
		printSavedChar(0xC1,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCC,0x02);
		printSavedChar(0xC5,0x04);
		printSavedChar(0xC6,0x03);
		printSavedChar(0x84,0x04);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x81,0x04);
		printSavedChar(0x82,0x03);
		printSavedChar(0xC1,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCC,0x02);
		printSavedChar(0xC5,0x04);
		printSavedChar(0xC7,0x03);
		printSavedChar(0x84,0x04);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x81,0x04);
		printSavedChar(0x83,0x03);
		printSavedChar(0xC1,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8C,0x02);
		printSavedChar(0xC5,0x04);
		printSavedChar(0xC8,0x03);
		printSavedChar(0x84,0x05);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x81,0x04);
		printSavedChar(0xC1,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8B,0x02);
		printSavedChar(0xC5,0x04);
		printSavedChar(0xC9,0x03);
		printSavedChar(0xC3,0x04);
		printSavedChar(0x81,0x04);
		printSavedChar(0x82,0x03);
		printSavedChar(0xC1,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8B,0x02);
		printSavedChar(0xC6,0x04);
		printSavedChar(0xCA,0x03);
		printSavedChar(0xC4,0x04);
		printSavedChar(0x81,0x04);
		printSavedChar(0x83,0x03);
		printSavedChar(0xC2,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8C,0x02);
		printSavedChar(0xC7,0x04);
		printSavedChar(0xCB,0x03);
		printSavedChar(0xC5,0x04);
		printSavedChar(0x82,0x04);
		printSavedChar(0x84,0x03);
		printSavedChar(0xC3,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8C,0x02);
		printSavedChar(0xC7,0x04);
		printSavedChar(0xCC,0x03);
		printSavedChar(0xC5,0x04);
		printSavedChar(0x83,0x04);
		printSavedChar(0x85,0x03);
		printSavedChar(0xC3,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCC,0x02);
		printSavedChar(0xC7,0x04);
		printSavedChar(0xC8,0x03);
		printSavedChar(0xCD,0x03);
		printSavedChar(0xC5,0x04);
		printSavedChar(0x84,0x04);
		printSavedChar(0x86,0x03);
		printSavedChar(0xC3,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8C,0x02);
		printSavedChar(0xC7,0x04);
		printSavedChar(0xC9,0x03);
		printSavedChar(0xCE,0x03);
		printSavedChar(0xC5,0x04);
		printSavedChar(0x84,0x04);
		printSavedChar(0x85,0x03);
		printSavedChar(0x87,0x03);
		printSavedChar(0xC3,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8D,0x02);
		printSavedChar(0xC7,0x04);
		printSavedChar(0xC8,0x03);
		printSavedChar(0xCA,0x03);
		printSavedChar(0xCF,0x03);
		printSavedChar(0xC5,0x04);
		printSavedChar(0x84,0x04);
		printSavedChar(0x86,0x03);
		printSavedChar(0x88,0x03);
		printSavedChar(0xC3,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8D,0x02);
		printSavedChar(0xC7,0x04);
		printSavedChar(0xC9,0x03);
		printSavedChar(0xCB,0x03);
		printSavedChar(0xC5,0x04);
		printSavedChar(0x84,0x04);
		printSavedChar(0x87,0x03);
		printSavedChar(0x89,0x03);
		printSavedChar(0xC2,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8E,0x02);
		printSavedChar(0xC8,0x04);
		printSavedChar(0xCA,0x03);
		printSavedChar(0xCC,0x03);
		printSavedChar(0xC6,0x04);
		printSavedChar(0x85,0x04);
		printSavedChar(0x88,0x03);
		printSavedChar(0x8A,0x03);
		printSavedChar(0x82,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8E,0x02);
		printSavedChar(0xC9,0x04);
		printSavedChar(0xCB,0x03);
		printSavedChar(0xCD,0x03);
		printSavedChar(0xC7,0x04);
		printSavedChar(0x85,0x04);
		printSavedChar(0x86,0x03);
		printSavedChar(0x89,0x03);
		printSavedChar(0x8B,0x03);
		printSavedChar(0x82,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0x8D,0x02);
		printSavedChar(0xCA,0x04);
		printSavedChar(0xCC,0x03);
		printSavedChar(0xCE,0x03);
		printSavedChar(0xC8,0x04);
		printSavedChar(0x85,0x04);
		printSavedChar(0x87,0x03);
		printSavedChar(0x8A,0x03);
		printSavedChar(0x8C,0x03);
		printSavedChar(0x82,0x04);
		delay(1400000);
		clearDisplay();
		
		printSavedChar(0xCA,0x04);
		printSavedChar(0xCD,0x03);
		printSavedChar(0xCF,0x03);
		printSavedChar(0xC8,0x04);
		printSavedChar(0x85,0x04);
		printSavedChar(0x88,0x03);
		printSavedChar(0x8B,0x03);
		printSavedChar(0x8D,0x05);
		printSavedChar(0x82,0x04);
		printSavedChar(0x80,0x04);
		printSavedChar(0xC0,0x04);
		delay(1400000);
		delay(1400000);
		clearDisplay();
		
		printText(0x87,"FIN");
		delay(1400000);
		delay(1400000);
		delay(1400000);
		/* The logic for the buttons works if a pull-down 
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

void clearDisplay(void)
{
	sendCode(nIns,0x01);
}

void printSavedChar(int Coord,int character)
{
	sendCode(nIns,Coord);
	sendCode(nData,character);
}
void createChar(void){//es el 0x00
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

void pacman(void){ //es el 0x01
	sendCode(nIns,0x48);
	sendCode(nData,0x0E);
	sendCode(nIns,0x49);
	sendCode(nData,0x1D);
	sendCode(nIns,0x4A);
	sendCode(nData,0x1F);
	sendCode(nIns,0x4B);
	sendCode(nData,0x1F);
	sendCode(nIns,0x4C);
	sendCode(nData,0x18);
	sendCode(nIns,0x4D);
	sendCode(nData,0x1F);
	sendCode(nIns,0x4E);
	sendCode(nData,0x1F);
	sendCode(nIns,0x4F);
	sendCode(nData,0x0E);
}

void matonpacman(void){ //es el 0x02
	sendCode(nIns,0x50);
	sendCode(nData,0x07);
	sendCode(nIns,0x51);
	sendCode(nData,0x07);
	sendCode(nIns,0x52);
	sendCode(nData,0x07);
	sendCode(nIns,0x53);
	sendCode(nData,0x1A);
	sendCode(nIns,0x54);
	sendCode(nData,0x0E);
	sendCode(nIns,0x55);
	sendCode(nData,0x02);
	sendCode(nIns,0x56);
	sendCode(nData,0x05);
	sendCode(nIns,0x57);
	sendCode(nData,0x05);
}

void disparo(void){ //es el 0x03
	sendCode(nIns,0x58);
	sendCode(nData,0x00);
	sendCode(nIns,0x59);
	sendCode(nData,0x00);
	sendCode(nIns,0x5A);
	sendCode(nData,0x00);
	sendCode(nIns,0x5B);
	sendCode(nData,0x1B);
	sendCode(nIns,0x5C);
	sendCode(nData,0x00);
	sendCode(nIns,0x5D);
	sendCode(nData,0x00);
	sendCode(nIns,0x5E);
	sendCode(nData,0x00);
	sendCode(nIns,0x5F);
	sendCode(nData,0x00);
}

void defensorpacman(void){//es el 0x04
	sendCode(nIns,0x60);
	sendCode(nData,0x1C);
	sendCode(nIns,0x61);
	sendCode(nData,0x1C);
	sendCode(nIns,0x62);
	sendCode(nData,0x1C);
	sendCode(nIns,0x63);
	sendCode(nData,0x0B);
	sendCode(nIns,0x64);
	sendCode(nData,0x0E);
	sendCode(nIns,0x65);
	sendCode(nData,0x08);
	sendCode(nIns,0x66);
	sendCode(nData,0x14);
	sendCode(nIns,0x67);
	sendCode(nData,0x14);
}

void impacto(void){//es el 0x05
	sendCode(nIns,0x68);
	sendCode(nData,0x00);
	sendCode(nIns,0x69);
	sendCode(nData,0x11);
	sendCode(nIns,0x6A);
	sendCode(nData,0x0A);
	sendCode(nIns,0x6B);
	sendCode(nData,0x0E);
	sendCode(nIns,0x6C);
	sendCode(nData,0x0E);
	sendCode(nIns,0x6D);
	sendCode(nData,0x0A);
	sendCode(nIns,0x6E);
	sendCode(nData,0x11);
	sendCode(nIns,0x6F);
	sendCode(nData,0x00);
}
