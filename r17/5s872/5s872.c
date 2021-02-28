#include <stdio.h>
#include <string.h>
#include "stos.h"

#define ROZMIAR 20

int main(void)
{
	Stos stos;
	char lancuch[ROZMIAR];

	printf("Podaj lancuch do wyswietlenia: ");
	scanf("%s", lancuch);

	InicjujStos(&stos);

	for (int i = 0; i < strlen(lancuch); i++)
		DodajPozycje(lancuch[i], &stos);

	while (ZdejmijPozycje(&stos));

	putchar('\n');

   	return 0;
}