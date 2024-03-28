#include <stdio.h>

/* memory = an array of bytes within RAM (street)
   memory block = a single unit (byte) within memory (house), used to hold some value (person)
   memory address = the address of where a memory block is located (house address) */

int main(){

	char a;
	char b[1];

	printf("%d bytes\n", sizeof(a));
	printf("%d bytes\n", sizeof(b));

	/* Mem addrs are hexadecimal: 1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
	   %p = pointer address
	   chars= 1 byte (addrs diff by one here */

	printf("%p\n", &a);
	printf("%p\n", &b);
	
	return 0;

}
