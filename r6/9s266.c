#include <stdio.h>

float funkcja(float a, float b);

int main(void)
{
	float a, b;

	printf("Podaj dwie liczby zmiennoprzecinkowe: ");
	
	while (scanf("%f %f", &a, &b) == 2)
	{
		printf("%.2f\n", funkcja(a, b));

		printf("Podaj dwie liczby zmiennoprzecinkowe: ");
	}

	return 0;
}

float funkcja(float a, float b)
{
	float roznica = a - b;
	float iloczyn = a * b;

	return roznica / iloczyn;
}
