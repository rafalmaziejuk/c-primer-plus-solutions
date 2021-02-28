#include <stdio.h>

int main(void)
{
	char tablica[26];
	int licznik = 0;

	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		tablica[licznik] = ch;
		licznik++;
	}

	for (int i = 0; i < 26; i++)
		printf("%c ", tablica[i]);

	return 0;
}