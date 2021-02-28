#include <stdio.h>

char pobierz_pierwszy(void);

int main(void)
{
	char ch = pobierz_pierwszy();

	printf("Pierwszy znak drukowalny: %c\n", ch);
		
	return 0;
}

char pobierz_pierwszy(void)
{
	int we;
	char ch;

	while (scanf("%c", &ch))
		if (ch > 32)
			break;
		else continue;
	
	return ch;
}