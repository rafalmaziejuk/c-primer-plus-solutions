#include <stdio.h>

void krytyka(int *jedn);

int main(void)
{
	int jednostki = 0;

	printf("Ile funtow masla miesci sie w barylce?\n");
	scanf("%d", &jednostki);

	while (jednostki != 56)
		krytyka(&jednostki);

	printf("Musiales podejrzec!\n");
	
	return 0;
}

void krytyka(int *jedn)
{
	printf("Nie masz szczescia, sprobuj ponownie.\n");
	scanf("%d", jedn);
}