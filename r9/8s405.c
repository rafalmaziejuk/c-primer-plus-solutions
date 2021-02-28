#include <stdio.h>

double potega(double p, int w);

int main(void)
{	
	double podstawa, wynik;
	int wykladnik;

	printf("Podaj podstawe i wykladnik: ");
	while (scanf("%lf %d", &podstawa, &wykladnik) == 2)
	{
		while (getchar() != '\n')
			continue;

		wynik = potega(podstawa, wykladnik);

		printf("%.4f\n", wynik);
	}

	return 0;
}

double potega(double p, int w)
{
	double pot = 1;
	int i;

	if (p == 0 && w == 0)
	{
		printf("0 do potegi 0 nie zadziala!\nZamiast tego uzyje 1.\n");
		return pot;
	}
	else 
	{
		if (w > 0)
		{
			for (i = 1; i <= w; i++)
				pot *= p;

			return pot;
		}
		else if (w < 0)
		{
			w = -w;

			for (i = 1; i <= w; i++)
				pot *= p;

			return 1 / pot;
		}
		else if (w == 0)
			return pot;
	}
}