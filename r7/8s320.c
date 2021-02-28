#include <stdio.h>
#include <stdlib.h>

#define WYNAGRODZENIE35 35
#define WYNAGRODZENIE37 37
#define WYNAGRODZENIE40 40
#define WYNAGRODZENIE45 45
#define PODATEK15 0.15
#define PODATEK20 0.20
#define PODATEK25 0.25

void menu(void);

int main(void)
{
	int opcja;

	menu();

	while (scanf("%d", &opcja) == 1)
	{
		int godziny, suma;
		int pom;
		float podatek;

		switch (opcja)
		{
			case 1:
			case WYNAGRODZENIE35:
			{
				printf("Podaj ilosc przepracowanych godzin w tygodniu: ");
				scanf("%d", &godziny);

				if (godziny > 40)
				{
					suma = 40 * WYNAGRODZENIE35;
					godziny -= 40;
					suma += godziny * WYNAGRODZENIE35 * 1.5;
				}
				else suma = godziny * WYNAGRODZENIE35;

				if (suma > 0 && suma <= 1200)
					podatek = suma * PODATEK15;
				else if (suma > 1200 && suma <= 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
				}
				else if (suma > 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
					pom -= 600;
					podatek += pom * PODATEK25;
				}

				printf("Wynagrodzenie brutto: %d\nPodatek: %.2f\nWynagrodzenie netto: %.2f\n", suma, podatek, suma - podatek);
				
				break;
			}

			case 2:
			case WYNAGRODZENIE37:
			{
				printf("Podaj ilosc przepracowanych godzin w tygodniu: ");
				scanf("%d", &godziny);

				if (godziny > 40)
				{
					suma = 40 * WYNAGRODZENIE37;
					godziny -= 40;
					suma += godziny * WYNAGRODZENIE37 * 1.5;
				}
				else suma = godziny * WYNAGRODZENIE37;

				if (suma > 0 && suma <= 1200)
					podatek = suma * PODATEK15;
				else if (suma > 1200 && suma <= 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
				}
				else if (suma > 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
					pom -= 600;
					podatek += pom * PODATEK25;
				}

				printf("Wynagrodzenie brutto: %d\nPodatek: %.2f\nWynagrodzenie netto: %.2f\n", suma, podatek, suma - podatek);

				break;
			}

			case 3:
			case WYNAGRODZENIE40:
			{
				printf("Podaj ilosc przepracowanych godzin w tygodniu: ");
				scanf("%d", &godziny);

				if (godziny > 40)
				{
					suma = 40 * WYNAGRODZENIE40;
					godziny -= 40;
					suma += godziny * WYNAGRODZENIE40 * 1.5;
				}
				else suma = godziny * WYNAGRODZENIE40;

				if (suma > 0 && suma <= 1200)
					podatek = suma * PODATEK15;
				else if (suma > 1200 && suma <= 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
				}
				else if (suma > 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
					pom -= 600;
					podatek += pom * PODATEK25;
				}

				printf("Wynagrodzenie brutto: %d\nPodatek: %.2f\nWynagrodzenie netto: %.2f\n", suma, podatek, suma - podatek);
				
				break;
			}

			case 4:
			case WYNAGRODZENIE45:
			{
				printf("Podaj ilosc przepracowanych godzin w tygodniu: ");
				scanf("%d", &godziny);

				if (godziny > 40)
				{
					suma = 40 * WYNAGRODZENIE45;
					godziny -= 40;
					suma += godziny * WYNAGRODZENIE45 * 1.5;
				}
				else suma = godziny * WYNAGRODZENIE45;

				if (suma > 0 && suma <= 1200)
					podatek = suma * PODATEK15;
				else if (suma > 1200 && suma <= 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
				}
				else if (suma > 1800)
				{
					pom = suma;
					podatek = 1200 * PODATEK15;
					pom -= 1200;
					podatek += 600 * PODATEK20;
					pom -= 600;
					podatek += pom * PODATEK25;
				}

				printf("Wynagrodzenie brutto: %d\nPodatek: %.2f\nWynagrodzenie netto: %.2f\n", suma, podatek, suma - podatek);

				break;
			}

			case 5:
			{
				printf("Koniec!\n");
				exit(0);
			}

			default: break;
		}
		
		menu();
	}

	return 0;
}

void menu(void)
{
	printf("Podaj liczbe odpowiadajaca zadanej stawce wynagrodzenia lub opcji\n");
	printf("1) 35 zl/godz.                  2) 37 zl/godz\n");
	printf("3) 40 zl/godz.                  4) 45 zl/godz\n");
	printf("5) wyjscie\n");
}
