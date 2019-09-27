#include <stdio.h>

int main(){

	int lower, upper, step;
	float celsius, fahr;

	lower = -150;
	upper = 150;
	step = 20;

	celsius = lower;
	printf("%7s %10s\n","Celsius","Fahrenheit");
	while (celsius <= upper){
		fahr = (celsius * (9.0/5.0))+32.0;
		printf("%7.0f %7.2f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}