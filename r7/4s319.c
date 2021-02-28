#include <stdio.h>

int main(void)
{
	char ch;
	int licznik = 0;

	while (scanf("%c", &ch) == 1)
	{
		if (ch == '#')
			break;

		if (ch == '.')
		{
			printf("!");
			licznik++;
		}
		else 
		{
			printf("!!");
			licznik++;
		}
	}

	printf("\nLiczba zamian: %d\n", licznik);

	return 0;
}
