#include <stdio.h>

int main(void)
{
	float liczba;

	scanf("%f", &liczba);
	printf("Wpisano liczbe %.1f lub %.1e.\n", liczba, liczba);
	printf("Wpisano liczbe %+.3f lub %.3E.\n", liczba, liczba);

	return 0;
}
