#include <stdio.h>

void rzad_zn(char ch, int i, int j);

int main(void)
{
	rzad_zn ('$', 5, 6);

	return 0;
}

void rzad_zn(char ch, int i, int j)
{
	int pom;
	i > j ? pom = i : pom = j;

	for (int x = 1; x <= pom; x++)
		if (x != i && x != j)
			putchar('.');
		else putchar(ch);

	putchar('\n');
}