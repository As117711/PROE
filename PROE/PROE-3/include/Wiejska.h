#ifndef WIEJSKA_H
#define WIEJSKA_H
#include "Zarzadzanie_wspoldzielnia.h"
#include "Remiza.h"

///Klasa wiejska poszerze mozliwosci klasy bazowej o posiadanie "remizy".
class Wiejska : public Zarzadanie_wspoldzielnia
{
    public:

        void wczytaj_zPliku();
        void zapisz_doPliku();
        ///Funkcja umozliwiajaca dodanie krzesel.
        void kup_krzesla();
        ///Funkcja umozliwiajaca dodanie stolikow.
        void kup_stoliki();
        ///Funkcja umozliwiajaca dodanie stolu bilardowego.
        void kup_stol_bilardowy();
        ///Funkcja umozliwiajaca dodanie stolu pingpongowego.
        void kup_stol_pingpongowy();
        ///Funkcja wyswietla informacje o remizie.
        void info_remiza();
        ///Funkcja wyswietlajaca informacje i spoldzielni.
        void info_wspoldzielnia();

    private:

        Remiza remiza; ///Obiekt remiza.

};

#endif // WIEJSKA_H
