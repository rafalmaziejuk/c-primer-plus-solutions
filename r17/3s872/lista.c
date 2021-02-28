#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static void KopiujDoWezla(Pozycja pozycja, Wezel *wwezel);

void InicjujListe(Lista *wlista)
{
   wlista->pozycje = 0;
}

bool PustaLista(const Lista *wlista)
{
   if (wlista->pozycje == 0)
      return true;
   else
      return false;
}

bool PelnaLista(const Lista *wlista)
{
   if (wlista->pozycje == MAXROZM)
      return true;
   else
      return false;
}

unsigned int LiczbaPozycji(const Lista *wlista)
{
   return wlista->pozycje;
}

bool DodajPozycje(Pozycja pozycja, Lista *wlista)
{
   unsigned int indeks = wlista->pozycje;

   if (PelnaLista(wlista))
      return false;

   if (wlista->pozycje == 0)
      indeks = 0;

   wlista->wpisy[indeks] = pozycja;
   wlista->pozycje++;

   return true;
}

void Przejdz(const Lista *wlista, void (*wfun)(Pozycja pozycja))
{
   unsigned int indeks = 0;

   while (indeks < wlista->pozycje)
   {
      (*wfun)(wlista->wpisy[indeks]);   
      indeks++;
   }
}

void CzyscListe(Lista *wlista)
{
   wlista->pozycje = 0;
}