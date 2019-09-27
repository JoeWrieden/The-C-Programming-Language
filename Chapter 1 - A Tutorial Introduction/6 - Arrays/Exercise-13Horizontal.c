#include <stdio.h>

int main(){

	int c, l, i, x;
	int words[10];
	l = 0;

	for (i = 0; i < 10; ++i)
		words[i] = 0;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			++words[l];
			l = 0;
		}
		else
			++l;
	}		
	++words[l];
	for (i = 0; i <= 10; ++i){
		printf("%2d",i);
		for (x = 0; x < words[i]; ++x)
			putchar('*');
		printf("\n");
	}
	return 0;
}