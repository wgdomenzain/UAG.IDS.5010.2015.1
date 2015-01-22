/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */

//prototype declaration
void cfgPorts (void);
int calculateAverage(int age1, int age2, int age3);

int main(void)
{
	int counter = 0;
	
	cfgPorts();
	counter = calculateAverage(1,2,3);
	
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}
void cfgPorts(void)
{
	
}
int calculateAverage(int age1, int age2, int age3)
{
	return 1;
}
int calculatePromedio(int age1, int age2, int age3)
{
	int x;
	x = (age1+age2+age3)/3;
	return x;
//Alan De Miguel García
}

