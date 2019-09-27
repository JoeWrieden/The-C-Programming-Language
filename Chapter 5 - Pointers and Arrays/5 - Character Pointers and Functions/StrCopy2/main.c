#include <stdio.h>

void strcpyp(char *, char *);

int main() {
    char oldp[] = "Hello World";
    char newp[50];
    strcpyp(newp, oldp);
    printf("%s\n", newp);
    return 0;
}

void strcpyp(char *s, char *t){
    while ((*s++ = *t++))
        ;
}