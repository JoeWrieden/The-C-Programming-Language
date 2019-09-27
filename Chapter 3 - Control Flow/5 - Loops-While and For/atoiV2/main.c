#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

int atoix(char s[]);

int main() {

    char sint[MAXLEN] = {' ','-','1','2','3','4','5','6'};

    printf("%d", atoix(sint));

    return 0;
}

int atoix(char s[]){

    int i, n, sign;

    for (i = 0; isspace(s[i]);i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;

}