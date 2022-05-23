#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int xor(int v[100], int n) {

}

int main() {
	int n, i, v[100];
	FILE *f;

	printf("Introduceti numarul de elemente din vector: ");
	scanf("%d", &n);

	printf("Introduceti elementele vectorului:\n");
	for (i = 0; i < n; i++) {
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}

	return 0;
}
