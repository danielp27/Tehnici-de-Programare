#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Functie care verifica daca un numar este patrat perfect
int patrat_perf(int n) {
	int i, m = 0;

	for(i = 2; i <= n/2; i++) {
		if(n == i * i) {
			m = 1;
			break;
		}
	}
	return m;
}

// Functie care verifica daca un numar este un numar Fibonacci
int isFibo(int n){
	int m = 0;

	if(patrat_perf(5 * n * n + 4) == 1 || patrat_perf(5 * n * n - 4) == 1)
		m = 1;

	return m;
}

int main() {
	int n, i, m = 0;
	FILE *f1, *f2;
	printf("Introduceti un numar: ");
	scanf("%d", &n);

	f1 = fopen("in.txt", "wt");
	fprintf(f1, "%d", n);
	f2 = fopen("out.txt", "wt");

	printf("\n");
	for(i = 0; i < n; i++){
		if (isFibo(i) == 1){ 									// Verifica daca numerele de la 0 pana la n sunt numere Fibonacci
			if (isFibo(n - i) == 1){							// Verifica daca rezultatul scaderii fiecarui numar pana la n din n este un numar Fibonacci afland astfel operanzii sumei cerute
				if(i <= n - i) {								// Pune conditia ca sumele afisate sa fie distincte
					printf("%d = %d + %d\n", n, i, n - i);
					m = 1;
					fprintf(f2, "%d = %d + %d\n", n, i, n - i);
				}
			}
		}
	}

	// In cazul in care numarul nu poate fi scris ca suma de doi termeni ai sirului lui Fibonacci
	while (m == 0) {
		printf("%d nu poate fi scris ca suma de doi termeni ai sirului lui Fibonacci\nIntroduceti alt numar: ", n);
		scanf("%d", &n);
		printf("\n");
		for(i = 0; i < n; i++){
			if (isFibo(i) == 1){ 			// Verifica daca numerele de la 0 pana la n sunt numere Fibonacci
				if (isFibo(n - i) == 1){	// Verifica daca rezultatul scaderii fiecarui numar pana la n din n este un numar Fibonacci afland astfel operanzii sumei cerute
					if(n == 2) {
						printf("%d = %d + %d\n", n, i, n - i);
						m = 1;												// Pune conditia ca inafara de 2, niciun alt numar sa nu fie scris ca suma de doi operatori identici
						fprintf(f2, "%d = %d + %d\n", n, i, n - i);			// si ca sumele afisate sa fie distincte
					} else if(i <= n - i && i != n - i) {
						printf("%d = %d + %d\n", n, i, n - i);
						m = 1;
						fprintf(f2, "%d = %d + %d\n", n, i, n - i);
					}
				}
			}
		} break;
		break;
	}

	fclose(f1);
	fclose(f2);
	system("pause");
	return 0;
}
