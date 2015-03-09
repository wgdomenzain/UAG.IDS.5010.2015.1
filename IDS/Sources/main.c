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

int int_Temp;

//Cursor Blink off initialization
const unsigned char InitializeLCD[5] = {0x38, 0x38, 0x38, 0x0C, 0x01};
//--------------------------------------------------------------
//Declare Prototypes
/* Functions */
void cfgPorts(void);
void cfgADC(void);
void cfgpwm(void);
void initLCD(void);
void delay(long time);
void sendCode(int Code, int Data);
void imprimirTemp(int centena,int decena, int unidad);
/*@description: Initial Port Cfg 
*/
int result = 0, unidad = 0, decena = 0,dummy = 0, adc;
int centena=0;			
int main(void)
{
	//Configure ports
	cfgPorts();
	//Initialize LCD
	initLCD();
	//Configure ADC
	cfgADC();
	
	//Set position to print character
	//sendCode(nIns, 0x83);
	//Print character
	//sendCode(nData, 'W');
	//sendCode(nIns, 0x80);

	for(;;)
	{
		if((ADC0_SC1A & 0x00000080)  == 0x00000080)
		{
			result = ADC0_RA;
			adc = result;
			ADC0_SC1A = 0x00;
			//result = (result*13)/10;
			centena = (result/100);
			decena = (result-centena*100)/10;
			unidad = (result-(centena*100)-(decena*10));
		
			imprimirTemp(centena, decena, unidad);
		
		}
		else
		{
			
		}	
	}
	return 0;
}

void cfgPorts(void)
{
	//Activate clocks
	//Turn on clock for portb
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;	
	//Turn on clock for portd
	//SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;	
	////Turn on clock for portc
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	////Turn on clock for porte
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	////Turn on clock for porte
	SIM_SCGC6 = SIM_SCGC6_ADC0_MASK;
	
	/* Set pins of PORTB as GPIO */
	PORTB_PCR0= PORT_PCR_MUX(1);
	PORTB_PCR1= PORT_PCR_MUX(1);
	PORTB_PCR2=(0|PORT_PCR_MUX(1));
	PORTB_PCR3=(0|PORT_PCR_MUX(1));
	PORTB_PCR4=(0|PORT_PCR_MUX(1));
	PORTB_PCR5=(0|PORT_PCR_MUX(1));
	PORTB_PCR6=(0|PORT_PCR_MUX(1));
	PORTB_PCR7=(0|PORT_PCR_MUX(1));
	
	/* Set pins of PORTC as GPIO */
	PORTC_PCR0= PORT_PCR_MUX(1);
	PORTC_PCR1= PORT_PCR_MUX(1);
	PORTC_PCR2= PORT_PCR_MUX(1);
	PORTC_PCR3= PORT_PCR_MUX(1);
	PORTC_PCR4= PORT_PCR_MUX(1);
	PORTC_PCR5= PORT_PCR_MUX(1);
	PORTC_PCR6= PORT_PCR_MUX(1);
	PORTC_PCR7= PORT_PCR_MUX(1);
	
	/* Set pins of PORTD as GPIO */
	/*PORTD_PCR0= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1);
	PORTD_PCR2= PORT_PCR_MUX(1);
	PORTD_PCR3= PORT_PCR_MUX(1);
	PORTD_PCR4= PORT_PCR_MUX(1);
	PORTD_PCR5= PORT_PCR_MUX(1);
	PORTD_PCR6= PORT_PCR_MUX(1);
	PORTD_PCR7= PORT_PCR_MUX(1);*/
	
	/* Set pin of PORTE as ADC0_DP0/ADC0_SE0 */
	PORTE_PCR20= PORT_PCR_MUX(0);
	
	//Initialize PortB
	GPIOB_PDOR = 0x00;
	
	//Initialize PortC
	GPIOC_PDOR = 0x00;

	//Configure PortB as outputs
	GPIOB_PDDR = 0xFF;
	
	//Configure PortD as outputs
	GPIOC_PDDR = 0xFF;
	
	//Configure PortC as inputs
	//GPIOC_PDDR = 0x00;
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
		delay(nt40_usec);
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

void cfgADC(void)
{	
	//ADC Configuration Register 1 (ADCx_CFG1) page 465
	ADC0_CFG1 = 0x00;  
	
	//ADC Configuration Register 2 (ADCx_CFG2) page 467
	//Channel A selected
	ADC0_CFG2 = 0x00;  	
	
	//Status and Control Register 2 (ADCx_SC2) page 470
	ADC0_SC2 = 0;   	
	
	//Status and Control Register 3 (ADCx_SC3)
	ADC0_SC3 = 0x0C; 	
	
	//ADC Status and Control Registers 1 - page 462
	//This registers triggers the ADC conversion
	ADC0_SC1A = 0x00;
}

void imprimirTemp(int centena,int decena, int unidad){
	sendCode(nIns, 0x85);
	sendCode(nData,0X30+centena);
	sendCode(nData, 0X30+decena);
	sendCode(nData,0x30+unidad);
	sendCode(nData, 0xDF);
	sendCode(nData, 'C');
}
