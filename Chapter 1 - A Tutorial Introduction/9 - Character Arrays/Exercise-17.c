#include <stdio.h>

#define BIGENOUGH 80
#define MAXLINE 1000

int getlinex(char line[], int maxline);

int main(){

	int len;
	char line[MAXLINE];

	while ((len = getlinex(line, MAXLINE)) > 0)
		if (len > BIGENOUGH){
			printf("%s\n", line);

		}

	return 0;
}

int getlinex(char s[], int lim){

	int c, i;

	for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	
	if (c == '\n'){
		s[i] = c;
		++i;
	}

	return i;
}