#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100


enum { NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int getch(void);
void ungetch(int);


int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name [MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
char buf[BUFSIZE];
int bufp = 0;


int main() {

    while(gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

void dcl(void){
    int ns;

    for (ns = 0; gettoken() == '*';)
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, "pointer to");
}

void dirdcl(void){
    int type;

    if (tokentype == '('){
        dcl();
        if (tokentype != ')')
            printf("Error: missing )\n");
    }else if (tokentype == NAME)
        strcpy(name, token);
    else
        printf("Error: expected name or dcl\n");
    while ((type =gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, "functions returning");
        else{
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

int gettoken(void){
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)){
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

/* get a possibly pushed back character */
int  getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters");
    else
        buf[bufp++] = c;
}