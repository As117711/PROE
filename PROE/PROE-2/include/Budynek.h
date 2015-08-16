#ifndef BUDYNEK_H
#define BUDYNEK_H
#include<iostream>
using namespace std;
///Klasa budynek
/**
    Klasa Umozliwiajaca tworzenie budynkow oraz
    zarzadzania nimi.
*/
class Budynek
{
    protected:
        int rodzaj; ///<- Zmienna okreslajaca rodzaj budynku. (1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec)
        char stan; ///<- Zmienna Okreslajaca stan budynku w skali od 1 do 10.
    public:
        ///Konstruktor.
        /**
            Umozliwia stworzenie obiektu z okreslonym stanem poczatkowym. r-rodzaj, s-stan.
        */
        Budynek(int r = 0, char s = 0);
        //virtual ~Budynek();    brak dynamicznej pamieci.
        int zwrocRodzaj(); ///<-Funkcja zwracajaca rodzaj budynku.
        char zwrocStan(); ///<-Funkcja zwracajaca stan budynku.
        /// Funkcja umozliwiajaca wczytanie stanu obiektu z pliku.
        virtual void wczytaj_zPliku(istream &);
        /// Funkcja umozliwiajaca zapisanie stanu obiektu do pliku.
        virtual void zapisz_doPliku(string);
        /// Funkcja zwiekszenie stanu budynku.
        void poprawStan(int);
        ///Operator strumieniowy.
        friend ostream& operator<<(ostream& ,Budynek &);
        ///Operator strumieniowy.
        friend istream& operator>>(istream& ,Budynek &);
};

#endif // BUDYNEK_H
