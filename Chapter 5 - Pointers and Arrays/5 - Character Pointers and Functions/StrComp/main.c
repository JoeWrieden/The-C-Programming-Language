#include <stdio.h>

int strcmpa(char *, char *);
int strcmpp(char *, char *);

int main() {
    char onea[] = "Hello World";
    char twoa[] = "Hello world";
    char onep[] = "Joe Wrieden";
    char twop[] = "Joe Wriedez";

    printf("Array: %d\nPointer: %d", strcmpa(twoa, onea), strcmpp(twop, onep));
    return 0;
}

int strcmpa(char *s, char *t){
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int strcmpp(char *s, char *t){
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}