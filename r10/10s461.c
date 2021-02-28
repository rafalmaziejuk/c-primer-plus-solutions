#include <stdio.h>

#define ROZMIAR 5

void przypisanie(const int tab1[], const int tab2[], int suma[], int rozmiar);
void wyswietl_tab(const int tab[], int rozmiar);

int main(void)
{
	int tab1[ROZMIAR] = { 1, 2, 3, 4, 5 };
	int tab2[ROZMIAR] = { 6, 7, 8, 9, 10 };
	int suma[ROZMIAR];

	printf("TABLICA PIERWSZA\n");
	wyswietl_tab(tab1, ROZMIAR);

	printf("TABLICA DRUGA\n");
	wyswietl_tab(tab2, ROZMIAR);

	przypisanie(tab1, tab2, suma, ROZMIAR);

	printf("SUMA TABLIC\n");
	wyswietl_tab(suma, ROZMIAR);

	return 0;
}

void przypisanie(const int tab1[], const int tab2[], int suma[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		suma[i] = tab1[i] + tab2[i];
}

void wyswietl_tab(const int tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		printf("%d ", tab[i]);

	putchar('\n');
	putchar('\n');
}
