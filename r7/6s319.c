#include <stdio.h>

int main(void)
{
	char ch;
	char poprzedni_znak = '\0';
	int licznik = 0;

	while (scanf("%c", &ch) == 1)
	{
		if (ch == '#')
			break;
	
		if (poprzedni_znak == 'o' && ch == 't')
			licznik++;
		
		poprzedni_znak = ch;
	}

	printf("\nLiczba powtorzen: %d\n", licznik);

	return 0;
}
