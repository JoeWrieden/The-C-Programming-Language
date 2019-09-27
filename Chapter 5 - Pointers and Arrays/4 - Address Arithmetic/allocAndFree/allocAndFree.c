
#define ALLOCSIZE 1000 /*size of availiable space */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int);
void afree(char *);

char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){ /* it fits */
        allocp +=n;
        return allocp - n; /* old p */
    }
    else /* not enough space */
        return 0;
}

void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}