#include <stdio.h>

void opcja_a(void);
void opcja_b(void);
void opcja_c(void);
void opcja_d(void);

int main(void)
{
	void (*tab[4])(void) = { opcja_a, opcja_b, opcja_c, opcja_d };

	char opcja;

	while (scanf("%c", &opcja))
	{
		while (getchar() != '\n')
			continue;

		switch(opcja)
		{
			case 'a':
			{
				(*tab[0])();
				break;
			}			

			case 'b':
			{
				(*tab[1])();
				break;
			}

			case 'c':
			{
				(*tab[2])();
				break;
			}

			case 'd':
			{
				(*tab[3])();
				break;
			}

			default: exit(0);
		}
	}

    return 0;
}

void opcja_a(void)
{
	printf("Opcja a.\n");
}

void opcja_b(void)
{
	printf("Opcja b.\n");
}

void opcja_c(void)
{
	printf("Opcja c.\n");
}

void opcja_d(void)
{
	printf("Opcja d.\n");
}
