#include <stdio.h>

int main(void)
{
	char kod_ASCII;

	printf("Podaj kod ASCII znaku: ");
	scanf("%hhd", &kod_ASCII);

	printf("Liczba %d odpowiada znakowi %c w kodzie ASCII.\n", kod_ASCII, kod_ASCII);

	return 0;
}
