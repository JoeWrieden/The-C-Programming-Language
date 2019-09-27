#include <stdio.h>
#define MAXLEN 100

int binsearch(int x, int v[], int n);


int main() {

    int nums[MAXLEN] = {1,4,6,8,9,11,13,15,18,24,25,28,30,31,35,36,38,40,'\0'};
    int i, numtofind;

    numtofind = 24;
    while (nums[i++] != '\0')
        ;
    printf("%d",binsearch(numtofind, nums, i));

}

int binsearch(int x, int v[], int n){

    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high){
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; /* found match */
    }
    return -1; /* no match */
}