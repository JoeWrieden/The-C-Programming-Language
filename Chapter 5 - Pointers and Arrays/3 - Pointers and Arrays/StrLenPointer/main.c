#include <stdio.h>

int strlen(char *);

int main() {
    char array[] = "This sentence is forty characters long x";
    char *ptr = "123456789";
    printf("1: %d, 2: %d, 3: %d", strlen("Hello World"), strlen(array), strlen(ptr));
    return 0;
}

int strlen(char *s){
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}