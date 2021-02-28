#include <stdio.h> 

int main(void)
{
	char ch = 'A';

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%c", ch);
			ch++;
		}

		printf("\n");
	}

	return 0;
}