#include <stdio.h>

#define MAXLINE 1000

int getlinex(char line[], int maxline);
void ridcomments(char to[], char from[], int start, int end, int len);

int main(){

	int len, i, j, t;
	t = 0;
	char line[MAXLINE];
	char fixedline[MAXLINE];
	while ((len = getlinex(line, MAXLINE)) > 0){

		if (len > 0)
			printf("%s\n", line);
	}

	return 0;
}

int getlinex(char s[], int lim){

	int c, d, i, success;

	for (i = 0; i < (lim -1) && (c = getchar())!= EOF; ++i && c !=  '\n'){
		success = 0;
		s[i] = c;
		if ((c == '/') && (d = getchar()) == '*')
			while ((c = getchar()) != '/' && success == 0)
				if (c == '*')
					if ((c = getchar()) == '/')
						success = 1;
		s[i] = c;
	}
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';


	return i;
}

void ridcomments(char to[], char from[], int start, int end, int len){

	int x, y, z;
	z = 0;

	for (x = 0; x < start; ++x){
		to[z] = from[x];
		++z;
	}
	for (y = end; y <= len; ++y){
		to[z] = from[y];
		++z;
	}

}