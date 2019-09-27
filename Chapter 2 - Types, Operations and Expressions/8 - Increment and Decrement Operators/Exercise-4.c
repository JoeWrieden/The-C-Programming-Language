#include <stdio.h>

void delsqueeze(char s1[], char s2[]);

int main(){

	char s1[1000];
	char s2[1000];

	s1[0] = 'a';
	s1[1] = 's';
	s1[2] = 't';
	s1[3] = 'a';
	s1[4] = 'b';
	s1[5] = 'o';
	s1[6] = 'c';
	s1[7] = 'b';
	s1[8] = 'p';
	s1[9] = 'a';
	s1[10] = '\0';

	s2[0] = 'a';
	s2[1] = 'b';
	s2[2] = 'c';
	s2[3] = '\0';

	printf("%s\n", s1);
	delsqueeze(s1, s2);
	printf("%s", s1);

	return 0;
}




void delsqueeze(char s1[], char s2[]){

	int i, c;
	int x,y;
	for (i = 0; (c = s2[i]) != '\0'; ++i){
		for (x = y = 0; s1[x] != '\0'; x++)
			if (s1[x] != c)
				s1[y++] = s1[x];
		s1[y] = '\0';
	}
}
	