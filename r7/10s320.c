#include <stdio.h>
#include <stdlib.h>

#define PODATEK_PONIZEJ 0.15
#define PODATEK_POWYZEJ 0.28
#define STAN_WOLNY 17850
#define GLOWA_RODZINY 23900
#define MALZENSTWO_WSP 29750
#define MALZENSTWO_OSO 14875

void menu(void);

int main(void)
{
	int opcja, dochod;

	menu();

	while(scanf("%d", &opcja) == 1)
	{
		switch(opcja)
		{
			case 1:
			{
				printf("Podaj dochod: ");
				scanf("%d", &dochod);

				if (dochod <= STAN_WOLNY)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod);
				else if (dochod > STAN_WOLNY)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod + (dochod - STAN_WOLNY) * PODATEK_POWYZEJ);

				break;
			}
				
			case 2:
			{
				printf("Podaj dochod: ");
				scanf("%d", &dochod);

				if (dochod <= GLOWA_RODZINY)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod);
				else if (dochod > GLOWA_RODZINY)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod + (dochod - GLOWA_RODZINY) * PODATEK_POWYZEJ);

				break;
			}

			case 3:
			{
				printf("Podaj dochod: ");
				scanf("%d", &dochod);

				if (dochod <= MALZENSTWO_WSP)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod);
				else if (dochod > MALZENSTWO_WSP)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod + (dochod - MALZENSTWO_WSP) * PODATEK_POWYZEJ);

				break;
			}

			case 4:
			{
				printf("Podaj dochod: ");
				scanf("%d", &dochod);

				if (dochod <= MALZENSTWO_OSO)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod);
				else if (dochod > MALZENSTWO_OSO)
					printf("Podatek wynosi: %.2f\n", PODATEK_PONIZEJ * dochod + (dochod - MALZENSTWO_OSO) * PODATEK_POWYZEJ);

				break;
			}

			case 5: exit(0);

			default: break;
		}

		menu();
	}

	return 0;
}

void menu(void)
{
	printf("\nKategoria\n");
	printf("1) Stan wolny\n");
	printf("2) Glowa rodziny\n");
	printf("3) Malzenstwo, rozliczenie wspolne\n");
	printf("4) Malzenstwo, rozliczenie osobne\n");
	printf("5) Wyjscie\n");
	printf("Podaj kategorie: ");
}
