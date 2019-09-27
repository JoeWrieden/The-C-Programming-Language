#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 500

int getlinex(char *, int);
int atoi(char *);
char *itoa(int, char *);
void reverse(char *);
int strindex(char *, char *);
int getop(char *);
void concat(char *, char *);

int main() {

/* getlinex
    char s[MAXLEN];
    while ((getlinex(s, MAXLEN)) > 0)
    printf("%s", s);
*/

/* atoi
    printf("%d", atoi("12345"));
*/

/* itoa
    int n = 54321;
    char s2[MAXLEN];
    itoa(n, s2);
    printf("%s", itoa(n, s2));
*/

/* strindex
    char s3[] = "Hello World";
    char s4[] = "World";
    printf("%d", strindex(s3, s4));
*/

/* getop
    char s5[MAXLEN];
    getop(s5);
    printf("%s", s5);
*/

/* concat
    char s5[MAXLEN] = "Hello ";
    char *s6 = "World!";
    concat(s6, s6);
    printf("Concated string: %s", s5);
*/

    return 0;
}

int getlinex(char *s, int lim){
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return i;
}

int atoi(char *s){
    int n, sign;
    while (*s == ' ' || *s == '\t')
        s++;
    sign = (*s == '-')? -1 : 1;
    if (*s == '-' || *s == '+')
        s++;
    for (n = 0; isdigit(*s);) {
        n = 10 * n + (*s - '0');
        s++;
    }
    return sign * n;
}

char *itoa(int n, char *s){
    int sign;
    char *p = s;
    if ((sign = n)< 0)
        n = -n;

    do {
        *p = n % 10 + '0';
        p++;
    }while ((n /= 10) > 0);
    if (sign < 0)
        *p = '-';
    reverse(s);
    return s;

}

void reverse(char *s) {
    char *p;
    int temp;
    p = s;
    while (*p){
        p++;
    }
    p--;
    while (s < p){
        temp = *s;
        *s = *p;
        *p = temp;
        s++;
        p--;

    }
}

int strindex(char *s, char *t) {
    int i, j, k;
    for (i = 0; *(s + i) != '\0'; i++){
        for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++);
    if (k > 0 && *(t + k) == '\0')
        return i;
    }
    return -1;
}

int getop(char *s){
    int c;

    while ((*s = c = getchar()) == ' ' || c == '\t')
        ;
    *(++s) = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    --s;
    if (isdigit(c))
        while(isdigit(*(++s) = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(*(++s) = c = getchar()))
            ;
    *s = '\0';
    return '0';
}

void concat(char *s, char *t){
    while (*s)
        s++;
    while((*s++ = *t++) != '\0')
        ;
}