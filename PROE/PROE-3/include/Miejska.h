#ifndef MIEJSKA_H
#define MIEJSKA_H
#include "Zarzadzanie_wspoldzielnia.h"
#include "Sklep.h"
///Klasa miejska, dziedziczaca po klasie Zarzadzanie_wspoldzielnia.
/**
    Klasa poszerzajaca klase bazowa o posiadanie pasazu handlowego (zbioru sklepow).
*/

class Miejska: public Zarzadanie_wspoldzielnia
{
    public:
        /// Funkcja umozliwiajaca wczytanie stanu obiektu z pliku.
        void wczytaj_zPliku();
        /// Funkcja umozliwiajaca zapisanie stanu obiektu do pliku.
        void zapisz_doPliku();

        ///Funkcja umozliwiajaca dodanie sklepu do spoldzielni.
        void dodaj_sklep();
        ///Funkcja umozliwiajaca usuniecie sklepu ze spoldzielni.
        void usun_sklep();
        ///Funkcja wypisujaca liste sklepow.
        void wyswietl_liste_sklepow();


    private:

        vector<Sklep> pasaz_handlowy;///<-Wektor sklepow.

};

#endif // MIEJSKA_H
