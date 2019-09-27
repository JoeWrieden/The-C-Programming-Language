#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atof(char s[]);
int getlinex(char s[], int lim);

int main() {
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (getlinex(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;

}

double atof(char s[]){
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}
int getlinex(char s[], int lim){

    int c, i;

    for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
