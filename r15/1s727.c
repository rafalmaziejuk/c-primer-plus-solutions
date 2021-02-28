#include <stdio.h>
#include <string.h>

unsigned int bin_to_dec(char *wsk);

int main(void)
{
	char *wbin = "01001001";
	unsigned int liczba;

	liczba = bin_to_dec(wbin);

	printf("%s = %u\n", wbin, liczba);

    return 0;
}

unsigned int bin_to_dec(char *wsk)
{
	unsigned int potega = 1;
	unsigned int liczba = 0;

	for (int i = strlen(wsk) - 1; i >= 0; i--)
	{
		unsigned int pom;

		pom = wsk[i] - '0';
		liczba += potega * pom;

		potega *= 2;
	}

	return liczba;
}