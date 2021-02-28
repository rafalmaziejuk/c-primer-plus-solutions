#include <stdio.h>

int main(void)
{
	float liczba;

	printf("Podaj liczbe zmiennoprzecinkowa: ");
	scanf("%f", &liczba);

	printf("Podana liczba to %f lub %e lub %a\n", liczba, liczba, liczba);

	return 0;
}
