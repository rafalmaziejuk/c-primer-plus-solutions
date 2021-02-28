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

void pokaz(const struct Obywatel o[], int n);

int main(void)
{
    struct Obywatel obywatele[ILOSC] =
    {
    	{ 12345678911, "imie1", "imie2", "nazwisko" },
    	{ 12345678912, "imie1", " ", "nazwisko" },
    	{ 12345678913, "imie1", "imie2", "nazwisko" }
    };

    pokaz(obywatele, ILOSC);

	return 0;
}

void pokaz(const struct Obywatel o[], int n)
{
	for (int i = 0; i < n; i++)	
		if (strcmp(o[i].osoba.imie2, " ") != 0)
			printf("%s, %s %c. -- %lu\n", o[i].osoba.nazwisko, o[i].osoba.imie1, o[i].osoba.imie2[0], o[i].pesel);
		else
			printf("%s, %s    -- %lu\n", o[i].osoba.nazwisko, o[i].osoba.imie1, o[i].pesel);
}