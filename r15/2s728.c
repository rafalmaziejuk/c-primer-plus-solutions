#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZMIAR 2

int bin_to_dec(char *wsk);
void dec_to_bin(int liczba, char *wsk, int r);

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		fprintf(stderr, "Za malo argumentow!\n");
		exit(EXIT_FAILURE);
	}
	else if (strlen(argv[1]) != strlen(argv[2]))
	{
		fprintf(stderr, "Lancuchy musza miec rowna dlugosc!\n");
		exit(EXIT_FAILURE);
	}

	int liczba[ROZMIAR], pom;
	int rozmiar = strlen(argv[1]);
	char *lan = (char *)malloc(rozmiar + 1);

	for (int i = 0; i < ROZMIAR; i++)
		liczba[i] = bin_to_dec(argv[i + 1]);

	for (int i = 0; i < ROZMIAR; i++)
		printf("%s = %d\n", argv[i + 1], liczba[i]);

	//NOT ~
	for (int i = 0; i < ROZMIAR; i++)
	{
		dec_to_bin(~liczba[i], lan, rozmiar);
		pom = bin_to_dec(lan);

		printf("~%s = %s = %d\n", argv[i + 1], lan, pom);
	}
	
	//AND &
	dec_to_bin(liczba[0] & liczba[1], lan, rozmiar);
	pom = bin_to_dec(lan);
	printf("%s & %s = %s = %d\n", argv[1], argv[2], lan, pom);

	//OR |
	dec_to_bin(liczba[0] | liczba[1], lan, rozmiar);
	pom = bin_to_dec(lan);
	printf("%s | %s = %s = %d\n", argv[1], argv[2], lan, pom);

	//XOR ^
	dec_to_bin(liczba[0] ^ liczba[1], lan, rozmiar);
	pom = bin_to_dec(lan);
	printf("%s ^ %s = %s = %d\n", argv[1], argv[2], lan, pom);

	free(lan);

    return 0;
}

int bin_to_dec(char *wsk)
{
	int potega = 1;
	int liczba = 0;

	for (int i = strlen(wsk) - 1; i >= 0; i--)
	{
		int pom;

		pom = wsk[i] - '0';
		liczba += potega * pom;

		potega *= 2;
	}

	return liczba;
}

void dec_to_bin(int liczba, char *wsk, int r)
{
	for (int i = r - 1; i >= 0; i--, liczba >>= 1)
		wsk[i] = '0' + (0x1 & liczba);

	wsk[r] = '\0';
}