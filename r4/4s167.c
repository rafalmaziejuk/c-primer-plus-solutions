#include <stdio.h>

int main(void)
{
	float wzrost;
	char imie[10];

	printf("Podaj swoj wzrost oraz imie:\n");
	scanf("%f %s", &wzrost, imie);

	wzrost /= 100;

	printf("%s, masz %.2f metra wzrostu.\n", imie, wzrost);

	return 0;
}
