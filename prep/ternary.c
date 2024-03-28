#include <stdio.h>

int findmax(int x, int y){

	return (x > y) ? x : y;

}

int main(){

	int max = findmax(13, 9);
	printf("%d", max);

	return 0;

}
