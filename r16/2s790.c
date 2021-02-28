#include <stdio.h>

#define SREDNIA(x, y) 2 / ((1 / x) + (1 / y))

int main(void)
{
	double a, b;

	a = 1.2;
	b = 32.5;

	printf("Srednia harmoniczna %.1f i %.1f wynosi %.2f.\n", a, b, SREDNIA(a, b));

	return 0;
}