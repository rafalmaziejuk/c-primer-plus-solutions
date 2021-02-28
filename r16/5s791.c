#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 10

void wyswietl_losowe(int tab[], int rozmiar, int ilosc);

int main(void)
{
	int tab[ROZMIAR];
	int ilosc_losowych = 5;

	for (int i = 0; i < ROZMIAR; i++)
		tab[i] = i + 1;

	printf("Tablica: ");
	for (int i = 0; i < ROZMIAR; i++)
		printf("%d ", tab[i]);

	printf("\n%d losowych liczb z tablicy: ", ilosc_losowych);
	wyswietl_losowe(tab, ROZMIAR, ilosc_losowych);

    return 0;
}

void wyswietl_losowe(int tab[], int rozmiar, int ilosc)
{
	int *temp = (int *)malloc(ilosc * sizeof(int));

	for (int i = 0; i < ilosc; i++)
		temp[i] = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < ilosc; i++)
	{
		int pom = tab[rand() % 9];
		int j = 0;
	
		while (j < ilosc)
		{
			if (pom == temp[j])
			{
				pom = tab[rand() % 9];
				j = 0;
				
				continue;
			}
			
			j++;
		}
		
		temp[i] = pom;
	}

	for (int i = 0; i < ilosc; i++)
		printf("%d ", temp[i]);

	putchar('\n');
	free(temp);
}