#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int male_litery, wielkie_litery, pozostale_znaki;

	male_litery = wielkie_litery = pozostale_znaki = 0; 

	while ((ch = getchar()) != EOF)
		if (islower(ch))
			male_litery++;
		else if (isupper(ch))
			wielkie_litery++;
		else if (ch != '\n' && ch != ' ' && ch != EOF)
			pozostale_znaki++;

	printf("Male litery: %d\nWielkie litery: %d\nPozostale znaki: %d\n", male_litery, wielkie_litery, pozostale_znaki);

	return 0;		
}