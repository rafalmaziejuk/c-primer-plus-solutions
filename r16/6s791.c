#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define ROZMIAR 5 
#define LEN 40 

struct osoba
{
	char imie[LEN];
	char nazwisko[LEN];
};	

void pokaz_tab(const struct osoba tab[], int n);
int porownaj(const void *w1, const void *w2);

int main(void) 
{ 
    struct osoba personel[ROZMIAR] = 
    {
    	{ "zimie", "znazwisko" },
    	{ "dimie", "dnazwisko" },
    	{ "cimie", "cnazwisko" },
    	{ "aimie", "anazwisko" },
    	{ "simie", "snazwisko" }
    };

    puts("Lista losowa:");
    pokaz_tab(personel, ROZMIAR);

    qsort(personel, ROZMIAR, sizeof(struct osoba), porownaj);

    puts("\nLista uporzadkowana:");
    pokaz_tab(personel, ROZMIAR);

    return 0;
} 

void pokaz_tab(const struct osoba tab[], int n)
{ 
    for (int index = 0; index < n; index++)
        printf("%s %s\n", tab[index].imie, tab[index].nazwisko);
}

int porownaj(const void *w1, const void *w2) 
{
    const struct osoba *a1 = (const struct osoba *)w1;
    const struct osoba *a2 = (const struct osoba *)w2;
    int wynik_porownania;

    wynik_porownania = strcmp(a1->imie, a2->imie);

    if (wynik_porownania != 0)
    	return wynik_porownania;
    else 
	    wynik_porownania = strcmp(a1->nazwisko, a2->nazwisko);

    return wynik_porownania;
}
