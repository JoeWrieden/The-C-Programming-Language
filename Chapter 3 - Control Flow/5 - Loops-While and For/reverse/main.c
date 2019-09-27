#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int getlinex(char s[], int lim);
void reversex(char s[]);

int main() {
    char s[MAXLEN];
    getlinex(s, MAXLEN);

    printf("original = %s\n", s);
    reversex(s);
    printf("reversed = %s\n", s);

    return 0;
}

int getlinex(char s[], int lim){

    int c, i;

    for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;


    s[i] = '\0';

    return i;
}

void reversex(char s[]){
    int c, i, j;

    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}