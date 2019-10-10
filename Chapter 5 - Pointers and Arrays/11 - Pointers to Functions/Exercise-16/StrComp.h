#define MAXLINES 5000

int readlines(char *lineptr[], int nlines);
int getlinex(char *, int);
void writelines(char *lineptr[], int nlines);

void swap(void *v[], int, int);
void qsortx(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
void reversex(char *);
int mystrcmp(char *, char *);