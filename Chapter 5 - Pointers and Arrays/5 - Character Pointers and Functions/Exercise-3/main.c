#include <stdio.h>

void strcatp(char *, char *);

int main() {
    char strOne[] = "Hello ";
    char strTwo[] = "World";
    strcatp(strOne, strTwo);
    printf("%s", strOne);
    return 0;
}

void strcatp(char *s, char *t){
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}