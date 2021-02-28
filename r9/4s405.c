#include <stdio.h>

double srednia_harmoniczna(double a, double b);

int main(void)
{
	double a, b;
	a = 5.5;
	b = 6.2;

	printf("Srednia harmoniczna z liczb %.1f i %.1f to %.1f.\n", a, b, srednia_harmoniczna(a, b));

	return 0;
}

double srednia_harmoniczna(double a, double b)
{
	double odw_a, odw_b;
	odw_a = 1 / a;
	odw_b = 1 / b;

	double srednia;
	srednia = (odw_a + odw_b) / 2;

	return 1 / srednia;
}	