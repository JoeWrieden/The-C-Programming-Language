#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tailx(char *[], int);
int numfind(char *[], int);

int main(int argc, char *argv[]) {
    int n = numfind(argv, argc);

    int c = argc - n;
    tailx(argv, c);
    return 0;
}

int numfind(char *s[], int p){
    while (*s){
        if (strcmp(*s,"-n") == 0){
            s++;
            int c = atoi(*s);
            if (c > (p - 2)) {
                printf("Too long defaulting length to 10\n");
                return 10;
            }
            return c;
            }
        else
            s++;
    }
    return 10;
}

void tailx(char *s[], int increment) {
    int i;

    for (i = 0; i < increment; ++i)
        s++;
    while (*s){
        printf("%s", *s);
        s++;
    }
}