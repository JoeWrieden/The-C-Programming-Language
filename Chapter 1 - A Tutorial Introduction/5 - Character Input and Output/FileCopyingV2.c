#include <stdio.h>

/* copy input to output; 2nd Version */
int main(){

	int c;

	while ((c = getchar()) != EOF)
		putchar(c);

	return 0;
}