/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
//Modificado por Daniel Sànchez Ramírez 

int avg(int x, int y, int z);
int main(void)
{
	int counter = 0;
	
	
	counter = avg(2, 2, 2);
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}
int avg(int x, int y, int z){
	
	int prom;
	
	prom = (x+y+z)/3
	return prom; 
}
