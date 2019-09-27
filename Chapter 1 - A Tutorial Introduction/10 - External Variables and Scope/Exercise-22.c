#include <stdio.h>

#define MAXLINE 1000
#define FOLDLEN 70

int getlinex(char line[], int maxline);

int main(){

	int len, i;
	char line[MAXLINE];
	int sectionlength;

	i = 0;
	while ((len = getlinex(line, MAXLINE)) > 0){
		while (len > (i + FOLDLEN)){
			i = i + FOLDLEN;
			while (line[i] != ' ')
				--i;
			line[i] = '\n';;
		}
		if (len > 0){
			printf("%s", line);
			i = 0;
		}
	}
	return 0;
}

int getlinex(char line[], int lim){

	int c, i;

	for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}