#include <stdio.h>
#include <string.h>

int main(void)
{
	char linia[255];
	char ch;
	int i = 0;

	printf("Wpisz linie: ");
	while (scanf("%c", &ch) == 1 && ch != '\n') 
	{
		linia[i] = ch;
		i++;
	}
	
	linia[i] = '\0';

	for (int i = strlen(linia) - 1; i >= 0; i--)
		printf("%c", linia[i]);

	return 0;
}
