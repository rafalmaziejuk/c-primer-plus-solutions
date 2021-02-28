#include <stdio.h>

#define MASKA 0x1

int sprawdz_bity(int liczba);

int main(void)
{
	int liczba = 23;

	printf("Liczba bitow ustawionych na 1 w %d = %d\n", liczba, sprawdz_bity(liczba));

    return 0;
} 

int sprawdz_bity(int liczba)
{
	int bity = 0;

	while (liczba != 0)
	{
		if (liczba & MASKA)
			bity++;

		liczba >>= 1;
	}

	return bity;
}