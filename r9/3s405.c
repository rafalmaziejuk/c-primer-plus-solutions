#include <stdio.h>

void rzad_zn(char ch, int i, int j);

int main(void)
{	
	char ch = '$';
	int i = 5;
	int j = 6;

	rzad_zn(ch, i, j);

	return 0;
}

void rzad_zn(char ch, int i, int j)
{
	for (int y = 1; y <= i; y++)
	{
		for (int x = 1; x <= j; x++)
			printf("%c", ch);

		printf("\n");
	}
}