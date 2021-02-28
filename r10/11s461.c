#include <stdio.h>

#define WIERSZ 3
#define KOLUMNA 5

void podwajanie(int tab[][KOLUMNA], int rzedy);
void wyswietlanie(const int tab[][KOLUMNA], int rzedy);

int main(void)
{
	int tab[WIERSZ][KOLUMNA] = 
	{
		{ 54, 35, 22, 16, 17 },
		{ 54, 31, 22, 15, 16 },
		{ 52, 37, 28, 19, 12 }
	};
	
	printf("TABLICA PRZED PODWOJENIEM\n");
	wyswietlanie(tab, WIERSZ);

	podwajanie(tab, WIERSZ);

	printf("\nTABLICA PO PODWOJENIU\n");
	wyswietlanie(tab, WIERSZ);

	return 0;
}

void podwajanie(int tab[][KOLUMNA], int rzedy)
{
	for (int i = 0; i < rzedy; i++)
		for (int j = 0; j < KOLUMNA; j++)
			tab[i][j] *= 2;
}

void wyswietlanie(const int tab[][KOLUMNA], int rzedy)
{
	for (int i = 0; i < rzedy; i++)
	{
		for (int j = 0; j < KOLUMNA; j++)
			printf("%d ", tab[i][j]);

		putchar('\n');
	}
}