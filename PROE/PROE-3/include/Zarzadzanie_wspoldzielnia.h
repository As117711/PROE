#ifndef ZARZADZANIE_WSPOLDZIELNIA_H
#define ZARZADZANIE_WSPOLDZIELNIA_H

#include "Firma_remontowa.h"
#include "Obsluga_podatkow.h"
#include "Zarzadzanie_budynkami.h"
#include <vector>

using namespace std;
/// Klasa bazowa, projektu. Symuluje dzialanie Spoldzielni mieszkaniowej.
class Zarzadanie_wspoldzielnia : public Zarzadzanie_budynkami{
	private:
        static int ilosc_wspoldzielni; ///<- Zmienna statyczna okreslajaca ilosc stworzonych spoldzielnii w programie.
	protected:
		Obsluga_podatkow podatki;  ///<- Obiekt umozliwiajacy zarzadzanie podatkami. 	//podobiekt definiowany automatycznie - hajs musi sie zgadzac
		Firma_remontowa remont; ///<- Obiekt umozliwiajacy przeprowadzanie remontow.

		int stan_konta; ///<- Zmienna przechowywujaca stan konta spoldzielni.
		string nazwa_wspoldzielni;
	public:
        ///Kontruktor domyslny.
        Zarzadanie_wspoldzielnia();
        ///Funkcja umozliwiajaca wczytanie obiektu z pliku.
        void wczytaj_zPliku();
        ///Funkcja umozliwiajaca zapisanie obiektu do pliku.
        void zapisz_doPliku();

        ///Funkcja zwracajaca ilosc stworzonych obiektow tej klasy.
		static int zwroc_ilosc_obiektow();
		///Funkcja zwracajaca stan konta spoldzielni.
		/**
		\return stan konta spoldzielni.
		*/
		int zwroc_stan_konta();
		///Funkcja zwracajaca nazwe spoldzielni.
		/**
		\return nazwa spoldzielni.
		*/
		string zwroc_nazwe();
		///Funkcja umozliwiajaca zmiane nazwy spoldzielni.
		/**
		\param Nowa nazwa.
		*/
		void ustaw_nazwe(string);
		///Funkcja umozliwiajaca zmiane stanu konta spoldzielni.
		/**
		\param Nowy stan konta.
		*/
		void ustaw_stan_konta(int);
		///Funkcja wyswietlajaca informacje o spoldzielni.
		void info_wspoldzielnia();

        ///Funkcja wyswietlajaca informacje o podatkach.
		void wyswietl_info_podatki();
		///Funkcja umozliwiajaca wyegzekwowanie podatkow.
		void zebranie_podatku();
		///Funkcja umozliwiajaca zmiane wysokosci podatkow.
		void zmien_cene_podatkow();

        ///Funkcja zwracajaca informacje o firmie remontowej spoldzielni.
		void wyswietl_info_remont();
		///Funkcja umozliwiajaca zmiane nazwy firmy spoldzielni.
		void zmien_nazwe_firmy_remontowej();
		///Funkcja umozliwiajaca zmiane ceny uslug firmy remontowej.
		void zmien_ceny_firmy_remontowej();
		///Funkcja umozliwiajaca przeprowadzanie remontu.
		void przeprowadz_remont();

        ///Operator umozliwiajacy stworzenie nowej spoldzielni, ktora ma stan konta bedacy suma.
		Zarzadanie_wspoldzielnia  operator+(const Zarzadanie_wspoldzielnia &);
		///Operator umozliwiajacy stwierdzenie ktora spoldzielnia jest bogatsza.
		bool operator>(Zarzadanie_wspoldzielnia &); // ktora wsp. jest bogatsza
		///Operator umozliwiajacy stwierdzenie ktora spoldzielnia jest biedniejsza.
		bool operator<(Zarzadanie_wspoldzielnia &); // ktora wsp. jest biedniejsza
		///Operator odpowiadajacy na pytanie czy spoldzielnie sa tak samo bogate.
		bool operator==(Zarzadanie_wspoldzielnia &); // czy sa tak samo bogate?
		///Operator umozliwiajacy zmiane nazwy spoldzielni.
		void operator[] (const string&);
		///Operator umozliwiajacy zmiane nazwy spoldzielni.
		void operator[] (const char[]);
		///Operator umozliwiajacy zmiane wysokosci stanu konta spoldzielni.
		void operator[](const int);

        ///Operator zwracajacy stan konta spoldzielni.
		operator int() const;
		///Operator Strumieniowy.
        friend ostream& operator<<(ostream& ,Zarzadanie_wspoldzielnia &);
		///Operator Strumieniowy.
		friend istream& operator>>(istream& ,Zarzadanie_wspoldzielnia &);
		///Operator zerujacy obiekt.
		void operator!(); // wyzerowanie obiektu.

};

#endif // ZARZADZANIE_WSPOLDZIELNIA_H
