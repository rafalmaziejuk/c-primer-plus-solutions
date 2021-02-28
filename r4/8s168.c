#include <stdio.h>

#define GALON 3.785
#define MILA 1.609

int main(void)
{
	float mila, zuzyte_galony;
	float poziom_zuzycia;
	float litr, kilometr;

	printf("Podaj liczbe przebytych mil i zuzytych galonow: ");
	scanf("%f %f", &mila, &zuzyte_galony);

	poziom_zuzycia = mila / zuzyte_galony;

	printf("Mile/galon: %.2f\n", poziom_zuzycia);

	litr = zuzyte_galony * GALON;
	kilometr = mila * MILA;
	poziom_zuzycia = litr / kilometr;

	printf("Litry/100 km: %.1f\n", poziom_zuzycia);

	return 0;
}
