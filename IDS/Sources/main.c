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
#define nt15_msec	6000
#define nt40_usec	3500
#define nt1_sec		2600000

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
void printText(unsigned char coord, char* array);
void centerText(int row, char* array);
void guardarCaracteres();
void baileMonos(int ban);


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
	
	//char myName[] = {"Hola"};
	//char myName2[] = {"Mundo"};
	//prinText(0xC0, myName);
	//centerText(1, myName);
	//centerText(2, myName2);
	//sendCode(nIns, 0x80);
	int x = 0, ban1 = 0, ban2 = 0, ban3 = 0, pos1 = 0xC1, pos2 = pos1+4, pos3 = pos2+4, pos4 = pos3+4;
	guardarCaracteres();
	
	for(;;)
	{
		for(x = 0; x < 16; x++){
			if(x != 8 && x != 3 && x != 6 && x != 10 && x != 14){
				sendCode(nIns, 0x80+x);
				if(ban2 == 0){
					sendCode(nData, 0x02);
				}else{
					sendCode(nData, 0x03);
				}
			}
		}
		for(x = 0; x < 16; x++){
			sendCode(nIns, 0xC0+x);
			if(ban2 == 0){
				sendCode(nData, 0x03);
			}else{
				sendCode(nData, 0x02);
			}
		}
		sendCode(nIns, 0x83);
		sendCode(nData, 0x07);
		sendCode(nIns, 0x86);
		sendCode(nData, 0x07);
		sendCode(nIns, 0x8A);
		sendCode(nData, 0x07);
		sendCode(nIns, 0x8E);
		sendCode(nData, 0x07);
		
		if(ban1 == 0){
			sendCode(nIns, 0x88);
			sendCode(nData, 0x00);
			ban1 = 1;
		}else{
			sendCode(nIns, 0x88);
			sendCode(nData, 0x01);
			ban1 = 0;
		}
		
		//baile monos
		sendCode(nIns, pos1);
		baileMonos(ban3);
		sendCode(nIns, pos2);
		baileMonos(ban3);
		sendCode(nIns, pos3);
		baileMonos(ban3);
		sendCode(nIns, pos4);
		baileMonos(ban3);
		ban3++;
		
		if(ban2 == 0){
			ban2 = 1;
		}else{
			ban2 = 0;
		}
		if(ban3 > 2){
			ban3 = 0;
		}
		delay(nt1_sec/2);
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
void printText(unsigned char coord, char* array){
	int x = 0;
	sendCode(nIns, coord);
	for(x = 0; array[x] != 0l; x++){
		sendCode(nData, array[x]);
	}
}
void centerText(int row, char* array){
	int x = 0, t = 16, pos;
	for(x = 0; array[x]!= 0l; x++);
	pos = t-x;
	pos = pos/2;
	if(row == 1){
		printText(0x80+pos, array);
	}else if(row == 2){
		printText(0xC0+pos, array);
	}
}
void guardarCaracteres(){
	//ccaracter 0
	sendCode(nIns, 0x40);
	sendCode(nData, 0x05);
	sendCode(nIns, 0x41);
	sendCode(nData, 0x14);
	sendCode(nIns, 0x42);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x43);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x44);
	sendCode(nData, 0x1F);
	sendCode(nIns, 0x45);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x46);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x47);
	sendCode(nData, 0x11);
	
	//caracter 1
	sendCode(nIns, 0x48);
	sendCode(nData, 0x14);
	sendCode(nIns, 0x49);
	sendCode(nData, 0x05);
	sendCode(nIns, 0x4A);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x4B);
	sendCode(nData, 0x0A);
	sendCode(nIns, 0x4C);
	sendCode(nData, 0x15);
	sendCode(nIns, 0x4D);
	sendCode(nData, 0x0A);
	sendCode(nIns, 0x4E);
	sendCode(nData, 0x14);
	sendCode(nIns, 0x4F);
	sendCode(nData, 0x02);
	
	//caracter 2
	sendCode(nIns, 0x50);
	sendCode(nData, 0x05);
	sendCode(nIns, 0x51);
	sendCode(nData, 0x08);
	sendCode(nIns, 0x52);
	sendCode(nData, 0x00);
	sendCode(nIns, 0x53);
	sendCode(nData, 0x02);
	sendCode(nIns, 0x54);
	sendCode(nData, 0x10);
	sendCode(nIns, 0x55);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x56);
	sendCode(nData, 0x01);
	sendCode(nIns, 0x57);
	sendCode(nData, 0x08);
	
	//caracter 3
	sendCode(nIns, 0x58);
	sendCode(nData, 0x08);
	sendCode(nIns, 0x59);
	sendCode(nData, 0x02);
	sendCode(nIns, 0x5A);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x5B);
	sendCode(nData, 0x10);
	sendCode(nIns, 0x5C);
	sendCode(nData, 0x01);
	sendCode(nIns, 0x5D);
	sendCode(nData, 0x08);
	sendCode(nIns, 0x5E);
	sendCode(nData, 0x02);
	sendCode(nIns, 0x5F);
	sendCode(nData, 0x08);
	
	//caracter 4
	sendCode(nIns, 0x60);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x61);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x62);
	sendCode(nData, 0x1E);
	sendCode(nIns, 0x63);
	sendCode(nData, 0x0D);
	sendCode(nIns, 0x64);
	sendCode(nData, 0x06);
	sendCode(nIns, 0x65);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x66);
	sendCode(nData, 0x0A);
	sendCode(nIns, 0x67);
	sendCode(nData, 0x09);
	
	//caracter 5
	sendCode(nIns, 0x68);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x69);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x6A);
	sendCode(nData, 0x0F);
	sendCode(nIns, 0x6B);
	sendCode(nData, 0x16);
	sendCode(nIns, 0x6C);
	sendCode(nData, 0x0C);
	sendCode(nIns, 0x6D);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x6E);
	sendCode(nData, 0x0A);
	sendCode(nIns, 0x6F);
	sendCode(nData, 0x12);
	
	//caracter 6
	sendCode(nIns, 0x70);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x71);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x72);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x73);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x74);
	sendCode(nData, 0x0E);
	sendCode(nIns, 0x75);
	sendCode(nData, 0x15);
	sendCode(nIns, 0x76);
	sendCode(nData, 0x0A);
	sendCode(nIns, 0x77);
	sendCode(nData, 0x11);
	
	//caracter 7
	sendCode(nIns, 0x78);
	sendCode(nData, 0x02);
	sendCode(nIns, 0x79);
	sendCode(nData, 0x0A);
	sendCode(nIns, 0x7A);
	sendCode(nData, 0x03);
	sendCode(nIns, 0x7B);
	sendCode(nData, 0x15);
	sendCode(nIns, 0x7C);
	sendCode(nData, 0x04);
	sendCode(nIns, 0x7D);
	sendCode(nData, 0x0C);
	sendCode(nIns, 0x7E);
	sendCode(nData, 0x1D);
	sendCode(nIns, 0x7F);
	sendCode(nData, 0x08);
}
void baileMonos(int ban){
	switch(ban){
		case 0:
			sendCode(nData, 0x04);
			break;
		case 1:
			sendCode(nData, 0x05);
			break;
		case 2:
			sendCode(nData, 0x06);
			break;
	}
}
