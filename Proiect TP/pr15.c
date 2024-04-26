// C program to find minimum
// number of denominations
#include <stdio.h>
#define K 10
#define MAX 100

// All denominations of Indian Currency
int tranz[K] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

void citire_sume(int n, int s[100]) {
	int i;

	printf("\nIntroduceti sumele necesare pentru virat:\n");
	for (i = 0; i < n; i++) {
		printf("s[%d] = ", i);
		scanf("%d", &s[i]);
	}

	printf("\nSumele necesare pentru virat sunt: ");
	for (i = 0; i < n; i++) printf("%d ", s[i]);
}

void vir_min(int sal)
{
    int S[MAX] = { 0 };
    int i, k = 0;

    for (i = K - 1; i >= 0; i--) {
        while (sal >= tranz[i]) {
            sal -= tranz[i];
            // Add coin in the list
            S[k++] = tranz[i];
        }
    }

    for (i = 0; i < k; i++) {
        // Print
        printf("%d ", S[i]);
    }
    return;
}

int main()
{
	int n, k, s[100], i;// j, m = 0;//, x = 0;
	printf("Introduceti numarul de angajati: ");
	scanf("%d", &n);
	printf("Introduceti numarul k: ");
	scanf("%d", &k);
	citire_sume(n, s);
	for (i = 0; i < n; i++) {
		printf("\nFollowing is minimal number of change for %d: ", s[i]);
		vir_min(s[i]);
	}
    return 0;
}
