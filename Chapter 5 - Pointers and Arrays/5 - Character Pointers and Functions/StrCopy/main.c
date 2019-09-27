#include <stdio.h>

void strcpya(char *, char *);
void strcpyp(char *, char *);

int main() {
    char olda[] = "Hello World";
    char oldp[] = "Nice to meet you";
    char newa[50];
    char newp[50];
    strcpya(newa, olda);
    strcpyp(newp, oldp);
    printf("%s\n%s", newa, newp);
    return 0;
}

void strcpya(char *s, char *t){
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void strcpyp(char *s, char *t){
    while ((*s = *t) != '\0'){
        s++;
        t++;
    }
}