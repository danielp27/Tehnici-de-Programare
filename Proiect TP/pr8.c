#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Fibo(int n){
	int v[100], i;
	v[1] = 0; v[2] = 1;

	for(i = 3; i < n; i++)
		v[i] = v[i - 1] + v[i - 2];
   	return v[n];

}

int main() {
	int n;
	printf("Introduceti un numar: ");
	scanf("%d", &n);

	printf("Fibo(%d) = %d", n, Fibo(n));

	return 0;
}
