#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double potega = 1;

	double podstawa = atof(argv[1]);
	int wykladnik = atoi(argv[2]);

	for (int i = 0; i < wykladnik; i++)
		potega *= podstawa;

	printf("Wynik = %.1f\n", potega);

	return 0;
}