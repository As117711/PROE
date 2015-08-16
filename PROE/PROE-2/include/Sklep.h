#ifndef SKLEP_H
#define SKLEP_H
#include "Budynek.h"
///Klasa Sklep, poszerzajaca mozliwosci Budynku o informacje o sklepie. Domyslnie jej rodzaj to 1.
class Sklep : public Budynek
{
    public:
        ///Konstruktor.
        Sklep(char s = 0, string rs="Zwykly");
        /// Funkcja umozliwiajaca wczytanie stanu obiektu z pliku.
        void wczytaj_zPliku(istream &);
        /// Funkcja umozliwiajaca zapisanie stanu obiektu do pliku.
        void zapisz_doPliku(string);
        ///Funkcja zwracajaca rodzaj sklepu.
        /**
        \return rodzaj sklepu.
        */
        string zwroc_rodzaj_sklepu();
    private:
        string rodzaj_sklepu; ///<- Zmienna przechowywujaca rodzaj sklepu.
};

#endif // SKLEP_H
