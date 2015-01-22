/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
//Este codigo fue modificado por Carlos Alejandro "Java" Payan Castellanos
int promedio(int uno,int dos,int tres);

int main(void)
{
	int counter = 0;
	
	counter=promedio(1,2,3);
	
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}

int promedio(int uno,int dos,int tres)
{
	int total=0;
	total=uno+dos+tres;
	total=total/3;

	return total;
}
