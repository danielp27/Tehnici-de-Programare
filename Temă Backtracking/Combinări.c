#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100

#include <stdio.h>
#include <stdlib.h>

int i, k, n, m, j, v[MAX_SIZE];
char isS, isV = 0;

void Init(int k){ 	// k – vârful stivei
	v[k] = 0; 		//iniţializează/resetează, valoarea din
					// vârful stivei
}

int Succesor(int k){
	if (v[k] < n){ 	// se poate creşte valoarea din vârf
		v[k]++; 	// se incrementează valoarea din vârf
		return 1; 	// funcţia a avut success
	}
	else 			// nu se poate creşte valoarea din vârf
		return 0;
}

int Valid(k){
	for (i = 1; i < k; i++) // verifică dacă elementul din
		if (v[i] >= v[k])
			return 0; 		// vârf este diferit de
							// elemente precedente din stivă
	return 1;
}

int Solution(k){
	return (k == m);
}

void Print(){
	printf("%d) ",++j);

	for (i = 1; i <= m; i++)
		printf("%d ",v[i]);

	printf("\n");
}

void Back(int n){
	k=1; Init(k);
	while (k > 0){ // cât timp stiva nu e vidă
		isS = 0;isV = 0;
		if (k <= n) // nu face sens depăşirea nivelului n în stivă
			do{ // repetă cât timp...
				isS = Succesor(k);
				if (isS) isV = Valid(k);
			} while (isS && !isV); // ...există succesor dar nu este valid
		if (isS) //este succesor si este valid
			if (Solution(k)) // verifică candidatul la soluţie
				Print(); // afişează soluţia
			else { // dacă nu este soluţie
				k++; Init(k); // creşte vârful stivei şi iniţializează
			}
		else // nu există succesor pt. valoarea curentă din stivă
			k--; // -> se coboară o poziţie în stivă
	}
}

int main() {
	printf("Introduceti numarul de elemente din stiva: ");
	scanf("%d", &n);
	printf("\nIntroduceti numarul de combinari dorite: ");
	scanf("%d", &m);
	printf("\nCombinari de %d formate din numerele stivei:\n\n", m);
	Back(n);
	return 0;
}
