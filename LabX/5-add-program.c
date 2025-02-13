#include <stdio.h>

int add(int *a, int *b, int *c) {
	int sum = *a + *b + *c;
	return sum;
}

int main(void) {
	int a=1;
	int b=2;
	int c=3;
	
	printf("%d + %d + %d = %d\n", a, b, c, add(&a, &b, &c));
	
	return 0;
}

