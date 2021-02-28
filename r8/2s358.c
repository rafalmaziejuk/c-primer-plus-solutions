#include <stdio.h>

int main(void)
{
	int ch;
	int licznik = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch > 32)
			printf("%c:%d  ", ch, ch);
		else if (ch == 32)
			printf("' ':%d  ", ch);
		else if (ch == '\t')
			printf("\\t:%d  ", ch);
		else if (ch == '\n')
			printf("\\n:%d  ", ch);
		else printf("^%c:%d  ", ch + 64);

		if (++licznik == 10)
		{
			printf("\n");
			licznik = 0;
		}
	}
		

	return 0;
}