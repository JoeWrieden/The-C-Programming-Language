#include <stdio.h>
#include <stdlib.h>  /* for atof */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);


/* reverse polish calculator */
int main(){
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch (type){
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop() , op2));
                else
                    printf("error: division by zero\n");
                break;
            case '#':
                showtop();
                break;
            case '~':
                swaptop();
                break;
            case '?':
                duplicate();
                break;
            case '@':
                clearstack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command%s\n", s);
                break;
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
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c, d;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-'){
        d = getch();
        if (d == ' ')
            return c;
        else
            ungetch(d);
    }
    i = 0;
    if (isdigit(c) || c == '-')
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
/* get a possibly pushed back character */
int  getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
