#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MASKA 0x1

#define TYP 				0xFF

#define ROZMIAR 				0x7F00
#define P_ROZMIAR       		8

#define WYROWNANIE      		0x18000	
#define P_WYROWNANIE      		15

#define WYTLUSZCZENIE 		0x20000
#define KURSYWA 				0x40000
#define PODKRESLENIE 			0x80000

void pokaz_czcionke(unsigned long c);
void menu(void);
void pokaz_binar(unsigned long liczba);

int main(void)
{
	unsigned long czcionka = 0;
	char opcja;
	unsigned long pom;
	bool flaga = 0;

	czcionka |= (1 & TYP);
	czcionka |= (12 << P_ROZMIAR & ROZMIAR);

	pokaz_czcionke(czcionka);
	menu();
	while (!flaga && scanf("%c", &opcja))
	{
		while (getchar() != '\n')
			continue;

		switch(opcja)
		{
			case 'T':
			case 't':
			{
				printf("Podaj typ czcionki: ");
				if (scanf("%lu", &pom))
				{
					czcionka &= ~TYP;
					czcionka |= pom & TYP;
				}

				while (getchar() != '\n')
					continue;

				break;
			}

			case 'R':
			case 'r':
			{
				printf("Podaj rozmiar czcionki (0 - 127): ");
				if (scanf("%lu", &pom))
				{
					czcionka &= ~ROZMIAR;
					czcionka |= (pom << P_ROZMIAR) & ROZMIAR;
				}

				while (getchar() != '\n')
					continue;

				break;
			}

			case 'W':
			case 'w':
			{
				printf("Wybierz wyrownanie: ");
				if (scanf("%lu", &pom))
				{
					czcionka &= ~WYROWNANIE;
					czcionka |= (pom << P_WYROWNANIE) & WYROWNANIE;
				}

				while (getchar() != '\n')
					continue;

				break;
			}

			case 'B':
			case 'b':
			{
				czcionka ^= WYTLUSZCZENIE;
				break;
			}

			case 'I':
			case 'i':
			{
				czcionka ^= KURSYWA;
				break;
			}

			case 'U':
			case 'u':
			{
				czcionka ^= PODKRESLENIE;
				break;
			}

			case 'K':
			case 'k':
			{
				printf("Koniec!\n");
				flaga = 1;
				break;
			}

			default: break;
		}

		if (!flaga)
		{
			system("clear");
			pokaz_czcionke(czcionka);
			menu();
		}
	}

    return 0;
} 

void pokaz_czcionke(unsigned long c)
{
	char wyr[7];

	if (((c & WYROWNANIE) >> P_WYROWNANIE) == 0)
		strcpy(wyr, "lewo");
	else if (((c & WYROWNANIE) >> P_WYROWNANIE) == 1)
		strcpy(wyr, "srodek");
	else if (((c & WYROWNANIE) >> P_WYROWNANIE) == 2)
		strcpy(wyr, "prawo");

	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "Typ", "Rozmiar", "Wyrownanie", "Wytl.", "Kurs.", "Podkr.");
	printf("%-10lu %-10lu %-10s %-10s %-10s %-10s\n", c & TYP, (c & ROZMIAR) >> P_ROZMIAR, wyr, (c & WYTLUSZCZENIE) != WYTLUSZCZENIE ? "wy" : "wl", 
												   (c & KURSYWA) != KURSYWA ? "wy" : "wl", (c & PODKRESLENIE) != PODKRESLENIE ? "wy" : "wl");
}

void menu(void)
{
	printf("t) zmiana czcionki  r) zmiana rozmiaru  w) zmiana wyrownania\n");
	printf("b) przelacz Bold    i) przelacz Italic  u) przelacz Underline\n");
	printf("k) wyjscie\n");
}

void pokaz_binar(unsigned long liczba)
{
	unsigned int r = 32;

	char tab[r + 1];

	for (int i = r - 1; i >= 0; i--, liczba >>= 1)
		tab[i] = '0' + (liczba & MASKA);

	tab[r] = '\0';

	for (int i = 0; i < r; i++)
	{
		putchar(tab[i]);

		if (i == 11) putchar(' ');
		else if (i == 12) putchar(' ');
		else if (i == 13) putchar(' ');
		else if (i == 14) putchar(' ');
		else if (i == 16) putchar(' ');
		else if (i == 23) putchar(' ');
	}

	putchar('\n');
}
