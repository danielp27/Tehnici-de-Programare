#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int isStackFull(int size) {
	return size >= MAX_SIZE;
}

int isStackEmpty(int size) {
	return size == 0;
}

void printStack(int size, int* stack) {
	int i;
	if (isStackEmpty(size)) {
		printf("\nStack is empty!\n");
	}
	else {
		printf("\nStack is: ");
		for (i = 0; i < (size); i++)
			printf("%d ", stack[i]);
		printf("\n");
	}

}

void push(int* size, int* stack, int valToAdd) {
	if (isStackFull(*size)) {
		printf("\nStack is full!\n");
	}
	else {
		stack[*size] = valToAdd;
		(*size)++;
	}
}

int pop(int* size, int* stack) {
	(*size)--;
	return stack[*size];
}


int main() {

	return 0;
}
