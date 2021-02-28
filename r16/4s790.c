#include <stdio.h>
#include <time.h>

void opoznienie(double czas);

int main(void)
{
	double czas;

	printf("Podaj czas, z jakim chcesz opoznic dzialanie funkcji: ");
	while (scanf("%lf", &czas))
	{
		puts("Start!");
		opoznienie(czas);
		printf("Podaj czas, z jakim chcesz opoznic dzialanie funkcji: ");
	}

    return 0;
} 

void opoznienie(double czas)
{
	clock_t start, koniec;

	start = clock();

	while (((koniec = clock()) - start) / (double) CLOCKS_PER_SEC < czas)
		continue;

	puts("Koniec!");
}