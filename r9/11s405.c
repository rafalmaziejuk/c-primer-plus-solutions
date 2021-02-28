#include <stdio.h>

unsigned long Fibonacci(unsigned int n);

int main(void)
{
	int liczba;

	printf("Podaj wyraz ciagu Fibonacci: ");
	scanf("%d", &liczba);

	printf("%d wyraz ciagu Fibonacciego = %lu\n", liczba, Fibonacci(liczba));

	return 0;
}

unsigned long Fibonacci(unsigned int n)
{
	unsigned long poprzedni, aktualny;
	unsigned long nastepny;

	poprzedni = aktualny = 1;

	if (n > 2)
		while (n > 2)
		{
			nastepny = poprzedni + aktualny;
			poprzedni = aktualny;
			aktualny = nastepny;	
			n--;
		}
	else return 1;
		
	return nastepny;
}
