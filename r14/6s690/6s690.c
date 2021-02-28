#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plik.h"

#define MAX 19

void pokaz(const struct Zawodnik z[], int n);

int main(void)
{
	FILE *we;
	struct Zawodnik tab[MAX];
	int index;
	int pom;

	for (int i = 0; i < MAX; i++)
	{
		tab[i] = (struct Zawodnik)
		{
			"", "",
			0, 0, 0, 0, 0, 0
		};
	}

	if ((we = fopen("druzyna.txt", "r")) == NULL)
	{
		fprintf(stderr, "Nie udalo sie otworzyc pliku!\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(we, "%d", &index) != EOF)
	{
		tab[index].nr_gracza = index;

		fscanf(we, "%s", tab[index].imie);
		fscanf(we, "%s", tab[index].nazwisko);

		fscanf(we, "%d", &pom);
		tab[index].oddane += pom;

		fscanf(we, "%d", &pom);
		tab[index].trafione += pom;

		fscanf(we, "%d", &pom);
		tab[index].asysty += pom;

		fscanf(we, "%d", &pom);
		tab[index].faule += pom;
		
		tab[index].skutecznosc = (float)tab[index].trafione / (float)tab[index].oddane;
	}

	pokaz(tab, MAX);

	if (fclose(we) != 0)
	{
		fprintf(stderr, "Nie udalo sie zamknac pliku!\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}

void pokaz(const struct Zawodnik z[], int n)
{
	int oddane, trafione, asysty, faule;

	oddane = trafione = asysty = faule = 0;

	for (int i = 0; i < n; i++)
	{
		if (strcmp(z[i].imie, "") != 0)
		{
			printf("\nNumer: %d - %s %s %d %d %d %d\n", i, z[i].imie, z[i].nazwisko, z[i].oddane, z[i].trafione, z[i].asysty, z[i].faule);
			printf("Skutecznosc: %.2f\n\n", z[i].skutecznosc);
		}

		oddane += z[i].oddane;
		trafione += z[i].trafione;
		asysty += z[i].asysty;
		faule += z[i].faule;
	}
		
	printf("Statystki zbiorcze\n");
	printf("Oddane: %d  Trafione: %d  Asysty: %d  Faule: %d  Skutecznosc: %.2f\n", oddane, trafione, asysty, faule, (float)trafione / (float)oddane);
}