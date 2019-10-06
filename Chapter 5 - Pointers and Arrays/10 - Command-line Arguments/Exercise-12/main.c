#include <stdio.h>

void tailx(char *[], int, int);


int main(int argc, char *argv[]) {
    tailx(argv, 10, argc);
    return 0;
}

void tailx(char *s[], int n, int c) {
    int i;
    int increment = c - n;

    for (i = 0; i < increment; ++i)
        s++;
    while (*s){
        printf("%s", *s);
        s++;
    }
}