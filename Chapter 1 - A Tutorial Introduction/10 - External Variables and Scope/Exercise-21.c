#include <stdio.h>
#define SPACELEN 4

void entab(int x, int bc);

int main(){

	int c, i, x, bc;
	x = bc = 0;
	while((c = getchar()) != EOF){
		if (c == ' '){
			++bc;
			while ((c = getchar()) == ' ')
				++bc;
			entab(x, bc);
			putchar(c);
			bc = 0;
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
void entab(int x, int bc){

	if (x > SPACELEN)
		while(x > SPACELEN)
			x = x - SPACELEN;
	x = SPACELEN - x;
	while (bc - SPACELEN >= 0){
		if (x > 0){
			bc = bc - x;
			putchar('\t');
			x = 0;
		}
		else{
			bc = bc - SPACELEN;
			putchar('\t');


		}
	}
	while(bc > 0){
		putchar(' ');
		--bc;
	}

}