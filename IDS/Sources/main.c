/*
 * main implementation: use this 'C' sample to create your own application
 * Author: Juan Abraham Porras
 */

#include "derivative.h" /* include peripheral declarations */

//prototype declaration
void cfgPorts(void);
int calculateAverage(int age1, int age2, int age3);

int main(void)
{
	int counter = 0;
	cfgPorts();
	counter = calculateAverage(1, 2, 3);
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}

void cfgPorts(void){
	
}

int calculateAverage(int age1, int age2, int age3){
	int avg = age1 + age2 + age3;
	avg = avg/3;
	return avg;
}
