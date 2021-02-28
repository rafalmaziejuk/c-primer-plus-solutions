#include <stdio.h>

void Temperatura(double temp);

int main(void)
{
	double temperatura;

	printf("Podaj temperature w skali Fahrenheita: ");

	while (scanf("%lf", &temperatura) == 1)
	{
		Temperatura(temperatura);

		printf("Podaj temperature w skali Fahrenheita: ");
	}

	return 0;
}

void Temperatura(double temp)
{
	double celsjusz = 5.0 / 9.0 * (temp - 32.0);
	double kelwin   = celsjusz + 273.16;

	printf("W skali Fahrenheita: %.2f\n", temp);
	printf("W skali Celsjusza: %.2f\n", celsjusz);
	printf("W skali Kelwina: %.2f\n", kelwin);
}
