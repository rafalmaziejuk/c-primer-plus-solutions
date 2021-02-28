#include <stdio.h>
#include <stdlib.h>

#define ARBUZ 1.25
#define BURAK 0.65
#define CEBULA 0.89
#define RABAT 0.05
#define PRZESYLKA_PONIZEJ5 3.50
#define PRZESYLKA_POWYZEJ5 10
#define PRZESYLKA_POWYZEJ20 8
#define KOLEJNY_KILOGRAM20 0.10

void menu(void);

int main(void)
{
	char opcja;
	int ilosc_arbuz, ilosc_burak, ilosc_cebula;
	int ilosc;

	ilosc_arbuz = ilosc_burak = ilosc_cebula = 0; 

	menu();

	while(scanf("%c", &opcja) == 1)
	{
		getchar();
		switch(opcja)
		{
			case 'A':
			{
				printf("Podaj ilosc: ");
				scanf("%d", &ilosc);
				getchar();
				
				ilosc_arbuz += ilosc;

				break;
			}
				
			case 'B':
			{
				printf("Podaj ilosc: ");
				scanf("%d", &ilosc);
				getchar();

				ilosc_burak += ilosc;

				break;
			}

			case 'C':
			{
				printf("Podaj ilosc: ");
				scanf("%d", &ilosc);
				getchar();

				ilosc_cebula += ilosc;

				break;
			}

			case 'K':
			{
				int waga_przesylki;
				float naleznosc, rabat, koszt_przesylki, suma_platnosci;

				waga_przesylki = ilosc_arbuz + ilosc_burak + ilosc_cebula;
				naleznosc = float (ilosc_arbuz * ARBUZ) + float (ilosc_burak * BURAK) + float (ilosc_cebula * CEBULA);

				if (naleznosc > 100)
					rabat = naleznosc * RABAT;
				else rabat = 0;

				if (waga_przesylki <= 5)
					koszt_przesylki = PRZESYLKA_PONIZEJ5;
				else if (waga_przesylki > 5 && waga_przesylki < 20)
					koszt_przesylki = PRZESYLKA_POWYZEJ5;
				else if (waga_przesylki >= 20)
				{
					int pom = waga_przesylki - 20;
					koszt_przesylki = PRZESYLKA_POWYZEJ20;
					koszt_przesylki += pom * KOLEJNY_KILOGRAM20;
				}	

				suma_platnosci = naleznosc - rabat + koszt_przesylki;

				printf("ZAMOWIENIE\n");
				printf("Ilosc zamowionych warzyw: %10d\n", waga_przesylki);
				printf("Wartosc arbuzy: %10.2f\n", ilosc_arbuz * ARBUZ);
				printf("Wartosc buraki: %10.2f\n", ilosc_burak * BURAK);
				printf("Wartosc cebule: %10.2f\n", ilosc_cebula * CEBULA);
				printf("Wartosc calosci zamowienia: %10.2f\n", naleznosc);
				printf("Rabat: %10.2f\n", rabat);
				printf("Koszt przesylki: %10.2f\n", koszt_przesylki);
				printf("Calkowity koszt zamowienia: %10.2f\n", suma_platnosci);

				ilosc_arbuz = ilosc_burak = ilosc_cebula = 0; 

				break;
			}

			case 'E': exit(0);

			default: break;
		}

		menu();
	}

	return 0;
}

void menu(void)
{
	printf("\nWARZYWA\n");
	printf("A) Arbuzy\n");
	printf("B) Buraki\n");
	printf("C) Cebule\n");
	printf("K) Koniec zamowienia\n");
	printf("E) Wyjscie\n");
	printf("Co chcesz zamowic: ");
}
