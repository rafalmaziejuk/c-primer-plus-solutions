#include <stdio.h>

int main(void)
{
	char ch;
	int liczba = 50;
	int dolna_granica = 0;
	int gorna_granica = 100;

	printf("Wybierz liczbe od 1 do 100. Sprobuje ja odgadnac.");
	printf("\nWpisz t, jesli moja proba jest udana lub");
	printf("\nm, jesli liczba jest mniejsza lub w jesli liczba jest wieksza.\n");
	printf("Hmm... czy Twoja liczba jest %d?\n", liczba);
	
	while ((ch = getchar()) != 't')
	{
		while (getchar() != '\n');

		if (ch == 'm')
			gorna_granica = liczba;
		else if (ch == 'w')
			dolna_granica = liczba;

		liczba = (dolna_granica + gorna_granica) / 2;
		
		printf("No dobrze, czy jest to %d?\n", liczba);
	}

	printf("Wiedzialem, ze mi sie uda!\n");
		
	return 0;
}