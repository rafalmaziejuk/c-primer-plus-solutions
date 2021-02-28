#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
	int tryb;
	int dystans;
	float zuzyte_paliwo;

	printf("Wybierz: 0 - system metryczny, 1 - system US: ");
	scanf("%d", &tryb);

	while (tryb >= 0)
	{
		wybierz_tryb(&tryb);
		pobierz_dane(&dystans, &zuzyte_paliwo, tryb);
		wyswietl_dane(dystans, zuzyte_paliwo, tryb);

		printf("Wybierz: 0 - system metryczny, 1 - system US");
		printf(" (-1 aby zakonczyc): ");
		scanf("%d", &tryb);
	}

	printf("Koniec.\n");

	return 0;
}