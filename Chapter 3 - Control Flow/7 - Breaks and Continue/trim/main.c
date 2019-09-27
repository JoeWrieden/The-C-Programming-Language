#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int trim(char s[]);

int main() {
    char s[MAXLEN] ="hello              ";
    printf("untrimmed string = %s.\n", s);
    trim(s);
    printf("trimmed string = %s.", s);
    return 0;
}

/* remove all trailing blanks tabs and newlines */
int trim(char s[]){
    int n;

    for (n = strlen(s)-1; n >=0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] !='\n')
            break;
    s[n+1] = '\0';
    return n;

}