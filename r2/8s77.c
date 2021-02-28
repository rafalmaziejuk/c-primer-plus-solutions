#include <stdio.h>

void dwa(void);
void raz_trzy(void);

int main(void)
{
	printf("zaczynamy:\n");
	raz_trzy();
	printf("koniec!\n");

	return 0;
}

void dwa(void)
{
	printf("dwa\n");
}

void raz_trzy(void)
{
	printf("raz\n");
	dwa();
	printf("trzy\n");
}
