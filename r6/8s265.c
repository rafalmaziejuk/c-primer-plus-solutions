#include <stdio.h>

int main(void)
{
	float a, b;

	printf("Podaj dwie liczby zmiennoprzecinkowe: ");
	
	while (scanf("%f %f", &a, &b) == 2)
	{
		float roznica = a - b;
		float iloczyn = a * b;

		printf("%.2f\n", roznica / iloczyn);

		printf("Podaj dwie liczby zmiennoprzecinkowe: ");
	}

	return 0;
}
