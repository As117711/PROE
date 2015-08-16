#ifndef ZARZADZANIE_BUDYNKAMI_H
#define ZARZADZANIE_BUDYNKAMI_H
#include "Budynek.h"
#include "Wyjatek.h"
#include <vector>
using namespace std;
///Klasa abstrakcyjna.
class Zarzadzanie_budynkami
{
    public:
        ///Funkcja wyswietlajaca informacje o budynkach.
        void info_lista_budynkow();
        ///Funkcja umozliwiajaca dodanie budynku do spoldzielni.
		void dodaj_budynek();
		///Funkcja umozliwiajaca usuniecie budynku ze spoldzielni.
		bool usun_budynek();

        ///Funkcja czysto wirtualna, umozliwiajaca wczytanie z pliku.
        virtual void wczytaj_zPliku() = 0;
        ///Funkcja czysto wirtualna, umozliwiajaca zapisanie do pliku.
        virtual void zapisz_doPliku() = 0;
        ///Funkcja wirtualna umozliwiajaca wyswieltlenie informacji o spoldzielni.
        virtual void info_wspoldzielnia() = 0;

    protected:
        vector<Budynek> budynki; ///<- Wektor budynkow spoldzielni.

};

#endif // ZARZADZANIE_BUDYNKAMI_H
