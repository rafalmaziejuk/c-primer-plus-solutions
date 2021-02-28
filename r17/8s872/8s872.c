#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "drzewo.h"

#define MAXROZ 20

char menu(void);
void dodajzw(Drzewo *wd);
void usunzw(Drzewo *wd);
void pokazzw(const Drzewo *wd);
void szukajzw(const Drzewo *wd);
void wyswpoz(Pozycja pozycja);
void duzelit(char *lan);
char * wczytaj(char *z, int ile);

int main(void)
{
    Drzewo zwierz;
    char wybor;

    InicjujDrzewo(&zwierz);

    while ((wybor = menu()) != 'q')
    {
        switch (wybor)
        {
            case 'd' :  dodajzw(&zwierz);
                        break;

            case 'w' :  pokazzw(&zwierz);
                        break;

            case 's' :  szukajzw(&zwierz);
                        break;

            case 'l' :  printf("%d zwierzat w klubie.\n", LiczbaPozycji(&zwierz));
                        break;

            case 'u' :  usunzw(&zwierz);
                        break;

            default  :  puts("Blad w instrukcji switch");
        }
    }

    puts("Do widzenia.");
    UsunWszystko(&zwierz);

    return 0;
}

char menu(void)
{
    int ch;

    puts("Klub Zwierzat Domowych - baza danych czlonkow");
    puts("Podaj litere odpowiadajaca wybranej opcji:");
    puts("d) dodaj zwierze        w) wyswietl liste zwierzat");
    puts("l) liczba zwierzat      s) szukaj zwierzecia");
    puts("u) usun zwierze         q) koniec");

    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') 
            continue;

        ch = tolower(ch);

        if (strchr("dwlsuq",ch) == NULL)
            puts("Wpisz d, w, l, s, u lub q:");
        else
            break;
    }

    if (ch == EOF)       
        ch = 'q';

    return ch;
}

void dodajzw(Drzewo *wd)
{
    Pozycja tymcz;

    if (PelneDrzewo(wd))
        puts("Brak wolnych miejsc w klubie!");
    else
    {
        puts("Podaj imie zwierzecia:");
        wczytaj(tymcz.imie, MAXROZ);

        puts("Podaj gatunek zwierzecia:");
        wczytaj(tymcz.gatunek, MAXROZ);

        duzelit(tymcz.imie);
        duzelit(tymcz.gatunek);

        DodajPozycje(&tymcz, wd);
    }
}

void pokazzw(const Drzewo *wd)
{
    if (PusteDrzewo(wd))
        puts("Brak pozycji!");
    else
        Przejdz(wd, wyswpoz);
}

void wyswpoz(Pozycja pozycja)
{
    printf("Zwierze: %-19s  Gatunek: %-19s\n", pozycja.imie, pozycja.gatunek);
}

void szukajzw(const Drzewo *wd)
{
    Pozycja tymcz;

    if (PusteDrzewo(wd))
    {
        puts("Brak pozycji!");
        return;     
    }

    puts("Podaj imie, ktore chcesz znalezc:");
    wczytaj(tymcz.imie, MAXROZ);

    duzelit(tymcz.imie);

    if (WDrzewie(&tymcz, wd))
        PokazListe(&tymcz, wd, wyswpoz);
    else
        printf("nie jest czlonkiem klubu.\n");
}

void usunzw(Drzewo *wd)
{
    Pozycja tymcz;

    if (PusteDrzewo(wd))
    {
        puts("Brak pozycji!");
        return;     
    }

    puts("Podaj imie zwierzecia, ktore chcesz usunac:");
    wczytaj(tymcz.imie, MAXROZ);

    puts("Podaj gatunek zwierzecia:");
    wczytaj(tymcz.gatunek, MAXROZ);

    duzelit(tymcz.imie);
    duzelit(tymcz.gatunek);

    printf("%s, %s ", tymcz.imie, tymcz.gatunek);

    if (UsunPozycje(&tymcz, wd))
        printf("zostal(a) usuniety/a z klubu.\n");
    else
        printf("nie jest czlonkiem klubu.\n");
}

void duzelit(char *lan)
{
    while (*lan != '\0')
    {
        *lan = toupper(*lan);
        lan++;
    }
}

char * wczytaj(char *z, int ile)
{
    char *wynik;
    char *tutaj;

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