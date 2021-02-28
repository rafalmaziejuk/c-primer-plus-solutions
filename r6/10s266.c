#include <stdio.h>

int main(void)
{
	int granica_dolna, granica_gorna;

	printf("Podaj dolna i gorna granice przedzialu liczb calkowitych: ");
	scanf("%d %d", &granica_dolna, &granica_gorna);

	while ((granica_dolna != granica_gorna) && (granica_dolna < granica_gorna))
	{
		int suma = 0;

		for (int i = granica_dolna; i <= granica_gorna; i++)
			suma += i * i;

		printf("Suma kwadratow od %d do %d wynosi %d\n", granica_dolna * granica_dolna, granica_gorna * granica_gorna, suma);

		printf("Podaj nastepny przedzial: ");
		scanf("%d %d", &granica_dolna, &granica_gorna);
	}

	printf("Koniec!\n");

	return 0;
}
