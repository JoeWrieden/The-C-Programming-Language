#include <stdio.h>

void printd(int);

int main(){
    int i = 32472;

    printd(i);

    printf("%s", s);

    return 0;
}

void printd(int n){
    if (n < 0){
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n/10);
    puchar(n % 10 + '0');
}