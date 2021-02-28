#include <stdio.h>
#include <math.h>

typedef struct wektor
{
	float a;
	float b;
} Wektor;

Wektor konwersja(const Wektor *w);

int main(void)
{
	Wektor wektor_biegunowe;
	Wektor wektor_kartezjanskie;

	puts("Podaj dlugosc i kat nachylenia wektora:");
	scanf("%f %f", &wektor_biegunowe.a, &wektor_biegunowe.b);

	printf("Dlugosc = %.1f\nKat nachylenia: %.1f\n\n", wektor_biegunowe.a, wektor_biegunowe.b);

	wektor_kartezjanskie = konwersja(&wektor_biegunowe);

	printf("x = %.1f\ny = %.1f\n", wektor_kartezjanskie.a, wektor_kartezjanskie.b);

	return 0;
}

Wektor konwersja(const Wektor *w)
{
	Wektor temp;
	float radiany = w->b * M_PI / 180;

	printf("radiany %.2f\n", radiany);

	temp.a = w->a * cos(radiany);
	temp.b = w->a * sin(radiany);

	return temp;
}
