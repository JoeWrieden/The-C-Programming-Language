#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getlinex(char *, int);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getlinex(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL){
                printf("%s", line);
                found++;
            }
    return 0;
}

int getlinex(char *s, int lim){
    int c, i;
    i = 0;

    while(--lim > 0 && (c= getchar()) != EOF && c != '\n') {
        *s = c;
        s++;
    }
    if (c == '\n') {
        *s = '\n';
        s++;
    }

    *s = '\0';
    return i;
}