#include <stdio.h>

int main(void)
{
	int lata;
	float ewa, kasia;

	lata = 0;
	ewa = kasia = 100.0;

	while (kasia <= ewa)
	{
		ewa += 100.0 * 0.10;
		kasia += kasia * 0.05;

		lata++;
	}

	printf("Po %d latach\n", lata);
	printf("Ewa: %5.2f\nKasia: %5.2f\n", ewa, kasia);

	return 0; 
}