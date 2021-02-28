#include <stdio.h>
#include <string.h>

#define MAXTYT   40
#define MAXAUT   40
#define MAXKS   100     

struct ksiazka 
{               
	char tytul[MAXTYT];
	char autor[MAXAUT];
	float wartosc;
};

char * wczytaj(char * z, int ile);
void swap(struct ksiazka *a, struct ksiazka *b);
void sortuj_tytul(struct ksiazka *s[], int n);
float wartosc(struct ksiazka s[], int n);

int main(void)
{
    struct ksiazka bibl[MAXKS]; 
    struct ksiazka *kopia[MAXKS];
	int licznik = 0;
	int index;
	int calkowita_wartosc;

	printf("Podaj tytul ksiazki.\n");
	printf("Aby zakonczyc, wcisnij nacisni j [enter] na poczatku wiersza.\n");
	while (licznik < MAXKS && wczytaj(bibl[licznik].tytul, MAXTYT) != NULL && bibl[licznik].tytul[0] != '\0')
	{
		printf("Teraz podaj autora.\n");
		wczytaj(bibl[licznik].autor, MAXTYT);
		printf("Teraz podaj wartosc.\n");
		scanf("%f", &bibl[licznik++].wartosc);

		while (getchar() != '\n')
			continue;               

		if (licznik < MAXKS)
			printf("Podaj kolejny tytul.\n");
	}

	for (int i = 0; i < licznik; i++)
		kopia[i] = &bibl[i];

	if (licznik > 1)
		sortuj_tytul(kopia, licznik);

	calkowita_wartosc = wartosc(bibl, licznik);

	printf("Calkowita wartosc ksiazek to %.2f.\n", calkowita_wartosc);

	if (licznik > 0)
	{
		printf("Oto lista Twoich ksiazek:\n");
		for (index = 0; index < licznik; index++)
			printf("%s, autor: %s, cena: %.2f zl\n", kopia[index]->tytul, kopia[index]->autor, kopia[index]->wartosc);
	}
	else
		printf("Zadnych ksiazek? Szkoda\n");

	return 0;
}

char * wczytaj(char *z, int ile)
{
	char * wynik;
	char * tutaj;

	wynik = fgets(z, ile, stdin);

	if (wynik)
	{
        tutaj = strchr(z, '\n'); 

        if (tutaj) 
            *tutaj = '\0';
        else
        	while (getchar() != '\n')
        		continue;
    }

        return wynik;
}

void sortuj_tytul(struct ksiazka *s[], int n)
{
	struct ksiazka *temp;

	for(int i = 0; i < n; i++)
		for(int j = 1; j < n - i; j++) 
			if(strcmp(s[j - 1]->tytul, s[j]->tytul) > 0)
			{
				temp = s[j - 1];
				s[j - 1] = s[j];
				s[j] = temp;
			}
}

float wartosc(struct ksiazka s[], int n)
{
	float suma = 0;

	for (int i = 0; i < n; i++)
		suma += s[i].wartosc;

	return suma;
}