#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEM 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// return a == b; -> returneaza 1 sau 0 in functie de valoarea de adevar a expresiei

// funtie pentru verificare daca stiva e plina (poate contine maxim 100 de elemente)
int isStackFull(int size) {
	return size >= MAX_ELEM;			// daca marimea stivei este cel putin MAX_ELEM, atunci stiva e plina
}

// functie pentru verificare daca stiva e goala
int isStackEmpty(int size) {
	return size == 0;					// daca marimea stivei e 0 => nu are niciun element
}

// functie pentru afisarea continutului stivei
void printStack(int size, char *stack) {
	int i;
	if (isStackEmpty(size)) {
		printf("\nStack is empty!\n");
	}
	else {
		printf("\nPostfix form is: ");
		for (i = 0; i < (size); i++)
			printf("%c", stack[i]);
		printf("\n");
	}
}

// functie pentru adaugarea unui element in varful stivei (stiva e de tip char)
// valoarea variabilei size se poate modifica in interiorul functiei, asa ca transmitem variabila prin referinta
void push(int *size, char *stack, char valToAdd) {
	if (isStackFull(*size)) {
		printf("\nStack is full!\n");
	}
	else {
		stack[*size] = valToAdd;		// se adauga element in varful stivei
		(*size)++;						// se incrementeaza valoarea variabilei size (adica se actualizeaza pozitia varfului ca fiind cu una mai sus decat inainte)
	}
}

// functie pentru adaugarea unui element in varful stivei (stiva e de tip int)
// valoarea variabilei size se poate modifica in interiorul functiei, asa ca transmitem variabila prin referinta
void pushInt(int *size, int *stack, int valToAdd) {
	if (isStackFull(*size)) {
		printf("\nStack is full!\n");
	}
	else {
		stack[*size] = valToAdd;		// se adauga element in varful stivei
		(*size)++;						// se incrementeaza valoarea variabilei size (adica se actualizeaza pozitia varfului ca fiind cu una mai sus decat inainte)
	}
}

// functie pentru extragerea elementului din varful stivei de tip int (il "scoate" din stiva si il returneaza)
// valoarea variabilei size se poate modifica in interiorul functiei, asa ca transmitem variabila prin referinta
char pop(int *size, char *stack) {
	(*size)--;							// se decrementeaza valoarea variabilei size (practic se ignora valoarea din varful stivei, va fi la un moment dat suprascrisa de un push cu o alta valoare, si se actualizeaza varful ca fiind cu o pozitie mai jos)
	return stack[*size];			// se returneaza valoarea fostului varf al stivei (adica elementul extras)
}

// functie pentru extragerea elementului din varful stivei de tip char (il "scoate" din stiva si il returneaza)
// valoarea variabilei size se poate modifica in interiorul functiei, asa ca transmitem variabila prin referinta
int popInt(int *size, int *stack) {
	(*size)--;							// se decrementeaza valoarea variabilei size (practic se ignora valoarea din varful stivei, va fi la un moment dat suprascrisa de un push cu o alta valoare, si se actualizeaza varful ca fiind cu o pozitie mai jos)
	return stack[*size];			// se returneaza valoarea fostului varf al stivei (adica elementul extras)
}

//functie pentru "vizualizarea" elementuilui din varful stivei (nu il si scoate din stiva)
char getTop(int size, char *stack) {
	return stack[size - 1];
}

// functie pentru determinarea prioritatii operatorului/operandului dat ca parametru
int getPriority(char op) {
	switch (op) {
	case '(':
	case ')':
		return 0;
	case '*':
	case '/':
		return 1;
	case '+':
	case '-':
		return 2;
	default:
		return 3;
	}
}

// functie pentru realizare unui calcul
int calc(int a, int b, char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return -1;
	}
}

int max(int a, int b) {
	return (a > b ) ? a : b;
}

int min(int a, int b) {
	return (a < b ) ? a : b;
}

// st, fp, st_int -> stivele folosite, fp retinand forma poloneza finala
// size_st, size_fp, size_st_int -> retin marimea stivelor, st[size_st - 1] fiind elementul din varful stivei
int main() {
	char st[MAX_ELEM], fp[MAX_ELEM], buffer[MAX_ELEM], *input, op;
	int size_st = 0, size_fp = 0, length, priority, st_int[MAX_ELEM], size_st_int = 0, val, op1, op2;

	// citim expresia de la tastatura
	printf("Expresia este: ");
	fgets(buffer, MAX_ELEM, stdin);		// stdin -> standard input (tastatura)
	length = strlen(buffer);


	// stergem "new line"-ul de la finalul citirii
	if (buffer[length - 1] == '\n') {
		buffer[length - 1] = 0;
		length--;
	}

	// alocam spatiu pentru expresia citita si cele doua paranteze -> (E)
	input = (char *)malloc(sizeof(char) * (length + 3));
	strcpy(input, "(");
	strcat(input, buffer);
	strcat(input, ")");



	printStack(size_fp, fp);


}

// � Coralia Bodea, 2021
