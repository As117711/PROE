#ifndef OBSLUGA_PODATKOW_H
#define OBSLUGA_PODATKOW_H
#include<iostream>
using namespace std;
///Klasa umozliwiajaca obsluge podatkow.
/**
    Zawiera informacje o podatkach, umozliwia zmiane wysokosci podatkow.
*/
class Obsluga_podatkow{
	private:
		int cena_prad[4]; ///<- Wysokosc Oplaty za prad. (w indeksie wpisujemy rodzaj budynku.(1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty. )
		int cena_gaz[4]; ///<- Wysokosc Oplaty za prad. (w indeksie wpisujemy rodzaj budynku. (1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty.)
		int cena_woda[4]; ///<- Wysokosc Oplaty za prad. (w indeksie wpisujemy rodzaj budynku.(1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty.))
		int cena_czynsz[4];///<- Wysokosc Oplaty za prad. (w indeksie wpisujemy rodzaj budynku.(1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty.))
	public:
        ///Kontruktor domyslny
		Obsluga_podatkow();

        ///Funkcja umozliwiajaca zmiane oplaty za prad
        /**
        \param rodzaj budynku (1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty.
        */
		void zmien_cene_prad(int,int);
        ///Funkcja umozliwiajaca zmiane oplaty za gaz
        /**
        \param rodzaj budynku (1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty.
        */
		void zmien_cene_gaz(int,int);
        ///Funkcja umozliwiajaca zmiane oplaty za wode
        /**
        \param rodzaj budynku (1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty.
        */
		void zmien_cene_woda(int,int);
        ///Funkcja umozliwiajaca zmiane oplaty za czynsz
        /**
        \param rodzaj budynku (1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec) , wysokosc oplaty.
        */
		void zmien_cene_czynsz(int,int);

        ///Funkcja zwracajaca oplaty za prad
        /**
        \param rodzaj budynku. 1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec
        \return wysokosc oplaty
        */
		int zwroc_cene_prad(int);
        ///Funkcja zwracajaca oplaty za gaz
        /**
        \param rodzaj budynku. 1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec
        \return wysokosc oplaty
        */
		int zwroc_cene_gaz(int);
        ///Funkcja zwracajaca oplaty za wode
        /**
        \param rodzaj budynku. 1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec
        \return wysokosc oplaty
        */
		int zwroc_cene_woda(int);
        ///Funkcja zwracajaca oplaty za czynsz
        /**
        \param rodzaj budynku. 1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec
        \return wysokosc oplaty
        */
		int zwroc_cene_czynsz(int);
        /// Funkcja umozliwiajaca wczytanie stanu obiektu z pliku.
        void wczytaj_zPliku(istream&);
        /// Funkcja umozliwiajaca zapisanie stanu obiektu do pliku.
        void zapisz_doPliku(string);
        ///Operator strumieniowy.
		friend ostream& operator<<(ostream& ,Obsluga_podatkow &);
		///Operator strumieniowy.
		friend istream& operator>>(istream& ,Obsluga_podatkow &);
};
#endif // OBSLUGA_PODATKOW_H
