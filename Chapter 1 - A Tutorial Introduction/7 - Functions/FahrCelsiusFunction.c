#include <stdio.h>

#define STEP 20

float fahrconvert(int n);

int main(){

	int fahr;

	printf("Fahr Celsius\n");
	for (fahr = 0; fahr <= 300; fahr = fahr + STEP)
		printf("%4d %6.1f\n", fahr, fahrconvert(fahr));

	return 0;
}

float fahrconvert(int fahr){

	float celsius;

	celsius = (5.0/9.0)*(fahr - 32);

	return celsius;

}