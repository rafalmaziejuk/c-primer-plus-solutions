#ifndef _KOLEJKA_H_
#define _KOLEJKA_H_
#include <stdbool.h>

#define MAXKOLEJKA 10

typedef struct pozycja 
{
	long czaskons; 
	int przybycie;
} Pozycja;

typedef struct wezel
{
	Pozycja pozycja;
	struct wezel *nast;
} Wezel;

typedef struct kolejka
{
   	Wezel *przod;   
   	Wezel *tyl;    
   	int pozycje;   
} Kolejka;

void InicjujKolejke(Kolejka *wk);
bool PelnaKolejka(const Kolejka *wk);
bool PustaKolejka(const Kolejka *wk);
int LiczbaPozycji(const Kolejka *wk);
bool Ustaw(Pozycja pozycja, Kolejka *wk);
bool Odlacz(Pozycja *wpozycja, Kolejka *wk);
void WyczyscKolejke(Kolejka *wk);

#endif