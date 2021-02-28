#include <stdio.h>

int main(void)
{
	char ch;
	int licznik = 0;

	while (scanf("%c", &ch) == 1)
	{
		if (ch == '#')
			break;

		switch(ch) 
		{
			case '.':
			{
				printf("!");
				licznik++;
				break;
			}
			case '!': 
			{
				printf("!!");
				licznik++;
				break;
			}
		}
	}

	printf("\nLiczba zamian: %d\n", licznik);

	return 0;
}
