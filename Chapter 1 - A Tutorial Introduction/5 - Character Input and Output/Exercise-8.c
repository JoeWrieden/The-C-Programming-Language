#include <stdio.h>

int main(){

	int c, nlc, tc, bc;
	nlc = tc = bc = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nlc;
		else if (c == '\t')
			++tc;
		else if (c == ' ')
			++bc;
	printf("Newlines:%d Tabs:%d Blanks:%d",nlc,tc,bc);

	return 0;
}