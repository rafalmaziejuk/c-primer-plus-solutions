#include <stdio.h>

#define WYNAGRODZENIE 40
#define PODATEK15 0.15
#define PODATEK20 0.20
#define PODATEK25 0.25

int main(void)
{
	int godziny, suma;
	int pom;
	float podatek;

	printf("Podaj ilosc przepracowanych godzin w tygodniu: ");
	scanf("%d", &godziny);

	if (godziny > 40)
	{
		suma = 40 * WYNAGRODZENIE;
		godziny -= 40;
		suma += godziny * WYNAGRODZENIE * 1.5;
	}
	else suma = godziny * WYNAGRODZENIE;

	if (suma > 0 && suma <= 1200)
		podatek = suma * PODATEK15;
	else if (suma > 1200 && suma <= 1800)
	{
		pom = suma;
		podatek = 1200 * PODATEK15;
		suma -= 1200;
		podatek += 600 * PODATEK20;
	}
	else if (suma > 1800)
	{
		pom = suma;
		podatek = 1200 * PODATEK15;
		suma -= 1200;
		podatek += 600 * PODATEK20;
		suma -= 600;
		podatek += suma * PODATEK25;
	}

	printf("Wynagrodzenie brutto: %d\nPodatek: %.2f\nWynagrodzenie netto: %.2f\n", pom, podatek, pom - podatek);

	return 0;
}