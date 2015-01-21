/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */


void cfgporTs(void);
int calculateAverage(int age1,int age2,int age3);

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
	
	return 1;
	
}
