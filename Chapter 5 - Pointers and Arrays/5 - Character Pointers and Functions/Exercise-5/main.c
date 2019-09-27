#include <stdio.h>

int strncmpp(char *, char *, int);
void strncpyp(char *, char *, int);
void strncatp(char *, char *, int);

int main() {
    char stringone[50] = "Hello World";
    char copystring[50];

    printf("Compared: %d\n", strncmpp(stringone, "Hello", 5));
    strncpyp(copystring, stringone, 7);
    printf("Copy: %s\n", copystring);
    strncatp(stringone, " Nice to meet you", 7);
    printf("Catted: %s\n", stringone);
    return 0;
}

int strncmpp(char *s, char *t, int n){
    int i = 1;
    for (; *s == *t && i <= n; s++, t++, i++)
        if (*s == '\0' || i == n)
            return 0;
    return *s - *t;
}

void strncpyp(char *s, char *t, int n){
    int i = 0;
    while ((*s++ = *t++) && i < n)
        i++;
}

void strncatp(char *s, char *t, int n){
    int i = 0;
    while (*s)
        s++;
    while ((*s++ = *t++) && i < n)
        i++;
}