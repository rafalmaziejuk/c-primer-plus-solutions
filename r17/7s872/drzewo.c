#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "drzewo.h"

typedef struct para 
{
    Wezel *rodzic;
    Wezel *dziecko;
} Para;

static Wezel * UtworzWezel(const Pozycja *wp);
static bool NaLewo(const Pozycja *p1, const Pozycja *p2);
static bool NaPrawo(const Pozycja *p1, const Pozycja *p2);
static void DodajWezel(Wezel *nowy, Wezel *korzen);
static void PoKolei(const Wezel *korzen, void (*wfun)(Pozycja pozycja));
static Para SzukajPozycji(const Pozycja *wp, const Drzewo *wdrzewo);
static void UsunWezel(Wezel **wsk);
static void UsunWszystkieWezly(Wezel *wsk);

void InicjujDrzewo(Drzewo *wdrzewo)
{
    wdrzewo->korzen = NULL;
    wdrzewo->rozmiar = 0;
}

bool PusteDrzewo(const Drzewo *wdrzewo)
{
    if (wdrzewo->korzen == NULL)
        return true;
    else
        return false;
}

bool PelneDrzewo(const Drzewo *wdrzewo)
{
    if (wdrzewo->rozmiar == MAXPOZ)
        return true;
    else
        return false;
}

int LiczbaPozycji(const Drzewo *wdrzewo)
{
    return wdrzewo->rozmiar;
}

bool DodajPozycje(const Pozycja *wp, Drzewo *wdrzewo)
{
    Wezel *nowy;

    if (PelneDrzewo(wdrzewo))
    {
        fprintf(stderr,"Drzewo jest pelne\n");
        return false;             
    }

    if (SzukajPozycji(wp, wdrzewo).dziecko != NULL)
    {
        SzukajPozycji(wp, wdrzewo).dziecko->pozycja.liczba_wystapien++;
        return false;             
    }

    nowy = UtworzWezel(wp);      

    if (nowy == NULL)
    {
        fprintf(stderr, "Nie mozna utworzyc wezla\n");
        return false;             
    }

    wdrzewo->rozmiar++;

    if (wdrzewo->korzen == NULL)  
        wdrzewo->korzen = nowy;   
    else                          
      DodajWezel(nowy,wdrzewo->korzen);  

    return true;             
}

bool WDrzewie(const Pozycja *wp, const Drzewo *wdrzewo)
{
    return (SzukajPozycji(wp, wdrzewo).dziecko == NULL) ? false : true;
}

bool UsunPozycje(const Pozycja *wp, Drzewo *wdrzewo)
{
    Para szuk;

    szuk = SzukajPozycji(wp, wdrzewo);

    if (szuk.dziecko == NULL)
        return false;

    if (szuk.rodzic == NULL)      
        UsunWezel(&wdrzewo->korzen);
    else if (szuk.rodzic->lewy == szuk.dziecko)
        UsunWezel(&szuk.rodzic->lewy);
    else
        UsunWezel(&szuk.rodzic->prawy);

    wdrzewo->rozmiar--;

    return true;
}

void Przejdz(const Drzewo *wdrzewo, void (*wfun)(Pozycja pozycja))
{
    if (wdrzewo != NULL)
        PoKolei(wdrzewo->korzen, wfun);
}

void UsunWszystko(Drzewo *wdrzewo)
{
    if (wdrzewo != NULL)
        UsunWszystkieWezly(wdrzewo->korzen);

    wdrzewo->korzen = NULL;
    wdrzewo->rozmiar = 0;
}

int LiczbaWystapien(const Pozycja *wp, const Drzewo *wdrzewo)
{
    Para szuk;

    szuk = SzukajPozycji(wp, wdrzewo);

    return szuk.dziecko->pozycja.liczba_wystapien;
}

static void PoKolei(const Wezel *korzen, void (*wfun)(Pozycja pozycja))
{
    if (korzen != NULL)
    {
        PoKolei(korzen->lewy, wfun);
        (*wfun)(korzen->pozycja);
        PoKolei(korzen->prawy, wfun);
    }
}

static void UsunWszystkieWezly(Wezel *wsk)
{
    Wezel *wprawy;

    if (wsk != NULL)
    {
        wprawy = wsk->prawy;
        UsunWszystkieWezly(wsk->lewy);
        free(wsk);
        UsunWszystkieWezly(wprawy);
    }
}

static void DodajWezel(Wezel *nowy, Wezel *korzen)
{
    if (NaLewo(&nowy->pozycja, &korzen->pozycja))
    {
        if (korzen->lewy == NULL)       
            korzen->lewy = nowy;        
        else
            DodajWezel(nowy, korzen->lewy); 
    }                                       
                        
    else if (NaPrawo(&nowy->pozycja, &korzen->pozycja))
    {
        if (korzen->prawy == NULL)
            korzen->prawy = nowy;
        else
            DodajWezel(nowy, korzen->prawy);
    }
    else                  
    {
        fprintf(stderr,"Blad funkcji DodajWezel()\n");
        exit(1);
    }
}

static bool NaLewo(const Pozycja *p1, const Pozycja *p2)
{
    int porown1;

    if ((porown1 = strcmp(p1->slowo, p2->slowo)) < 0)
        return true;
    else
        return false;
}

static bool NaPrawo(const Pozycja *p1, const Pozycja *p2)
{
    int porown1;

    if ((porown1 = strcmp(p1->slowo, p2->slowo)) > 0)
        return true;
    else
        return false;
}

static Wezel * UtworzWezel(const Pozycja *wp)
{
    Wezel *nowy;

    nowy = (Wezel *)malloc(sizeof(Wezel));

    if (nowy != NULL)
    {
        nowy->pozycja = *wp;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
    }

    return nowy;
}

static Para SzukajPozycji(const Pozycja *wp, const Drzewo *wdrzewo)
{
    Para szuk;

    szuk.rodzic = NULL;
    szuk.dziecko = wdrzewo->korzen;

    if (szuk.dziecko == NULL)
        return szuk;                

    while (szuk.dziecko != NULL)
    {
        if (NaLewo(wp, &(szuk.dziecko->pozycja)))
        {
            szuk.rodzic = szuk.dziecko;
            szuk.dziecko = szuk.dziecko->lewy;
        }
        else if (NaPrawo(wp, &(szuk.dziecko->pozycja)))
        {
            szuk.rodzic = szuk.dziecko;
            szuk.dziecko = szuk.dziecko->prawy;
        }
        else     
            break;                   
    }                
                        
    return szuk;      
}

static void UsunWezel(Wezel **wsk)
{
    Wezel *tymcz;

    if ((*wsk)->lewy == NULL)
    {
        tymcz = *wsk;
        *wsk = (*wsk)->prawy;
        free(tymcz);
    }
    else if ((*wsk)->prawy == NULL)
    {
        tymcz = *wsk;
        *wsk = (*wsk)->lewy;
        free(tymcz);
    }
    else    
    {
        for (tymcz = (*wsk)->lewy; tymcz->prawy != NULL; tymcz = tymcz->prawy)
            continue;

        tymcz->prawy = (*wsk)->prawy;
        tymcz = *wsk;
        *wsk = (*wsk)->lewy;

        free(tymcz);
    }
}