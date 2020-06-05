#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int compLine(FILE *, FILE *, int);

int main(int argc, char *argv[]){
    if (argc < 3)
        printf("Usage: %s <file1> <file2>", argv[0]);
    
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    while(compLine(fp1, fp2, MAXLEN)){
        ;
    }
    return 0;
}

int compLine(FILE *fp1, FILE *fp2, int max){
    char line1[max];
    char line2[max];

    if (fgets(line1, max, fp1) == NULL)
        return 0;
    if (fgets(line2, max, fp2) == NULL)
        return 0;
    if (strcmp(line1, line2) != 0){
        printf("Difference at lines:\nFile1: %sFile2: %s\n", line1, line2);
        return 0;
    }
    return strlen(line1);

}