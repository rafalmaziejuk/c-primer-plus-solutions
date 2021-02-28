#include <string.h>
#include <stdio.h>
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
static void PrzejdzListe(const Lista *wlista, void (*wfun)(Pozycja pozycja));
static Para SzukajPozycji(const Pozycja *wp, const Drzewo *wdrzewo);
static bool SzukajLiscia(const Pozycja *wp, const Lista *wlista);
static bool UsunLisc(const Pozycja *wp, Wezel **wsk);
static void UsunWszystkieWezly(Wezel *wsk);
static void CzyscListe(Lista *wlista);
static bool DodajLisc(Pozycja wp, Lista *wlista);

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
    Wezel *pom;

    pom = SzukajPozycji(wp, wdrzewo).dziecko;

    if (PelneDrzewo(wdrzewo))
    {
        fprintf(stderr,"Drzewo jest pelne\n");
        return false;             
    }

    if (pom != NULL)
    {
        if (NaLewo(wp, &pom->glowny->pozycja) == 0 && NaPrawo(wp, &pom->glowny->pozycja) == 0)
            if (!SzukajLiscia(wp, &pom->glowny))
            {
                DodajLisc(*wp, &pom->glowny);
                wdrzewo->rozmiar++;
                return true;
            }

        fprintf(stderr, "Proba dodania istniejacej pozycji\n");
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
      DodajWezel(nowy, wdrzewo->korzen); 

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
    {
        if (SzukajLiscia(wp, &wdrzewo->korzen->glowny))
            UsunLisc(wp, &wdrzewo->korzen);
        else
            return false;
    }
    else if (szuk.rodzic->lewy == szuk.dziecko)
    {
        if (SzukajLiscia(wp, &szuk.rodzic->lewy->glowny))
            UsunLisc(wp, &szuk.rodzic->lewy);
        else
            return false;
    }
    else
    {
        if (SzukajLiscia(wp, &szuk.rodzic->prawy->glowny))
            UsunLisc(wp, &szuk.rodzic->prawy);
        else
            return false;
    }

    wdrzewo->rozmiar--;

    if (wdrzewo->rozmiar == 0)
        wdrzewo->korzen = NULL;

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

void PokazListe(const Pozycja *wp, const Drzewo *wdrzewo, void (*wfun)(Pozycja pozycja))
{
    Lista wsk = SzukajPozycji(wp, wdrzewo).dziecko->glowny;

    PrzejdzListe(&wsk, wfun);
}

static void PoKolei(const Wezel *korzen, void (*wfun)(Pozycja pozycja))
{
    if (korzen != NULL)
    {
        PoKolei(korzen->lewy, wfun);
        PrzejdzListe(&korzen->glowny, wfun);
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
        CzyscListe(&wsk->glowny);
        UsunWszystkieWezly(wprawy);
    }
}

static void DodajWezel(Wezel *nowy, Wezel *korzen)
{
    if (NaLewo(&nowy->glowny->pozycja, &korzen->glowny->pozycja))
    {
        if (korzen->lewy == NULL)       
            korzen->lewy = nowy;        
        else
            DodajWezel(nowy, korzen->lewy); 
    }                                       
    else if (NaPrawo(&nowy->glowny->pozycja, &korzen->glowny->pozycja))
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

    if ((porown1 = strcmp(p1->imie, p2->imie)) < 0)
        return true;
    else
        return false;
}

static bool NaPrawo(const Pozycja *p1, const Pozycja *p2)
{
    int porown1;

    if ((porown1 = strcmp(p1->imie, p2->imie)) > 0)
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
        nowy->glowny = NULL;
        DodajLisc(*wp, &nowy->glowny);
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
        if (NaLewo(wp, &(szuk.dziecko->glowny->pozycja)))
        {
            if (SzukajLiscia(wp, &(szuk.dziecko->glowny)))
                return szuk;

            szuk.rodzic = szuk.dziecko;
            szuk.dziecko = szuk.dziecko->lewy;
        }
        else if (NaPrawo(wp, &(szuk.dziecko->glowny->pozycja)))
        {
            if (SzukajLiscia(wp, &(szuk.dziecko->glowny)))
                return szuk;

            szuk.rodzic = szuk.dziecko;
            szuk.dziecko = szuk.dziecko->prawy;
        }
        else     
            break;    
    }        

    return szuk;      
}

static void PrzejdzListe(const Lista *wlista, void (*wfun)(Pozycja pozycja))
{
    Lisc *wsk = *wlista;   

    while (wsk != NULL)
    {
        (*wfun)(wsk->pozycja);   
        wsk = wsk->nast;         
    }
}

static void CzyscListe(Lista *wlista)
{
   Lisc *wsk;

   while (*wlista != NULL)
   {
      wsk = (*wlista)->nast;   
      free(*wlista);           
      *wlista = wsk;         
   }
}

static bool SzukajLiscia(const Pozycja *wp, const Lista *wlista)
{
    Lisc *szuk = *wlista;

    while (szuk != NULL)
    {
        if (strcmp(wp->imie, szuk->pozycja.imie) == 0 && strcmp(wp->gatunek, szuk->pozycja.gatunek) == 0)
            return true;

        szuk = szuk->nast;
    }

    return false;
}

static bool UsunLisc(const Pozycja *wp, Wezel **wsk)
{
    if (!SzukajLiscia(wp, &(*wsk)->glowny))
        return false;

    Lisc *szuk = (*wsk)->glowny;
    Lisc *poprz;
    int porown = strcmp(wp->imie, szuk->pozycja.imie) == 0 && strcmp(wp->gatunek, szuk->pozycja.gatunek) == 0;

    if (porown == 1 && szuk->nast == NULL)
    {
        Wezel *tymcz;

        if ((*wsk)->lewy == NULL)
        {
            tymcz = *wsk;
            *wsk = (*wsk)->prawy;
            CzyscListe(&tymcz->glowny);
            free(tymcz);
        }
        else if ((*wsk)->prawy == NULL)
        {
            tymcz = *wsk;
            *wsk = (*wsk)->lewy;
            CzyscListe(&tymcz->glowny);
            free(tymcz);
        }
        else
        {
            for (tymcz = (*wsk)->lewy; tymcz->prawy != NULL; tymcz = tymcz->prawy)
                continue;

            tymcz->prawy = (*wsk)->prawy;
            tymcz = *wsk;
            *wsk =(*wsk)->lewy;
            CzyscListe(&tymcz->glowny);
            free(tymcz);
        }
    }
    else if (porown == 1 && szuk->nast != NULL)
    {
        (*wsk)->glowny = szuk->nast;
        free(szuk);
    }
    else 
    {
        while (szuk != NULL)
        {
            if (strcmp(wp->imie, szuk->pozycja.imie) == 0 && strcmp(wp->gatunek, szuk->pozycja.gatunek) == 0)
                break;

            poprz = szuk;
            szuk = szuk->nast;
        }

        poprz->nast = szuk->nast;
        free(szuk);
    }

    return true;
}

static bool DodajLisc(Pozycja wp, Lista *wlista)
{
    Lisc *wnowy;
    Lisc *szuk = *wlista;

    wnowy = (Lisc *)malloc(sizeof(Lisc));

    if (wnowy == NULL)
        return false;

    wnowy->pozycja = wp;
    wnowy->nast = NULL;

    if (szuk == NULL)       
        *wlista = wnowy;     
    else
    {
        while (szuk->nast != NULL)
            szuk = szuk->nast;   

        szuk->nast = wnowy;     
    }

    return true;
}