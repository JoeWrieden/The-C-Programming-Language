#include <stdarg.h>
#include <stdio.h>


void minprintf(char *fmt, ...){
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}

int main(int argc, char *argv[]){
    minprintf("Hello i am %s and i amd called %d\n" , "joe", 12);
    return 0;
}