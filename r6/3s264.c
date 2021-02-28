#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 6; i++)
	{
		char ch = 'F';

		for (int j = 0; j <= i; j++)
		{
			printf("%c", ch);
			ch--;
		}

		printf("\n");
	}

	return 0;
}
