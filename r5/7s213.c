#include <stdio.h>

float szescian(float a);

int main(void)
{
	float liczba;

	printf("Podaj liczbe: ");
	scanf("%f", &liczba);
	printf("Szescian: %.2f\n", szescian(liczba));

	return 0;
}

float szescian(float a)
{
	return a * a * a;
}
