#include <stdio.h>
#include <string.h>
#include <limits.h>



#define MAXLEN 100

void itoa(int n, char s[]);
void reversex(char s[]);

int main() {
    int n = 123456;
    char s[MAXLEN];

    itoa(INT_MIN, s);

    printf("integer = %d\nstring = %s\n", INT_MIN, s);

    return 0;
}

void itoa(int n, char s[]){
    int i, sign;
    unsigned int n2;

    if ((sign = n) < 0) /* record sign */
        n2 = -n;
    else
        n2 = n;
    i = 0;
    do {
        s[i++] = n2 % 10 + '0';
    }while ((n2 /=10) > 0);
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