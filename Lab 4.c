#include <stdio.h>

void func(int x) {
	x = 30;
}

int main() {
	int y = 20;
	func(y);
	printf("%d", y);
	return 0;
}
