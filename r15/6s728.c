#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MASKA 0x1

struct Czcionka
{
	unsigned int typ_czcionki     : 8;
	unsigned int rozmiar_czcionki : 7;
	unsigned int wyrownanie       : 2;
	bool         wytluszczenie    : 1;
	bool         kursywa          : 1;
	bool         podkreslenie     : 1;
};

void pokaz_czcionke(const struct Czcionka *c);
void menu(void);

int main(void)
{
	struct Czcionka czcionka = { 1, 12, 0, 0, 0, 0 };
	char opcja;
	unsigned int pom;
	bool flaga = 0;

	pokaz_czcionke(&czcionka);
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
				scanf("%u", &pom);

				while (getchar() != '\n')
					continue;

				czcionka.typ_czcionki = pom;

				break;
			}

			case 'R':
			case 'r':
			{
				printf("Podaj rozmiar czcionki (0 - 127): ");
				scanf("%u", &pom);

				while (getchar() != '\n')
					continue;

				czcionka.rozmiar_czcionki = pom;

				break;
			}

			case 'W':
			case 'w':
			{
				printf("Wybierz wyrownanie: ");
				scanf("%d", &pom);

				while (getchar() != '\n')
					continue;

				czcionka.wyrownanie = pom;
				
				break;
			}

			case 'B':
			case 'b':
			{
				czcionka.wytluszczenie ^= MASKA;
				break;
			}

			case 'I':
			case 'i':
			{
				czcionka.kursywa ^= MASKA;
				break;
			}

			case 'U':
			case 'u':
			{
				czcionka.podkreslenie ^= MASKA;
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
			pokaz_czcionke(&czcionka);
			menu();
		}
	}

    return 0;
} 

void pokaz_czcionke(const struct Czcionka *c)
{
	char wyr[7];

	if (c->wyrownanie == 0)
		strcpy(wyr, "lewo");
	else if (c->wyrownanie == 1)
		strcpy(wyr, "srodek");
	else if (c->wyrownanie == 2)
		strcpy(wyr, "prawo");

	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "Typ", "Rozmiar", "Wyrownanie", "Wytl.", "Kurs.", "Podkr.");
	printf("%-10u %-10u %-10s %-10s %-10s %-10s\n", c->typ_czcionki, c->rozmiar_czcionki, wyr, c->wytluszczenie == 0 ? "wy" : "wl", 
													c->kursywa == 0 ? "wy" : "wl", c->podkreslenie == 0 ? "wy" : "wl");
}

void menu(void)
{
	printf("t) zmiana czcionki  r) zmiana rozmiaru  w) zmiana wyrownania\n");
	printf("b) przelacz Bold    i) przelacz Italic  u) przelacz Underline\n");
	printf("k) wyjscie\n");
}
