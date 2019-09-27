#include <ctype.h>
#include <stdio.h>

#define SIZE 100
#define BUFSIZE 100

int bufp = 0;
char buf[BUFSIZE];

int getch(void);
void ungetch(int);

int main(){
    int i ,n;
    double array[SIZE], getint(double *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    for (i = 0; i < n; ++i)
        printf("%g\n", array[i]);
}


/* getint: get next integer from input to *pn */
double getint(double *pn) {
    int c, sign, power;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn = sign * *pn / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

int  getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters");
    else
        buf[bufp++] = c;
}