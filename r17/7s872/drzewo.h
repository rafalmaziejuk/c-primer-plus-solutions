#ifndef _DRZEWO_H_
#define _DRZEWO_H_

#include <stdbool.h>

#define MAXSLOWO 20
#define MAXPOZ 10

typedef struct pozycja
{
    char slowo[MAXSLOWO];
    unsigned int liczba_wystapien;
} Pozycja;

typedef struct wezel
{
    Pozycja pozycja;
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
int LiczbaWystapien(const Pozycja *wp, const Drzewo *wdrzewo);
bool DodajPozycje(const Pozycja *wp, Drzewo *wdrzewo);
bool WDrzewie(const Pozycja *wp, const Drzewo *wdrzewo);
bool UsunPozycje(const Pozycja *wp, Drzewo *wdrzewo);
void Przejdz(const Drzewo *wdrzewo, void (*wfun)(Pozycja pozycja));
void UsunWszystko(Drzewo *wdrzewo);

#endif