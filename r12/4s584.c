#include <stdio.h>

void funkcja(void);

int main(void)
{
	for (int i = 0; i < 10; i++)
		funkcja();

	return 0;
}

void funkcja(void)
{
	static int licznik = 0;

	printf("Wywolanie numer %d.\n", 1 + licznik++);
}