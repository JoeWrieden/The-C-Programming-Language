#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void itoa(int n, char s[]);
void reversex(char s[]);

int main() {
    int n = 123456;
    char s[MAXLEN];

    itoa(n, s);

    printf("integer = %d\nstring = %s\n", n, s);

    return 0;
}

void itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    }while ((n /=10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
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