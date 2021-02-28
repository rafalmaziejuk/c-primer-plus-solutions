#include <stdio.h>
#include <string.h>

#define MAXDL 40
#define ILOSC 3
   
struct Osoba
{
	char imie1[MAXDL];
	char imie2[MAXDL];
	char nazwisko[MAXDL];
};

struct Obywatel
{
	unsigned long pesel;
	struct Osoba osoba;
};

void pokaz(const struct Obywatel *o);

int main(void)
{
    struct Obywatel obywatele[ILOSC] =
    {
    	{ 12345678911, "imie1", "imie2", "nazwisko" },
    	{ 12345678912, "imie1", " ", "nazwisko" },
    	{ 12345678913, "imie1", "imie2", "nazwisko" }
    };

    for (int i = 0; i < ILOSC; i++)
    	pokaz(obywatele + i);

	return 0;
}

void pokaz(const struct Obywatel *o)
{
	if (strcmp(o->osoba.imie2, " ") != 0)
		printf("%s, %s %c. -- %lu\n", o->osoba.nazwisko, o->osoba.imie1, o->osoba.imie2[0], o->pesel);
	else
		printf("%s, %s    -- %lu\n", o->osoba.nazwisko, o->osoba.imie1, o->pesel);
}
