#include <stdio.h> 

#define TYDZIEN 7

int main(void)
{
	int liczba;
	int tygodni, dni;

	printf("Podaj ilosc dni:\n");
	scanf("%d", &liczba);

	while(liczba != 0 && liczba != -20)
	{
		tygodni = liczba / TYDZIEN;
		dni = liczba - tygodni * TYDZIEN;

		printf("%d dni to %d tydodnie, %d dni.\n", liczba, tygodni, dni);

		printf("Podaj ilosc dni:\n");
		scanf("%d", &liczba);
	}

	return 0;
}
