/*
 * Marco Antonio Angel Pérez
 * 
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

//prototype declaration
void cfgPorts(void);
float calculateAverage(int age1,int age2,int age3);


int main(void)
{
	int counter = 0;
	float average;
	cfgPorts();
	
	average=calculateAverage(1,2,3);
	average+1-1;
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}

void cfgPorts(void)
{
	


}

float calculateAverage(int age1,int age2,int age3)
{
	float average;
	average = (age1+age2+age3)/3;
	
	
	return average;
}
