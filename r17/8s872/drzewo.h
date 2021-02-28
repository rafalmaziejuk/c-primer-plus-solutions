#ifndef _DRZEWO_H_
#define _DRZEWO_H_

#include <stdbool.h>

#define MAXPOZ 10

typedef struct pozycja
{
    char imie[20];
    char gatunek[20];
} Pozycja;

typedef struct lisc
{
	Pozycja pozycja;
	struct lisc *nast;
} Lisc;

typedef Lisc * Lista;

typedef struct wezel
{
    Lista glowny;
    struct wezel *lewy;    
    struct wezel *prawy;   
} Wezel;

typedef struct drzewo
{
    Wezel *korzen;           
    int rozmiar;              
} Drzewo;

void InicjujDrzewo(Drzewo *wdrzewo);
bool PusteDrzewo(const Drzewo *wdrzewo);
bool PelneDrzewo(const Drzewo *wdrzewo);
int LiczbaPozycji(const Drzewo *wdrzewo);
bool DodajPozycje(const Pozycja *wp, Drzewo *wdrzewo);
bool WDrzewie(const Pozycja *wp, const Drzewo *wdrzewo);
bool UsunPozycje(const Pozycja *wp, Drzewo *wdrzewo);
void Przejdz(const Drzewo *wdrzewo, void (*wfun)(Pozycja pozycja));
void UsunWszystko(Drzewo *wdrzewo);
void PokazListe(const Pozycja *wp, const Drzewo *wdrzewo, void (*wfun)(Pozycja pozycja));

#endif