#include <stdio.h>

int main(void)
{
	int granica_dolna, granica_gorna;

	printf("Podaj dolna i gorna granice: ");
	scanf("%d %d", &granica_dolna, &granica_gorna);

	for (int i = granica_dolna; i <= granica_gorna; i++)
		printf("%d %d %d\n", i, i * i, i * i * i);

	return 0;
}