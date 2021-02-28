#include <stdio.h>

int main(void)
{
	int rachunek = 1000000;
	int lata = 0;

	while (rachunek > 0)
	{
		printf("Stan rachunku: %d\n", rachunek);

		rachunek += rachunek * 0.08;
		rachunek -= 100000;
		
		lata++;
	}

	printf("Lat: %d\n", lata);

	return 0;
}