#include <stdio.h>

int anyx(char s1[], char s2[]);

int main(){

	char s1[1000];
	char s2[1000];
	int h;

	s1[0] = 'b';
	s1[1] = 'e';
	s1[2] = 'c';
	s1[3] = 'a';
	s1[4] = 'u';
	s1[5] = 's';
	s1[6] = 'e';
	s1[7] = '\0';

	s2[0] = 'z';
	s2[1] = 's';
	s2[2] = 't';
	s2[3] = 'c';
	s2[4] = '\0';

	h = anyx(s1, s2);
	printf("first occurence is at: %d",h);
	
	return 0;
}

int anyx(char s1[], char s2[]){

	int i, c;
	int x,y;
	for (i = 0; s1[i] != '\0'; ++i){
		for (x = 0; (c = s2[x]) != '\0'; x++)
			if (s1[i] == c)
				return (i+1);
	}
	return -1;
}
