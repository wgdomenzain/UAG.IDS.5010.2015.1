#include "derivative.h" /* include peripheral declarations */

#define portB GPIOB_PDOR
#define portD GPIOD_PDOR

void cfgPorts(void);
void retardo(long ms);
void apagarPuertoB(void);
void apagarPuertoD(void);


int main(void)
{
	cfgPorts();
	apagarPuertoB();
	apagarPuertoD();
	
	for(;;) {	  
		//prende  rojo
		portB = 0xFFFBFFFF;
		retardo(2100000);
		//tiempo apagado
		apagarPuertoB();
		retardo(2100000);
		
		//prende verde
		portB = 0xFFF7FFFF;
		retardo(2100000);
		//tiempo apagado
		apagarPuertoB();
		retardo(2100000);
		
		//prende azul
		portD = 0xFFFFFFFD;
		retardo(2100000);
		//tiempo apagado
		apagarPuertoD();
		retardo(2100000);
		
	}
	
	return 0;
}
void retardo(long ms){
	do
	{
		ms--;
	}
	while(ms!=0);
	
}
void apagarPuertoB(void)
{
	portB = 0xFFFFFFFF; // apagar leds rojo y verde
}
void apagarPuertoD(void)
{
	portD = 0xFFFFFFFF; // apagar led azul
}

void cfgPorts(void)
{
	//Activar Reloj Puerto A, B y D
	SIM_SCGC5 = SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// Activar pines como GPIO
	PORTB_PCR18= PORT_PCR_MUX(1);
	PORTB_PCR19= PORT_PCR_MUX(1);
	PORTD_PCR1= PORT_PCR_MUX(1); 
	
	
	// Configurar direccion como salida de los puertos
	GPIOB_PDDR= 0xFFFFFFFF;
	GPIOD_PDDR= 0xFFFFFFFF;
}
