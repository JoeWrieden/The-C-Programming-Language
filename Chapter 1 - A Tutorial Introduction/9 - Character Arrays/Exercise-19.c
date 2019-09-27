#include <stdio.h>
#define MAXLINE 1000

int getlinex(char line[], int maxline);
void reverse(char n[]);

int main(){

	int len;

	char line[MAXLINE];
	char reversed[MAXLINE];

	while((len = getlinex(line, MAXLINE)) > 0){
		if (len > 1){
			reverse(line);
			printf("%s\n", line);
		}
	}
	return 0;
}

int getlinex(char s[], int lim){

	int c, i;

	for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	s[i] = '\0';

	return i;
}

void reverse(char s[]){

	int i, j;
	char temp;

	for (j = 0; s[j] != '\0'; ++j)
		;
	--j;

	for (i = 0; i<j; ++i){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		--j;

	}
}