#include <stdio.h>
#include <stdlib.h>  /* for atof */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char line[BUFSIZE];
int line_n = 0;

int getop(char []);
void push(double);
double pop(void);
int getlinex(char [], int);

/* reverse polish calculator */
int main(){
    int type;
    double op2;
    char s[MAXOP];

    while ((getlinex(line, BUFSIZE)) != 0) {
        line_n = 0;
        while ((type = getop(s)) != '\0') {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command%s\n", s);
                    break;
            }
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push (double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cant push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void){
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;

    while ((s[0] = c = line[line_n++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[line_n++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[line_n++]))
            ;
    s[i] = '\0';
    line_n --;
    return NUMBER;
}

int getlinex(char s[], int lim){
    int i = 0;
    int c;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;

}