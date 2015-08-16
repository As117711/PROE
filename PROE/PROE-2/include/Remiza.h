#ifndef REMIZA_H
#define REMIZA_H
#include<iostream>
using namespace std;
///Klasa symulujaca wiejska remize.
class Remiza
{
    public:
    ///Konstruktor domyslny
            Remiza();
            ///Zwieksza liczbe krzesel w remizie
            /**
            \param Informacja o ile zwiekszamy ilosc krzesel.
            */
            void zwieksz_liczbe_krzesel(int);
            ///Zwieksza liczbe stolikow w remizie
            /**
            \param Informacja o ile zwiekszamy ilosc stolikow.
            */
            void zwieksz_liczbe_stolikow(int);
            ///Funkcja umozliwiajaca dodanie stolu bilarowego do remizy.
            void kup_stol_bilardowy();
            ///Funkcja umozliwiajaca dodanie stolu pingpongowego do remizy.
            void kup_stol_pingpongowy();

            /// Funkcja umozliwiajaca wczytanie stanu obiektu z pliku.
            void wczytaj_zPliku(istream &);
            /// Funkcja umozliwiajaca zapisanie stanu obiektu do pliku.
            void zapisz_doPliku(string);
            ///Funkcja zwracajaca ilosc krzesel
            /**
            \return ilosc krzesel
            */
            int ile_krzesel();
            ///Funkcja zwracajaca ilosc stolikow
            /**
            \return ilosc stolikow
            */
            int ile_stolikow();
            ///Funkcja zwracajaca informacje czy jest bilard w remizie.
            /**
            Tak - True, Nie - False
            */
            bool czy_jest_bilard();
            ///Funkcja zwracajaca informacje czy jest pingpong w remizie.
            /**
            Tak - True, Nie - False
            */
            bool czy_jest_pingpong();
            ///Funkcja wyswietlajaca informacje o remizie.
            void info_remiza();
            ///Operator strumieniowy.
            friend ostream& operator<<(ostream& ,Remiza &);
            ///Operator strumieniowy.
            friend istream& operator>>(istream& ,Remiza &);

    private:
            bool stol_bilardowy; ///<- Informacja czy jest stol bilardowy.
            bool stol_pingpongowy; ///<- Informacja czy jest stol pingpongowy.
            int liczba_krzesel; /// Zmienna przechowywujaca ilosc krzesel.
            int liczba_stolikow; /// Zmienna przechowywujaca ilosc stolikow.

};

#endif // REMIZA_H
