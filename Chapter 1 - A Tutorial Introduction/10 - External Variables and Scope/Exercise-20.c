#include <stdio.h>

#define SPACELEN 4

void detab(int x);

int main(){

	int c, i, x;
	x = 0;
	while((c = getchar()) != EOF){
		if (c == '\t'){
			detab(x);
			x = 0;
		}
		else if (c == '\n'){
			putchar(c);
			x = 0;
		}
		else{
			putchar(c);
			++x;
		}
	}
	return 0;
}
void detab(int x){

	int w,t ;
	w = x;

	if (w > SPACELEN){
		while (w > SPACELEN)
			w = w - SPACELEN;
	}
	if (w == SPACELEN)
		for (t = 0; t < SPACELEN; ++t)
			putchar(' ');
	else{
		for (t = 0; t < (SPACELEN - w); ++t)
			putchar(' ');
	}

}