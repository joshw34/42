#include <stdio.h>

int main(){

	int a = 10;
	int b = 10;
	int c = 10;
	int d = 10;
	int e = 10;

	a = a+=2;
	b = b-=5;
	c = c*=5;
	d = d/=5;
	e = e%=2;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("d = %d\n", d);
	printf("e = %d\n", e);

	return 0;

}


