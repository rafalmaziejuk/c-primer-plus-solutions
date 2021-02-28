#include <stdio.h>

int main(void)
{
	int znajomi = 5;
	int tydzien = 1;

	while (znajomi < 150)
	{
		printf("Tydzien %d: %d\n", tydzien, znajomi);

		znajomi -= tydzien;
		znajomi *= 2;
		
		tydzien++;
	}

	printf("Tydzien %d: %d\n", tydzien, znajomi);

	return 0;
}