/* 
  * main implementation: use this 'C' sample to create your own application 
  * 
  */ 
 #include "derivative.h" /* include peripheral declarations */ 
 #define portB GPIOB_PDOR 

void cfgPorts(void); 
void apagarLeds(void);
void Retardo(long miliseg); 
 


 int main(void) 
{ 
 	cfgPorts(); 
 	apagarLeds(); 
	 
	for(;;) //FOR INFINITO
	{	    
		portB = 0xFFFBFFFF; // 0xFFFBFFFF ROJO
		Retardo(2500000); //
		apagarLeds(); 
		Retardo(2500000); 
		portB = 0xFFF7FFFF; // 0xFFF7FFFF VERDE
		Retardo(2500000); 
		apagarLeds(); 
 		Retardo(2500000); 
 		GPIOD_PDOR = 0xFFFFFFFD; // 0xFFFFFFFD AZUL
 		Retardo(2500000); 
		apagarLeds(); 
 		Retardo(2500000); 
 		 
 	} 
 	 
 	return 0; 
 } 
 
 
 void apagarLeds(void) 
 { 
 	portB = 0xFFFFFFFF; // PORT B ROJO Y VERDE
 	GPIOD_PDOR = 0xFFFFFFFF; // PORT D AZUL
 } 

 void Retardo(long miliseg) 
  { 
  	do 
  	{ 
 		miliseg=miliseg -1; 
  	} 
 	while(miliseg!=0); 
 	 
  } 

 void cfgPorts(void)
 {  	 	  
	 SIM_SCGC5 =  SIM_SCGC5_PORTB_MASK;
	 SIM_SCGC5 |=  SIM_SCGC5_PORTA_MASK; 
	 SIM_SCGC5 |=  SIM_SCGC5_PORTD_MASK;
	 	
	 //ACTIVA EL MODO DEL PIN 
	 PORTB_PCR18 = PORT_PCR_MUX(1);// 1 es el modulo de la tabla la clumna de funcionalidad
	 PORTB_PCR19 = PORT_PCR_MUX(1);
	 PORTD_PCR1  = PORT_PCR_MUX(1);// MODO 1
	 
	 
	 //CONFIGURE PORT B AS OUTPUT           para encontrar lo siguiente buscar capitulo GPIO
 	GPIOB_PDDR= 0xFFFFFFFF; 
 	GPIOD_PDDR= 0xFFFFFFFF; 
 } 
 
 
 
