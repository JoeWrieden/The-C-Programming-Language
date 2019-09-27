#include <stdio.h>

int htoi(char s[]);
int ishexx(int x);


int main(){

	int n;
	char hexstring[1000];
	hexstring[0] = 'a';
	hexstring[1] = 'B';
	hexstring[2] = '1';
	hexstring[3] = '2';
	hexstring[4] = '\0';

	n = htoi(hexstring);

	printf("the hex string: %s as an integer is %d",hexstring, n);

	return 0;
}

int htoi(char s[]){

	int i, n, l;

	n = 0;
	for (i = 0; (l = ishexx(s[i])) > 0; ++i){
		if (l == 1)
			n = 16 * n + (s[i] -'0');
		else if (l == 2)
			n = 16 * n +(10 + (s[i] - 'a'));
		else if (l == 3)
			n = 16 * n +(10 + (s[i] - 'A'));
	}
	return n;
}

int ishexx(int x){
	if (x >= '0' && x <= '9')
		return 1;
	else if (x >= 'a' && x <= 'z')
		return 2;
	else if (x >= 'A' && x <= 'Z')
		return 3;
	else
		return 0;
}