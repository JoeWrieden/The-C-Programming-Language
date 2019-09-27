#include <stdio.h>

#define MAXLINE 1000

int getlinex(char line[], int maxline);
void copy(char to[], char from[]);

int main(){

	int len;
	char line[MAXLINE];
	char fixedline[MAXLINE];

	while((len = getlinex(line, MAXLINE)) > 0){
		copy(fixedline, line);
		printf("%s\n",fixedline);
	}

	return 0;
}

int getlinex(char s[],int lim){

	int c, i, last;

	for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
		if (c != ' ' && c != '\t')
			last = i;
	}

	s[last + 1] = '\0';

	return i;
}

void copy(char to[], char from[]){

	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}