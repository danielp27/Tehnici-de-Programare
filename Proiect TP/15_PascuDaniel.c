#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000
#define S 10000000

// Functie pentru a citi salariile angajatiilor
void citire_sume(int n, int s[N]) {
	int i;

	printf("\nIntroduceti sumele necesare pentru virat (<= 10 000 000):\n");
	for (i = 0; i < n; i++) {
		printf("s[%d] = ", i);
		scanf("%d", &s[i]);
		while (s[i] > S) {
			printf("Suma este prea mare, introduceti alta: ");
			scanf("%d", &s[i]);
		}
	}

	printf("\nSumele necesare pentru virat sunt: ");
	for (i = 0; i < n; i++) printf("%d ", s[i]);
	printf("\n");
}

// Functie care afiseaza cum se pot oferi exact sumele de bani pentru toti angajati, astfel incat viramentele sa fie minime
void vir_min(int sal, int k) {
	int s[N] = {0}, i, j = 0, c, tranz[k];
	FILE *f2;
	f2 = fopen("sal.out", "at");

	for (c = 0; c <= k; c++) 	  		// Seteaza puterea maxima de 10 reprezentand tranzactiile disponibile cu care se vireaza banii in cont
		tranz[c] = pow(10, c);

	for (i = k; i >= 0; i--) {  	// Descompune sumele in puteri de 10 valide
		while (sal >= tranz[i]) {
			sal -= tranz[i];
			s[j++] = tranz[i];
		}

	}

	for (i = 0; i < j; i++) {			// Afiseaza sumele ca puteri de 10 valide
		printf("%d ", s[i]);
		fprintf(f2, "%d ", s[i]);
	}

	fclose(f2);
}


int main() {
	int n, k, s[N], i;
	FILE *f1;
	f1 = fopen("sal.in", "at");
	printf("Introduceti numarul de angajati (intre 1 si 100 000): ");
	scanf("%d", &n);
	while (n <= 0 || n > N) {
		printf("Nr. de angajati nu apartine intervalului, introduceti alt nr.: ");
		scanf("%d", &n);
	}
	while (n > 0 && n <= N) {
		printf("Introduceti un nr. k (intre 0 si 9): ");
		scanf("%d", &k);
		while (k < 0 || k > 9) {
			printf("k nu apartine intervalului, introduceti alt nr.: ");
			scanf("%d", &k);
		}
		fprintf(f1, "%d %d\n", n, k);
		while (k >= 0 && k <= 9) {
			citire_sume(n, s);

			for (i = 0; i < n; i++) {
				printf("\nNumarul minim de viramente posibile pentru %d: ", s[i]);
				vir_min(s[i], k);
				fprintf(f1, "%d ", s[i]);
			}
			break;
		}
		break;
	}

	fclose(f1);
	system("pause");
	return 0;
}
