#ifndef _STOS_H_
#define _STOS_H_

#include <stdbool.h>  

typedef char Pozycja;

typedef struct wezel
{
	Pozycja pozycja;
	struct wezel *poprz;
} Wezel;

typedef struct stos
{
	Wezel *gora;
} Stos;

void InicjujStos(Stos *wstos);
bool PustyStos(const Stos *wstos);
bool DodajPozycje(Pozycja pozycja, Stos *wstos);
bool ZdejmijPozycje(Stos *wstos);

#endif