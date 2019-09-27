#include <stdio.h>
#include <string.h>

void reversex(char [], int, int);

int main() {
    char s[] = "Hello World";
    reversex(s, 0, strlen(s)-1);
    printf("%s", s);
    return 0;
}

void reversex(char s[], int start, int end) {
    int temp;
    if (start >= end);
    else {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        reversex(s, ++start, --end);
    }
}