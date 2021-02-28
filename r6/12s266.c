#include <stdio.h>

int main(void)
{
	int limit;
	float suma1 = 0.0, suma2 = 0.0;
	float licznik = 2.0;
	float pom = -1.0;

	printf("Podaj limit: ");
	scanf("%d", &limit);

	while (limit >= 0)
	{	
		for (int i = 0; i <= limit; i++)
		{	
			suma1 += 1.0 / licznik;
			suma2 += pom / licznik;

			pom = -pom;
			licznik += 1.0;
		}
		
		printf("Suma1 = %f\nSuma2 = %f\n", suma1, suma2);

		suma1 = suma2 = 0.0;
		licznik = 2.0;
		pom = -1.0;
		
		printf("Podaj limit: ");
		scanf("%d", &limit);
	}

	return 0;
}
