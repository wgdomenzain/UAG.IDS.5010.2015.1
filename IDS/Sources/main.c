/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
//#include "UART0_PDD.h"

#define PortLCD    GPIOD_PDOR
#define RS_1   GPIOB_PDOR |= 0x02 
#define RS_0   GPIOB_PDOR &= 0xF
#define Enable_1	   GPIOB_PDOR |= 0x01
#define Enable_0	   GPIOB_PDOR &= 0xFE

// time for delay
#define			n1seg			0xFFFF
#define			n0_5seg			0x4FFF
#define			n30mseg			0x0400
#define			n15mseg			0x02E8
#define			n40useg			0x1AD0

#define 		nIns			0x00
#define 		nData			0x01

#define PortButtons 	GPIOE_PDIR
const unsigned char InitializeLCD[5] 				= {0x38, 0x38, 0x38, 0x0C, 0x01}; 
unsigned int cfgADC(void);
//int seconds1 = 0,alarm = 0,minutes1 = 0,seconds2 = 0,minutes2 = 0,horas1 = 0, horas2 = 0;
int B1 = 0;
void uart0_putchar (char data);
unsigned char uart0_getchar (void);
char c;
char h;
 //For ADC
unsigned int Valor;
unsigned int Dece;
unsigned int Unid;
unsigned int Residuo;
unsigned int Deci;
unsigned int Residuo1;
void cfgPorts(void);
void UARTinit();
void quickSend(const unsigned char *str) ;
void quickSendNum(const unsigned val);
void quickSendHex(const unsigned val) ;
void sendCode(int Code, int Data);
void initLCD(void);
void delay(long time);
void Clock_Configuration (void);
void rtc_init(void);
void cfgPWM(void);
unsigned int cfgADC(void);
unsigned char uart0_getchar (void);
void uart0_putchar (char data);
int i;
int x;

int main(void)
{
	//int counter = 0;
	
	 cfgPorts();
	 initLCD();
	
	 UARTinit(); 
	// rtc_init();
	 //cfgADC();
	 //cfgPWM();
	i=0;
	
		UART0_D= 'H';
		delay(10000);
		UART0_D= 'o';
		delay(10000);
		UART0_D= 'l';
		delay(10000);
		UART0_D= 'a';
		delay(10000);
		UART0_D= ' ';
		delay(10000);
		UART0_D= 'M';
		delay(10000);
		UART0_D= 'u';
		delay(10000);
		UART0_D= 'n';
		delay(10000);
		UART0_D= 'd';
		delay(10000);
		UART0_D= 'o';
		delay(10000);
		UART0_D= '!';
		delay(10000);
		UART0_D= ' ';
		delay(10000);	
	
	for(;;) {	   
	   	
	}
	
	return 0;
}
void cfgPorts(void)
{
	//Turn on clock for portB and portC
 SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; /* SIM_SCGC5: PORTA=1 */
 SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /* SIM_SCGC5: PORTB=1 */
 SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; /* SIM_SCGC5: PORTC=1 */
 SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK; /* SIM_SCGC5: PORTD=1 */
 SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK; /* SIM_SCGC5: PORTE=1 */
	
	/* Set pins of PORTC as GPIO */
 PORTD_PCR0=(0|PORT_PCR_MUX(1));
 PORTD_PCR1=(0|PORT_PCR_MUX(1));
 PORTD_PCR2=(0|PORT_PCR_MUX(1));
 PORTD_PCR3=(0|PORT_PCR_MUX(1));
 PORTD_PCR4=(0|PORT_PCR_MUX(1));
 PORTD_PCR5=(0|PORT_PCR_MUX(1));
 PORTD_PCR6=(0|PORT_PCR_MUX(1));
 PORTD_PCR7=(0|PORT_PCR_MUX(1));
    
	
	/* Set pins of PORTB 0 and PORTB 1 as GPIO */
 PORTB_PCR0=(0|PORT_PCR_MUX(1));
 PORTB_PCR1=(0|PORT_PCR_MUX(1));
 PORTB_PCR8=(0|PORT_PCR_MUX(1));
 PORTB_PCR9=(0|PORT_PCR_MUX(1));
 PORTB_PCR10=(0|PORT_PCR_MUX(1));
 PORTB_PCR11=(0|PORT_PCR_MUX(1));
 
    /* Set pins of PORTE for PWM */
 PORTE_PCR0=(0|PORT_PCR_MUX(1));
 //PORTE_PCR30=(0|PORT_PCR_MUX(3));
  
 /* Set PORTB 2 for ADC  */
// PORTB_PCR2=(PORT_PCR_MUX(0));
	
	
	//Reasure first PortD and B value
 GPIOB_PDOR = 0x00;
 GPIOD_PDOR = 0x00;
 //GPIOE_PDOR = 0x00;
	//GPIOC_PDOR = 0x00;
	
	//Configure PortD as outputs
 GPIOD_PDDR = 0xFF;
	//Configure PortB as outputs
 GPIOB_PDDR = 0xFF;
	//Configure PortE as outputs
 GPIOE_PDDR = 0x00;
	//Configure PortC as outputs
	//GPIOC_PDDR = 0xFE;
	
}

void UARTinit()
{
 SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;                                                   
	
 /* PORTA_PCR1: ISF=0,MUX=2 */
 PORTA_PCR1 = (uint32_t)((PORTA_PCR1 & (uint32_t)~0x01000500UL) | (uint32_t)0x0200UL);
 /* PORTA_PCR2: ISF=0,MUX=2 */
 PORTA_PCR2 = (uint32_t)((PORTA_PCR2 & (uint32_t)~0x01000500UL) | (uint32_t)0x0200UL); 

 /* Disable TX & RX while we configure settings */
 UART0_C2 &= ~(UART0_C2_TE_MASK); //disable transmitter
 UART0_C2 &= ~(UART0_C2_RE_MASK); //disable receiver
 
 /* UART0_C1: LOOPS=0,DOZEEN=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
 UART0_C1 = 0x00U; /* Set the C1 register */
 /* UART0_C3: R8T9=0,R9T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
 UART0_C3 = 0x00U; /* Set the C3 register */
 /* UART0_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
 UART0_S2 = 0x00U; /* Set the S2 register */
 
 SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1); //set clock source to be from PLL/FLL
 SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0b100);
 unsigned SBR = 546;//137; //Set the baud rate register, SBR = 137
 UART0_BDH |= (~UART0_BDH_SBR_MASK) | SBR >> 8;
 UART0_BDL |= (~UART0_BDL_SBR_MASK) | SBR;
 
 char OSR = 3; //set the oversampling ratio to option #3 = 4x
 UART0_C4 &= (~UART0_C4_OSR_MASK) | OSR;
 
 /*
 * Target Baud rate = 38400 9600
 *
 * Baud rate = baud clock / ((OSR+1) * SBR)
 * baud clock = FLL/PLL = 20.97152MHz  32kHZ
 * OSR = 3
 * SBR = 137 //546
 * Resulting Baud rate = 20.97152MHz / ((3 + 1) * 546) = 9600
 */
 
 UART0_C5 |= UART0_C5_BOTHEDGE_MASK; //enable sampling on both edges of the clock
 UART0_C2 |= UART0_C2_TE_MASK; //enable transmitter
 UART0_C2 |= UART0_C2_RE_MASK; //enable receiver
	
}

void quickSend(const unsigned char *str) 
{
  while(*str!='\0') { //send every character except the null or '\0' character that terminates the string
    UART0_D = *str++; //put the next character in the transmit register & increment which character is next
    while((UART0_S1 & UART0_S1_TDRE_MASK) == 0); //wait for the trasmit register to be empty (meaning the whole character has been sent)
  }
}

void quickSendNum(const unsigned val) 
{
    char nums[20];
    int cnt=0;
    unsigned tmp = val;
    do { //send every character except the null or '\0' character that terminates the string
        char num = tmp % 10;
        nums[cnt++]='0'+num;
        //UART0_D = '0'+num; //put the next character in the transmit register & increment which character is next
        tmp /= 10;
        //while((UART0_S1 & UART0_S1_TDRE_MASK) == 0); //wait for the trasmit register to be empty (meaning the whole character has been sent)
    } while(tmp > 0);
 
    int i;
    for(i=cnt-1; i>=0; i--) {
        UART0_D = nums[i]; //put the next character in the transmit register & increment which character is next
        while((UART0_S1 & UART0_S1_TDRE_MASK) == 0); //wait for the trasmit register to be empty (meaning the whole character has been sent)
    }
}

void quickSendHex(const unsigned val) 
{
    char nums[20];
    int cnt=0;
    unsigned tmp = val;
    do { //send every character except the null or '\0' character that terminates the string
        char num = tmp % 16;
        if(num < 10)
            nums[cnt++]='0'+num;
        else
            nums[cnt++]='A'+num-10;
        //UART0_D = '0'+num; //put the next character in the transmit register & increment which character is next
        tmp /= 16;
        //while((UART0_S1 & UART0_S1_TDRE_MASK) == 0); //wait for the trasmit register to be empty (meaning the whole character has been sent)
    } while(tmp > 0);
 
    int i;
    for(i=cnt-1; i>=0; i--) {
        UART0_D = nums[i]; //put the next character in the transmit register & increment which character is next
        while((UART0_S1 & UART0_S1_TDRE_MASK) == 0); //wait for the trasmit register to be empty (meaning the whole character has been sent)
    }
}

void sendCode(int Code, int Data)
{
	//Assign a value to pin RS
	/*HINT: When RS is 1, then the LCD receives a data
	when RS is 0, then the LCD receives an instruction */
	// Initialise RS and Enable with 0
	RS_0;
	Enable_0;
	//Assign the value we want to send to the LCD
	PortLCD = Data;	
	
	//We make the algorithm to establish if its an instruction we start with 0 on RS value, otherwise if its a data command we start with RS as 1;
	
	if (Code == nIns)
	{
		RS_0;
		Enable_1;
		delay(n40useg);
		Enable_0;
		RS_0;
	}
	else if(Code == nData)
	{
		RS_1;
		Enable_1;
		delay(n40useg);
		Enable_0;
		RS_0;
	}
}

void initLCD(void)
{
	unsigned int i;											/* local index */
	//LCD requires a delay of 15 msec
	delay(n15mseg);									/* wait for 15 mseg */
	
	/* send initialization instructions */
	/* Loop for sending each character from the array */
	for(i=0;i<5;i++)
	{										
		sendCode(nIns, InitializeLCD[i]);	/* send initialization instructions */
					
	}

}

void delay(long time)
{
	/*@description: 
	*/
	//Initiate time
	long x;
	x = time;
	
	//Execute loop as long as x is not zero
	while (x != 0)
		{
		//Decrease x
		x--;
		}
}


//quickSendNum(B1);
//quickSend((unsigned char*)c);

//Valor  = B1;
//Dece = Valor/ 100;
//Residuo  = Valor % 100;
//Unid = Residuo / 10;
//Residuo1 = Residuo % 10;
//Deci = Residuo1 ;

unsigned char uart0_getchar (void)
{
/* Warten bis Charakter empfangen wurde */
while (!(UART0_S1 & UART_S1_RDRF_MASK));
/* Return the 8-bit data from the receiver */
return UART0_D;
}

void uart0_putchar (char data)
{
/* Warten bis Speicher verfügbar im FIFO */
while(!(UART0_S1 & UART_S1_TDRE_MASK));
/* Send the character */
UART0_D = data;
}
