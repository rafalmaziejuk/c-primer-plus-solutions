#include <stdio.h>

void do_podst_n(unsigned long n, unsigned int podstawa);

int main(void)
{
	unsigned long liczba;
	unsigned int  podstawa;

	printf("Podaj liczbe calkowita i podstawe (q konczy program): \n");

	while (scanf("%ld %d", &liczba, &podstawa) == 2)
	{
		printf("Odpowiednik dwojkowy: ");
		do_podst_n(liczba, podstawa);
		putchar('\n');
		printf("Podaj liczbe calkowita i podstawe (q konczy program): \n");
	}
	
	printf("Gotowe.\n");

	return 0;
}

void do_podst_n(unsigned long n, unsigned int podstawa)
{
	int r;

	r = n % podstawa;

	if (n >= podstawa)
		do_podst_n(n / podstawa, podstawa);

	if (r == 0)
		putchar('0');
	else printf("%d", r);

	return;
}