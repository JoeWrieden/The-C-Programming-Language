#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void reversex(char s[]);
void itob(int n, char s[], int b);


int main() {

    char s[MAXLEN];
    int n, b;

    n = 37;
    b = 2;

    itob(n, s, b);
    printf("number %d in base %d = %s", n, b, s);

    return 0;
}

void itob(int n, char s[], int b){
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    int c, b2;
    b2 = b;
    do {
            s[i++] = digits[n % b];
            n /=b;
        }while (n > 0);
    reversex(s);
}

void reversex(char s[]){
    int c, i, j;

    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}