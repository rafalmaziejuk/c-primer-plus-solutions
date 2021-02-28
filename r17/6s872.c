#include <stdio.h>
#include <stdbool.h>

#define ROZMIAR 10

bool wyszukiwanie_binarne(const int tab[], int n, int cel);

int main(void)
{
	int tab[ROZMIAR] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int liczba = 5;

	printf("%d %s sie w tablicy.\n", liczba, wyszukiwanie_binarne(tab, ROZMIAR, liczba) ? "zawiera" : "nie zawiera");

   	return 0;
}

bool wyszukiwanie_binarne(const int tab[], int n, int cel)
{
	int rozmiar = n;
	int srodek = rozmiar / 2;

	if (tab[srodek] == cel)
		return true;
	
	if (rozmiar == 1)
		return false;
	
	if (tab[srodek] < cel)
	{
		srodek += 1;
		rozmiar -= srodek;
	}
	else if (tab[srodek] > cel)
	{
		rozmiar = srodek;
		srodek = 0;
	}
	
	wyszukiwanie_binarne(tab + srodek, rozmiar, cel);
}
