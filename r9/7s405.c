#include <stdio.h>
#include <ctype.h>

int znak(char ch);

int main(void)
{	
	char ch;

	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;

		printf("%c %d\n", ch, znak(ch));
	}

	return 0;
}

int znak(char ch)
{
	if (isalpha(ch))
		return int(toupper(ch)) - 64;
	else return -1;
}