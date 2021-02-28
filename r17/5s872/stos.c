#include <stdio.h>
#include <stdlib.h>
#include "stos.h"

static void KopiujDoWezla(Pozycja pozycja, Wezel *wwezel);

void InicjujStos(Stos *wstos)
{
    wstos->gora = NULL;
}

bool PustyStos(const Stos *wstos)
{
    if (wstos->gora == NULL)
        return true;
    else
        return false;
}

bool DodajPozycje(Pozycja pozycja, Stos *wstos)
{
    Wezel *wnowy;
    Wezel *biezaca_gora = wstos->gora;

    wnowy = (Wezel *)malloc(sizeof(Wezel));

    if (wnowy == NULL)
        return false;  

    KopiujDoWezla(pozycja, wnowy);

    if (wstos->gora == NULL) 
        wstos->gora = wnowy;
    else
    {
        wstos->gora = wnowy;
        wstos->gora->poprz = biezaca_gora;
    }

    return true;
}

bool ZdejmijPozycje(Stos *wstos)
{
    if (PustyStos(wstos))
        return false;

    putchar(wstos->gora->pozycja);

    Wezel *pom = wstos->gora->poprz;

    free(wstos->gora);
    wstos->gora = pom;

    return true;
}

static void KopiujDoWezla(Pozycja pozycja, Wezel *wwezel)
{
    wwezel->pozycja = pozycja;
}