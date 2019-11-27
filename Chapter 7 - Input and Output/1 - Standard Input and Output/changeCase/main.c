#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int c;

    if (strcmp(argv[1],"-u") == 0){
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    }
    else if (strcmp(argv[1], "-l") == 0 ){
        while((c = getchar()) != EOF)
            putchar(tolower(c));
    }
    else
        printf("Enter a case specifier -u for upper and -l for lower");
    return 0;
}