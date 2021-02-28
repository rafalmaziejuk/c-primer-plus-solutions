#include <stdio.h>

#define ROZMIAR 20

char * kopiuj_string(char *s1, const char *s2, unsigned int n);

int main(void)
{
	char zrodlo[] = "String jakis ";
	char cel[ROZMIAR];

	kopiuj_string(cel, zrodlo, 10);

	puts(cel);

	return 0;
}

char * kopiuj_string(char *s1, const char *s2, unsigned int n)
{
	int i = 0;

	while (*s2 != '\0' && i != n)
	{
		*s1 = *s2;

		s1++;
		s2++;
		i++;
	}

	if (i == n)
		*s1 = '\0';
	else
	{	
		while (i < n)
		{
			*s1 = '\0';
			i++;
		}
	}	

	return s1;
}
