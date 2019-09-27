#include <stdio.h>

#define MAXLEN 1000

void expand(char s1[], char s2[]);
int getlinex(char s[], int lim);

int main() {
    char s[MAXLEN];
    char v[MAXLEN];

    getlinex(s, MAXLEN);
    expand(s,v);

    printf("original = %s\nexpanded = %s", s, v);

    return 0;
}

void expand(char s1[], char s2[]) {
    char c, d;
    int i, j;
    i = j = 0;

    while ((c = s1[i++]) != '\0') {
        if (c != ' ' && s1[i] == '-' && s1[i + 1] != '\0') {
            i++;
            d = s1[i];
            if (d < c)
                while (c > d)
                    s2[j++] = c--;

            else
                while (c < d)
                    s2[j++] = c++;

        }
        else
            s2[j++] = c;
    }
    s2[j] = '\0';
}


int getlinex(char s[], int lim){

    int c, i;

    for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}