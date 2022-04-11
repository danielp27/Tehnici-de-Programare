#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned int oglindire_biti(unsigned int x){
	unsigned int y = 0;

	while(x > 0) {
		y <<= 1;
		if((x & 1) == 1)
			y ^= 1;
		x >>= 1;
	}

	return y;
}

int main() {
	unsigned int x;
	printf("Introduceti un numar intreg x: ");
	scanf("%d", &x);
	printf("y = %d", oglindire_biti(x));

	system('pause');
	return 0;
}
