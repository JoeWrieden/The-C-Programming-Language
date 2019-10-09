#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrComp.h"

char *lineptr[MAXLINES];


/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0, reverse = 0;

    if (argc > 1 && (strcmp(argv[1], "-n") || strcmp(argv[2], "-n")) == 0)
        numeric = 1;
    if (argc > 1 && (strcmp(argv[1], "-r") || strcmp(argv[2], "-r")) == 0)
        reverse = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsortx((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) (numeric ? numcmp : strcmp));
        if (reverse == 1)
            reversex(lineptr);

        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsortx(void *v[], int left, int right, int (*comp)(void *, void *)){
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsortx(v, left, last-1, comp);
    qsortx(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2){
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void reversex(char *s){
    int c, i, j;

    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
}