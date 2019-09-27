#include <stdio.h>

#define MAXLINE 1000

enum boolean {NO, YES};

int getlinex(char s[], int lim);
void copy(char to[], char from[]);

int main(){

	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */

	max = 0;
	while ((len = getlinex(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s\n", longest);

	return 0;
}

int getlinex(char s[], int lim){

	int i, c, stop;
    i = 0;
    stop = NO;
    while (stop == NO) {
        stop = YES;
        if (i < lim - 1)
            if ((c = getchar()) != '\n')
                if (c != EOF) {
                    s[i] = c;
                    ++i;
                    stop = NO;
                }
    }
	if (c == '\n') {
        s[i] = c;
        ++i;
    }


	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]){

	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}