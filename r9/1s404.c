#include <stdio.h>

double min(double x, double y);

int main(void)
{	
	double a = 2.2;
	double b = 1.2;

	printf("a = %.1f  b = %.1f\n", a, b);
	printf("Mniejsza jest %.1f\n", min(a, b));

	return 0;
}

double min(double x, double y)
{
	return x < y ? x : y;
}