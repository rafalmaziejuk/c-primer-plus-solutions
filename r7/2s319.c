#include <stdio.h>

int main(void)
{
	char ch;
	int licznik = 0;

	while (scanf("%c", &ch) == 1)
	{
		if (ch == '#')
			break;

		if (licznik % 8 == 0)
		{
			licznik = 0;
			printf("\n");
		}
		
		if (ch != '\n')
			printf("%c %d ", ch, ch);
	
		licznik++;
	}

	return 0;
}
