#include <stdio.h>
#include <string.h>

int strend(char *, char *);
int strcmpp(char *, char *);

int main() {
    char strone[] = "Hello World";
    printf("Correct: %d\nWrong: %d\n", strend(strone, "World"), strend(strone, "Egg"));
    return 0;
}

int strend(char *s, char *t){
    int i = strlen(s) - strlen(t);
    for (int n = 0; n < i; n++){
        s++;
    }
    return strcmpp(s, t);
}

int strcmpp(char *s, char *t){
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 1;
    return 0;

}