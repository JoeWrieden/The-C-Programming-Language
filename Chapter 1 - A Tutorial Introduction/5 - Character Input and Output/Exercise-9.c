#include <stdio.h>

int main(){

	int c, d;

	while ((c = getchar()) != EOF)
		if (c == ' '){
			putchar(c);
			while ((c = getchar()) == ' ')
				;
			putchar(c);
		}
		else
			putchar(c);

	return 0;
}
