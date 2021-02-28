#include <stdio.h>

int main(void)
{
	double tablica1[8];
	double tablica2[8];
	double pom = 0.0;

	for (int i = 0; i < 8; i++)
	{
		printf("Podaj %d element tablicy: ", i + 1);
		scanf("%lf", tablica1 + i);
	}
		
	for (int i = 0; i < 8; i++)
	{
		pom += tablica1[i];
		tablica2[i] = pom;
	}

	for (int i = 0; i < 8; i++)
		printf("%5.2f ", tablica1[i]);

	printf("\n");

	for (int i = 0; i < 8; i++)
		printf("%5.2f ", tablica2[i]);

	printf("\n");

	return 0;
}