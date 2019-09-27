#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getlinex(char line[], int max);
int strindex(char source[], char searchfor[]);
void reversex(char s[]);


int main() {
    char parent[] = "aaZZaaaZZaaZa";
    char child[] = "aaZ";
    int found = 0;
    int i;

    i = strindex(parent, child);

    printf("%d", i);

    return 0;
}

int strindex(char s[], char t[]){
    int i, j, k, m = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            m = i;
    }
    return m;
}
