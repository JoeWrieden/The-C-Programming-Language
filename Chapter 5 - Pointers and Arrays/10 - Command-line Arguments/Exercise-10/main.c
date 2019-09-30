#include <stdio.h>
#include <stdlib.h>  /* for atof */
#include <ctype.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100


int sp = 0;
double val[MAXVAL];


void push(double);
double pop(void);

/* reverse polish calculator */
int main(int argc, char *argv[])
{
    int type;
    int c;
    double op1, op2, latest;
    while (--argc > 0)
    {
        ++argv;
        if (!isdigit(c = **argv) && strlen(*argv) == 1)
            type = c;
        else
            type = NUMBER;
        switch (type)
        {
            case NUMBER:
                push(atof(*argv));
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
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command: %c\n", type);
                break;
        }
    }
    latest = pop();
    printf("\t%.8g\n", latest);
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
