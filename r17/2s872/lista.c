#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static void KopiujDoWezla(Pozycja pozycja, Wezel *wwezel);

void InicjujListe(Lista *wlista)
{
   wlista->glowny = NULL;
   wlista->koniec = NULL;
}

bool PustaLista(const Lista *wlista)
{
   if (wlista->glowny == NULL)
      return true;
   else
      return false;
}

bool PelnaLista(const Lista *wlista)
{
   Wezel *wsk;
   bool full;

   wsk = (Wezel *)malloc(sizeof(Wezel));

   if (wsk == NULL)
      full = true;
   else
      full = false;

   free(wsk);

   return full;
}

unsigned int LiczbaPozycji(const Lista *wlista)
{
   unsigned int licznik = 0;
   Wezel *w = wlista->glowny;

   while (w != wlista->koniec)
   {
      ++licznik;
      w = w->nast;   
   }

   return licznik;
}

bool DodajPozycje(Pozycja pozycja, Lista *wlista)
{
   Wezel *wnowy;
   Wezel *szuk = wlista->glowny;
   wnowy = (Wezel *)malloc(sizeof(Wezel));

   if (wnowy == NULL)
      return false;  

   KopiujDoWezla(pozycja, wnowy);

   wnowy->nast = NULL;

   if (szuk == NULL)        
      wlista->glowny = wnowy;     
   else
   {
      while (szuk->nast != wlista->koniec)
         szuk = szuk->nast;

      szuk->nast = wnowy;     
   }

   return true;
}

void Przejdz(const Lista *wlista, void (*wfun)(Pozycja pozycja))
{
   Wezel *wsk = wlista->glowny;     

   while (wsk != NULL)
   {
      (*wfun)(wsk->pozycja);   
      wsk = wsk->nast;         
   }
}

void CzyscListe(Lista *wlista)
{
   Wezel *wsk;

   while (wlista->glowny != wlista->koniec)
   {
      wsk = wlista->glowny->nast;   
      free(wlista->glowny);           
      wlista->glowny = wsk;           
   }
}

static void KopiujDoWezla(Pozycja pozycja, Wezel *wwezel)
{
   wwezel->pozycja = pozycja;
}