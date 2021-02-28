#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdbool.h>    

#define ROZT 45    

struct film
{
	char tytul[ROZT];
	int ocena;
};

typedef struct film Pozycja;

typedef struct wezel
{
	Pozycja pozycja;
	struct wezel * nast;
} Wezel;

typedef struct lista
{
	Wezel *glowny;
	Wezel *koniec;
} Lista;

void InicjujListe(Lista *wlista);
void Przejdz (const Lista *wlista, void (*wfun)(Pozycja pozycja));
void CzyscListe(Lista *wlista);
bool PustaLista(const Lista *wlista);
bool PelnaLista(const Lista *wlista);
bool DodajPozycje(Pozycja pozycja, Lista *wlista);
unsigned int LiczbaPozycji(const Lista *wlista);

#endif