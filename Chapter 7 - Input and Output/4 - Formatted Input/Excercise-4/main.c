#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minscanf(char *fmt, ...){
    va_list ap;
    char *p;
    int *ival;

    va_start(ap, fmt);

    for (p = fmt; *p; p++){
        if (p != '%')
            continue;
        
        switch(*++p){
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            default:
                break;
        }
    }
}

int main(){
    int i;

    minscanf("%d", &i);
    printf("Scanned in: %d\n", i);

    return 0;
}