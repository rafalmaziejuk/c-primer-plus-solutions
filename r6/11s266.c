#include <stdio.h>

int main(void)
{
	int tablica[8];

	for (int i = 0; i < 8; i++)
		tablica[i] = i + 1;

	for (int i = 7; i >= 0; i--)
		printf("%d ", tablica[i]);

	printf("\n");
	
	return 0;
}