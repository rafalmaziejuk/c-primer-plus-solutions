#include <stdio.h> 
#include <stdlib.h>
#include <stdarg.h>

void pokaz_tablice(const double tab[], int n);
double * nowa_tablica(int n, ...);

int main(void) 
{ 
    double *w1, *w2;

    w1 = nowa_tablica(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    w2 = nowa_tablica(4, 100.0, 20.00, 8.08, -1890.0);

    pokaz_tablice(w1, 5);
    pokaz_tablice(w2, 4);

    free(w1);
    free(w2);

    return 0;
} 

void pokaz_tablice(const double tab[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%.2f ", tab[i]);

	putchar('\n');
}

double * nowa_tablica(int n, ...)
{
	double *temp = (double *)malloc(n * sizeof(double));

	va_list lista_argumentow;
	va_start(lista_argumentow, n);

	for (int i = 0; i < n; i++)
		temp[i] = va_arg(lista_argumentow, double);

	va_end(lista_argumentow);

	return temp;
}