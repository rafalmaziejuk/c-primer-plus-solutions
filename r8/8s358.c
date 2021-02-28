#include <stdio.h>
#include <stdlib.h>

char pobierz_wybor(void);
char pobierz_pierwszy(void);
float pobierz_float(void);
void menu(void);

int main(void)
{
	int opcja;

	while (opcja = pobierz_wybor())
	{
		switch (opcja)
		{
			case 'a':
			{
				float liczba1, liczba2;

				printf("Podaj pierwsza liczbe: ");
				liczba1 = pobierz_float();

				printf("Podaj druga liczbe: ");
				liczba2 = pobierz_float();
				
				printf("%.2f + %.2f = %.2f\n", liczba1, liczba2, liczba1 + liczba2);

				break;
			}

			case 'b':
			{
				float liczba1, liczba2;

				printf("Podaj pierwsza liczbe: ");
				liczba1 = pobierz_float();

				printf("Podaj druga liczbe: ");
				liczba2 = pobierz_float();

				printf("%.2f - %.2f = %.2f\n", liczba1, liczba2, liczba1 - liczba2);

				break;
			}

			case 'c':
			{
				float liczba1, liczba2;

				printf("Podaj pierwsza liczbe: ");
				liczba1 = pobierz_float();

				printf("Podaj druga liczbe: ");
				liczba2 = pobierz_float();

				printf("%.2f * %.2f = %.2f\n", liczba1, liczba2, liczba1 * liczba2);

				break;
			}

			case 'd':
			{
				float liczba1, liczba2;

				printf("Podaj pierwsza liczbe: ");
				liczba1 = pobierz_float();

				printf("Podaj druga liczbe: ");
				liczba2 = pobierz_float();

				while (liczba2 == 0)
				{
					printf("Podaj liczbe inna niz 0.\n");
					liczba2 = pobierz_float();
				}

				printf("%.2f / %.2f = %.2f\n", liczba1, liczba2, liczba1 / liczba2);
				
				break;
			}

			case 'k':
			{
				printf("Koniec.\n");
				exit(0);
			}

			default: break;
		}

		while (getchar() != '\n')
			continue;
	}

	return 0;
}

char pobierz_wybor(void)
{
	int ch;

	menu();

	ch = pobierz_pierwszy();

	while ((ch < 'a' || ch > 'd') && ch != 'k')
	{
		printf("Wpisz a, b, c, d lub k!\n");
		ch = pobierz_pierwszy();
	}

	return ch;
}	

char pobierz_pierwszy(void)
{
	int ch;

	ch = getchar();

	while (getchar() != '\n')
		continue;

	return ch;
}

float pobierz_float(void)
{
	float we;
	char ch;

	while (scanf("%f", &we) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);

		printf(" nie jest liczba.\n");
	}

	return we;
}

void menu(void)
{
	printf("Wybierz jedno z dzialan\n");
	printf("a. dodawanie                  b. odejmowanie\n");
	printf("c. mnozenie                   d. dzielenie\n");
	printf("k. koniec\n");
}