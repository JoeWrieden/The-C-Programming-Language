#include <stdio.h>
#define swap(t, x, y) t temp; temp = x; x = y; y = temp;

int main(){
    int x = 6;
    int y = 7;
    swap(int, x, y);
    printf("x: %d y: %d",x,y);
}