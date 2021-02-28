#include <stdio.h>

#define MASKA 0x1

int sprawdz_bit(int liczba, int nr);

int main(void)
{
	int liczba = 5;
	int nr_bitu = 0;

	printf("Bit o numerze %d wynosi %d\n", nr_bitu, sprawdz_bit(liczba, nr_bitu));

    return 0;
} 

int sprawdz_bit(int liczba, int nr)
{
	int licznik = 0;

	while (licznik++ != nr)
		liczba >>= 1;

	return liczba & MASKA;
}