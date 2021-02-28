#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROZMIAR 20
#define MAX 10

void menu(void);
void wyswietl(char *tab[], unsigned int ilosc);
void sortowanie_ASCII(char *tab[], unsigned int ilosc);
void sortowanie_dlugosc(char *tab[], unsigned int ilosc);
void sortowanie_slowo(char *tab[], unsigned int ilosc);
int dlugosc_slowa(char *lancuch);

int main(void)
{
	char lancuchy[MAX][ROZMIAR];
	char *wsk[MAX];
	int opcja;
	int licznik = 0;

	puts("Wprowadzaj lancuchy (pusty wiersz konczy wprowadzanie)");
	while (licznik != MAX && fgets(*(lancuchy + licznik), ROZMIAR, stdin) != NULL && lancuchy[licznik][0] != '\n')
	{
		int dlugosc = strlen(lancuchy[licznik]);
		lancuchy[licznik][dlugosc - 1] = '\0';

		wsk[licznik] = lancuchy[licznik];

		licznik++;
	}

	menu();
	while (scanf("%d", &opcja))
	{
		while (getchar() != '\n')
			continue;

		switch(opcja)
		{
			case 1:
			{
				wyswietl(wsk, licznik);

				break;
			}

			case 2:
			{
				sortowanie_ASCII(wsk, licznik);

				puts("Lista wedlug ASCII");
				wyswietl(wsk, licznik);

				break;
			}

			case 3:
			{
				sortowanie_dlugosc(wsk, licznik);

				puts("Lista wedlug dlugosci lancucha");
				wyswietl(wsk, licznik);

				break;
			}

			case 4:
			{
				sortowanie_slowo(wsk, licznik);

				puts("Lista wedlug dlugosci slowa");
				wyswietl(wsk, licznik);

				break;
			}

			case 5: exit(0);

			default: break;
		}

		menu();
	}

	return 0;
}

void menu(void)
{
	printf("\n");

	puts("1. Wyswietl liste w pierwotnej kolejnosci.");
	puts("2. Wyswietl liste w porzadku ASCII.");
	puts("3. Wyswietl liste wedlug dlugosci lancuchow.");
	puts("4. Wyswietl liste wedlug dlugosci pierwszego slowa.");
	puts("5. Koniec.");
	printf("Podaj wybor: ");
}

void wyswietl(char *tab[], unsigned int ilosc)
{
	printf("\n");

	for (int i = 0; i < ilosc; i++)
		puts(tab[i]);
}

void sortowanie_ASCII(char *tab[], unsigned int ilosc)
{
	char *pom;

	for(int i = 0; i < ilosc; i++)
		for(int j = 1; j < ilosc - i; j++)
			if (strcmp(tab[j - 1], tab[j]) > 0)
			{
				pom = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = pom;
			}
}

void sortowanie_dlugosc(char *tab[], unsigned int ilosc)
{
	char *pom;

	for(int i = 0; i < ilosc; i++)
		for(int j = 1; j < ilosc - i; j++)
			if (strlen(tab[j - 1]) > strlen(tab[j]))
			{
				pom = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = pom;
			}
}

void sortowanie_slowo(char *tab[], unsigned int ilosc)
{
	char *pom;

	for(int i = 0; i < ilosc; i++)
		for(int j = 1; j < ilosc - i; j++)
			if (dlugosc_slowa(tab[j - 1]) > dlugosc_slowa(tab[j]))
			{
				pom = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = pom;
			}
}

int dlugosc_slowa(char *lancuch)
{
	int licznik = 0;

	while (*lancuch != '\0')
	{
		if (isspace(*lancuch))
			return licznik;

		lancuch++;
		licznik++;
	}

	return licznik;
}
