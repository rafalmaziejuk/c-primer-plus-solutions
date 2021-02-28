#include <stdio.h>

char * zawiera_lan(char *s1, char *s2);

int main(void)
{
	char *ch;
	
	ch = zawiera_lan("pula", "ul");

	if (ch != NULL)
		printf("Zawiera sie pod adresem %p znak %c.\n", ch, *ch);
	else printf("Nie zawiera sie.\n");

	return 0;
}

char * zawiera_lan(char *s1, char *s2)
{
	int flaga = 0;

	while (*s1 != '\0')
	{
		while (*s2 != '\0')
		{
			if (*s1 != *s2)
				break;

			s2++;
			flaga = 1;
		}

		if (flaga)
			return s1;

		s1++;
	}

	return NULL;
}
