#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZMIAR 10

int main(void)
{
	int liczba_slow;
	char temp[ROZMIAR];
	int i = 0;

	printf("Podaj liczbe slow do wprowadzenia: ");
	scanf("%d", &liczba_slow);
	getchar();

	char **tab = (char **)malloc(liczba_slow * sizeof(char *));

	printf("Wprowadz %d slow: \n", liczba_slow);
	while (i < liczba_slow && scanf("%10s", temp) && temp[0] != '\n')
	{
		char *pom = (char *)malloc(strlen(temp) * sizeof(char) + 1);
		strcpy(pom, temp);

		tab[i] = pom;

		i++;
	}

	puts("Oto wprowadzone slowa:");
	for (int j = 0; j < liczba_slow; j++)
		puts(tab[j]);

	free(tab);

	return 0;
}