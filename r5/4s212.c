#include <stdio.h>

#define STOPA 30.48
#define CAL   2.54

int main(void)
{
	float wzrost;
	float cale;
	int stopy;

	printf("Podaj wzrost w centymetrach: ");
	scanf("%f", &wzrost);
	printf("\n");

	while(wzrost > 0)
	{
		stopy = wzrost / STOPA;
		cale = wzrost / CAL;

		printf("%.1f cm = %d stop, %.2f cali\n", wzrost, stopy, cale);

		printf("Podaj wzrost w centymetrach (<=0 - koniec): ");
		scanf("%f", &wzrost);
	}

	printf("Do widzenia!\n");

	return 0;
}