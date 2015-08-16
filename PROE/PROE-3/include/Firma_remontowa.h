#ifndef FIRMA_REMONTOWA_H
#define FIRMA_REMONTOWA_H
#include<string>
using namespace std;
///Klasa firmy remontowej
/**
    Klasa umozliwia przeprowadzanie remontow
    budynkow w wspoldzielni.
*/
class Firma_remontowa{
	private:

		int cena[4]; ///<- tablica z cenami uslug dla poszczegolnych rodzajow budynku (1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec)
		string nazwa; ///<- zmienna przechowywujaca nazwe firmy remontowej wspoldzielni.
	public:
        ///Konstruktor domysly
		Firma_remontowa();
        ///Funkcja zwracajaca cene rodzaju budynku.
        /**
            \param rodzaj budynku. 1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec
            \return Zwraca cene uslugi.
        */
		int zwroc_cene(int);
		///Funkcja zwracajaca nazwe firmy remontowej.
		/**
		\return Zwraca nazwe firmy.
		*/
		string zwroc_nazwe();
		///Funkcja wyswietlajaca informacje o firmie
		void info_firma();
		///Funkcja umozliwiajaca zmiane nazwy firmy
		void zmien_nazwe(string&);
		///Funkcja umozliwiajaca zmiane ceny uslugi
		/**
            \param pierwszy argument okresla rodzaj budynku
            \param drugi nowa cene uslugi.
		*/
		void zmien_cene(int ,int);

        /// Funkcja umozliwiajaca wczytanie stanu obiektu z pliku.
        void wczytaj_zPliku(istream&);
        /// Funkcja umozliwiajaca zapisanie stanu obiektu do pliku.
        void zapisz_doPliku(string);
        ///Operator strumieniowy
		friend ostream& operator<<(ostream& ,Firma_remontowa &);
		///Operator strumieniowy
        friend istream& operator>>(istream& ,Firma_remontowa &);
};
#endif // FIRMA_REMONTOWA_H
