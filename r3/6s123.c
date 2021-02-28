#include <stdio.h>

int main(void)
{
	double czasteczki = 3.0e-23;
	int objetosc;

	printf("Podaj objetosc wody w litrach: ");
	scanf("%d", &objetosc);

	objetosc *= 1000;

	printf("Liczba czasteczek wody: %e\n", objetosc / czasteczki);

	return 0;
}
