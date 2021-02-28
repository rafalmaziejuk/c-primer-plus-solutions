#include <stdio.h>
#include <math.h>

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
	double pot;

	if (p == 0 && w == 0)
	{
		printf("0 do potegi 0 nie zadziala!\nZamiast tego uzyje 1.\n");
		return 1;
	}
	else 
	{
		if (w == 0)
			return 1;
		else if (w < 0)
			pot = p * potega(p, -w - 1);
		else if (w > 0)
			pot = p * potega(p, w - 1);
	}

	if (w > 0)
		return pot;
	else return 1 / pot;
}