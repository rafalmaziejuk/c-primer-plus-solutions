
#include <stdio.h>

int main(void)
{
	double sekundy = 3.156e7;
	int wiek;

	printf("Podaj swoj wiek: ");
	scanf("%d", &wiek);

	printf("Twoj wiek w sekundach: %e\n", wiek * sekundy);

	return 0;
}
