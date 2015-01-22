/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include <stdio.h>

void cfgporTs(void);
int calculateAverage(int age1,int age2,int age3);
float calculateIMC(float altura,float peso);
int main(void)
{
	//prototype declaration
	int counter = 0;
	cfgporTs();
	counter = calculateAverage(1,2,3);
	
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}
void cfgporTs(void){
	
}
int calculateAverage(int age1,int age2,int age3){
	int avg=0;
	
	
	avg = (age1+age2+age3)/3;
	
	return avg;
	
}
float calculateIMC(float altura,float peso){
	
	return 0;
}
