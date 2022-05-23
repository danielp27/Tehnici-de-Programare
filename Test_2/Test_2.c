#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;

int xor(int v[100]) {
	int i, x = 0;
	for (i = 0; i < n; i++) {
		return xor (x ^= v[i]);
	}

}

int main() {
	int i, v[100];

	printf("Introduceti numarul de elemente din vector: ");
	scanf("%d", &n);

	printf("Introduceti elementele vectorului:\n");
	for (i = 0; i < n; i++) {
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}

	printf("\n%d", xor(v));

	return 0;
}
