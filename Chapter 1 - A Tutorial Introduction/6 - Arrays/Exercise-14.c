#include <stdio.h>

int main(){

	int c, i;

	int letters[26];
	for (i = 0; i < 26; ++i)
		letters[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= 'a' && c <= 'z')
			++letters[c - 'a'];

	for (i = 'a'; i <= 'z'; ++i){
		putchar(i);
		printf(": %d\n",letters[i - 'a']);
	}

	return 0;
}