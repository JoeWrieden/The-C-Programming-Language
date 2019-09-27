#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTORE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *ls);
void writelines(char *lineptr[], int nlines);
int getlinex(char *, int);
void qsortx(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

int main() {
    int nlines; /* number of input lines read */
    char linestore[MAXSTORE];
    if ((nlines = readlines(lineptr, MAXLINES, linestore)) >= 0){
        qsortx(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *ls){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    p = ls + strlen(ls);
    while((len = getlinex(line, MAXLEN)) > 0){
        if (nlines >= maxlines ||(strlen(ls) + len) > MAXSTORE)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsortx(char *v[], int left, int right){
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsortx(v, left, last-1);
    qsortx(v, last+1, right);
}

void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getlinex(char s[], int lim){

    int c, i;

    for (i = 0; i < (lim-1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}