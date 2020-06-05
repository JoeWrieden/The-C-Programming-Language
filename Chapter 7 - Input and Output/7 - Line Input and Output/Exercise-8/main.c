#include <stdio.h>
#include <stdlib.h>

#define LINESPERPAGE 10
#define TRUE 1
#define FALSE 0

void print_file(char *filename){
    FILE *fp;
    int page_number = 1;
    int line_count;
    int c;
    int newpage = TRUE;

    if ((fp = fopen(filename, "r")) != NULL){
        while((c = fgetc(fp)) != EOF){
            if (newpage){
                printf("%s, page %d starts\n", filename, page_number);
                newpage = FALSE;
                line_count = 1;
            }
            putchar(c);
            if (c == '\n' && ++line_count > LINESPERPAGE){
                printf("%s, page %d ends\n", filename, page_number);
                putchar('\n');
                page_number++;
                newpage = TRUE;
            }
        }
        if (!newpage){
            printf("\n%s, page %d ends\n", filename, page_number);
        }
        putchar('\n');
        fclose(fp);
    }
}


int main(int argc, char *argv[]){
    if (argc < 2){
        printf("Usage: %s <file> ...", argv[0]);
        exit(0);
    }
    for (int i = 1; i < argc; i++){
        print_file(argv[i]);
    }
    
    return 0;
}