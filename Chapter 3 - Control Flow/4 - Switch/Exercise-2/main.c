#include <stdio.h>
#define MAXLEN 1000

int getlinex(char s[], int lim);
void escape (char s[], char t[]);

int main() {
    char s[MAXLEN], t[MAXLEN] ;
    getlinex(s,MAXLEN);

    escape(s,t);
    printf("The unfiltered text %s\nThe filtered text %s",s,t);

    return 0;
}

int getlinex(char s[], int lim){

    int c, i;

    for (i = 0; i < (lim-1) && (c = getchar()) != EOF; ++i)
        s[i] = c;

    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void escape(char s[], char t[]){

    int i, j;
    i = 0;
    j = 0;
    while (s[i] != '\0'){
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                ++i;
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                ++i;
                break;
            default:
                t[j++] = s[i++];
                break;
        }
    }
}