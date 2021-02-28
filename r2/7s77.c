#include <stdio.h>

void funkcja(void);

int main(void)
{
	funkcja();
	funkcja();
	funkcja();
	printf("\n");

	funkcja();
	funkcja();
	printf("\n");

	funkcja();
	printf("\n");

	return 0;
}

void funkcja(void)
{
	printf("Usmiech!");
}
