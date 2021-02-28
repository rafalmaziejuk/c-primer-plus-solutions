#include <stdio.h>

int main(void)
{
	char znak;

	printf("Podaj wielka litere: ");
	scanf("%c", &znak);

	char pom = znak - 1;

	for (char c = 'A'; c <= znak; c++)
	{
		for (char ch = pom; ch >= 'A'; ch--)
			printf(" ");

		for (char ch = 'A'; ch < 'A' + (znak - pom); ch++)
			printf("%c", ch);
		
		for (char ch = 'A' + (znak - pom - 1); ch > 'A'; ch--)
			printf("%c", ch - 1);

		printf("\n");
		pom--;
	}

	return 0;
}