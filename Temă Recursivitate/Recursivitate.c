#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int nr_inv = 0, baza = 1;

int suma_cifre(int n) {
	if (n == 0) return 0;
	else return (n % 10 + suma_cifre(n / 10));
}

int Manna_Pnueli(int n) {
	if (n >= 12) return n - 1;
	else return Manna_Pnueli(Manna_Pnueli(n + 2));
}

int cmmdc(int a, int b) {
	if (b != 0) return cmmdc(b, a % b);
	else return a;
}

int inv_cifre(int n) {
    if (n > 0) {
        inv_cifre(n / 10);
        nr_inv += (n % 10) * baza;
        baza *= 10;
    }
    return nr_inv;
}

int main() {
	int n, a, b, opt;
	do {
		printf("\n0. Exit\n");
		printf("1. Calcul suma cifrelor unui numar\n");
		printf("2. Calcul functie Manna-Pnueli\n");
		printf("3. Calcul Cmmdc(a, b)\n");
		printf("4. Inversarea cifrelor unui numar\n");
		printf("Alegeti o optiune: ");
		scanf("%d", &opt);

		switch (opt) {
			case 0: exit(0);

			case 1:
				printf("n = ");
				scanf("%d", &n);
				printf("\nsuma_cifre(%d) = %d\n", n, suma_cifre(n));
				break;

			case 2:
				printf("n = ");
				scanf("%d", &n);
				printf("\nf(%d) = %d\n", n, Manna_Pnueli(n));
				break;

			case 3:
				printf("a = ");
				scanf("%d", &a);
				printf("b = ");
				scanf("%d", &b);
				printf("\nCmmdc(%d, %d) = %d\n", a, b, cmmdc(a, b));
				break;

			case 4:
				printf("n = ");
				scanf("%d", &n);
				printf("\ninv_cifre(%d) = %d\n", n, inv_cifre(n));
				break;

			default: printf("Optiune gresita!");
				break;
		}

	} while (1);

	return 0;
}
