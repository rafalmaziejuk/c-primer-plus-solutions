#include <stdio.h>

int main(void)
{
	int dzielnik;
	int dzielna;

	printf("Program obliczajacy reszte z dzielenia.\n");
	printf("Podaj dzielnik (liczba calkowita): ");
	scanf("%d", &dzielnik);
	printf("Podaj dzielna: ");
	scanf("%d", &dzielna);
	
	while (dzielna > 0)
	{
		printf("%d %% %d wynosi %d\n", dzielna, dzielnik, dzielna % dzielnik);
		
		printf("Podaj dzielna (<= 0, aby zakonczyc: ");
		scanf("%d", &dzielna);
	}

	printf("Koniec\n");

	return 0;
}
