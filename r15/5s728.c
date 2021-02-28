#include <stdio.h>

#define MASKA 0x1

void pokaz_binar(unsigned int liczba);
unsigned int rozmiar(unsigned int liczba);
unsigned int obroc_1(unsigned int liczba, int ilosc);

int main(void)
{
	unsigned int x = 1;

	printf("Liczba przed obroceniem: ");
	pokaz_binar(x);

	x = obroc_1(x, 1);
	
	printf("Liczba po obroceniu: ");
	pokaz_binar(x);

    return 0;
} 

unsigned int rozmiar(unsigned int liczba)
{
	unsigned int licznik = 0;

	while (liczba != 0)
	{
		licznik++;
		liczba >>= 1;
	}

	return licznik;
}

void pokaz_binar(unsigned int liczba)
{
	unsigned int r = rozmiar(liczba);

	char tab[r + 1];

	for (int i = r - 1; i >= 0; i--, liczba >>= 1)
		tab[i] = '0' + (liczba & MASKA);

	tab[r] = '\0';

	puts(tab);
}

unsigned int obroc_1(unsigned int liczba, int ilosc)
{
	unsigned int r = rozmiar(liczba);
	unsigned int bit = liczba;

	while (ilosc-- > 0)
	{
		bit >>= r - 1;
		liczba <<= 1;
		liczba &= ~(MASKA << r);

		if ((bit & MASKA) == MASKA)
			liczba |= MASKA;

		bit = liczba;
	}

	return liczba;
}