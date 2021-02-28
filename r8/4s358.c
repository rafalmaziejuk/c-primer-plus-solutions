#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int znaki, slowa, suma;

	znaki = slowa = suma = 0;

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
			znaki++;
		
		if (ch == ' ' || ch == '\n')
		{
			slowa++;
			suma += znaki;
			znaki = 0;
		}
	}	
	
	printf("Srednia ilosc liter w slowe: %.2f\n", float(suma / slowa));
		
	return 0;
}