#include <stdio.h>


void shellsort(int v[], int n);

int main() {

    int i;
    int intarray[] = {5,3,8,1,4,76,88,9,23,34,12};

    printf("unsorted = %d",intarray[i]);
    for (i = 1; i <11; ++i)
        printf(", %d",intarray[i]);

    shellsort(intarray, 12);
    i = 0;
    printf("\nsorted  =  %d", intarray[i]);
    for (i = 1; i <11; ++i)
        printf(", %d",intarray[i]);

    return 0;
}

void shellsort(int v[], int n){
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap/= 2)
        for(i = gap; i < n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j+gap];j-=gap){
                temp = v[ j ];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }

}