#include <stdio.h>

int strlenx(char *);

int main() {
    char array[] = "This sentence is forty characters long x";
    char *ptr = "123456789";
    printf("1: %d, 2: %d, 3: %d", strlenx("Hello World"), strlenx(array), strlenx(ptr));
    return 0;
}

int strlenx(char *s){
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}