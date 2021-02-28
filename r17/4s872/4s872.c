#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
#include "kolejka.h"

#define MIN_W_GODZ 60.0
#define ROZMIAR 2

bool nowyklient(double x);         
Pozycja czasklienta(long kiedy);   

int main(void)
{
   	Kolejka kol[ROZMIAR];
   	Pozycja tymcz;         
   	int godz;              
   	int nagodz;            
   	long cykl, gran_cyklu; 
   	long odeslani = 0;     
   	long klienci = 0;      
   	long obsluzeni1 = 0;
   	long obsluzeni2 = 0;     
   	long suma_kol1 = 0;     
   	long suma_kol2 = 0; 
   	int czas_czek1 = 0;   
   	int czas_czek2 = 0; 
   	double min_na_kl;      
   	long kol_czek1 = 0;  
   	long kol_czek2 = 0;   

   	for (int i = 0; i < ROZMIAR; i++)
   		InicjujKolejke(&kol[i]);

   	srand((unsigned int)time(0));

   	puts("Studium przypadku: Punkt porad Zygmunta Prywaciarza");
   	puts("Podaj liczbe godzin symulacji:");
   	scanf("%d", &godz);
   	gran_cyklu = MIN_W_GODZ * godz;

   	puts("Podaj srednia liczbe klientow w ciagu godziny:");
   	scanf("%d", &nagodz);
   	min_na_kl = MIN_W_GODZ / nagodz;

   	for (cykl = 0; cykl < gran_cyklu; cykl++)
   	{
		if (nowyklient(min_na_kl))
	   	{
	   		if (PelnaKolejka(&kol[0]) & PelnaKolejka(&kol[0]))
	   			odeslani++;
	   		else
	   		{
	   			klienci++;
	   			tymcz = czasklienta(cykl);

	   			if (LiczbaPozycji(&kol[0]) <= LiczbaPozycji(&kol[1]))
	   				Ustaw(tymcz, &kol[0]);
	   			else 
	   				Ustaw(tymcz, &kol[1]);
	   		}
	   	}

	   	if (czas_czek1 <= 0 && !PustaKolejka(&kol[0]))
	   	{
	   		Odlacz(&tymcz, &kol[0]);
	   		czas_czek1 = tymcz.czaskons;
	   		kol_czek1 += cykl - tymcz.przybycie;
	   		obsluzeni1++;
	   	}

	   	if (czas_czek2 <= 0 && !PustaKolejka(&kol[1]))
	   	{
	   		Odlacz(&tymcz, &kol[1]);
	   		czas_czek2 = tymcz.czaskons;
	   		kol_czek2 += cykl - tymcz.przybycie;
	   		obsluzeni2++;
	   	}

	   	if (czas_czek1 > 0)
	   		czas_czek1--;

	   	if (czas_czek2 > 0)
	   		czas_czek2--;

	   	suma_kol1 += LiczbaPozycji(&kol[0]);
	   	suma_kol2 += LiczbaPozycji(&kol[1]);
   	}

   	if (klienci > 0)
   	{
	   	printf("klienci przyjeci do kolejek: %ld\n", klienci);
	   	printf("klienci odeslani: %ld\n", odeslani);
   		printf("klienci obsluzeni w kolejce 1: %ld\n", obsluzeni1);
   		printf("srednia dlugosc kolejki 1: %.2f\n", (double) suma_kol1 / gran_cyklu);
   		printf("sredni czas oczekiwania kolejki 1: %.2f minut\n", (double) kol_czek1 / obsluzeni1);
   		printf("srednia dlugosc kolejki 2: %.2f\n", (double) suma_kol2 / gran_cyklu);
   		printf("sredni czas oczekiwania kolejki 2: %.2f minut\n", (double) kol_czek2 / obsluzeni2);
   		printf("klienci obsluzeni w kolejce 2: %ld\n", obsluzeni2);
   	}
   	else
   		puts("Brak klientow!");

	for (int i = 0; i < ROZMIAR; i++)
		WyczyscKolejke(&kol[i]);

   	puts("Do widzenia.");

   	return 0;
}

bool nowyklient(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Pozycja czasklienta(long kiedy)
{
	Pozycja klient;

	klient.czaskons = rand() % 3 + 1;
	klient.przybycie = kiedy;

	return klient;
}