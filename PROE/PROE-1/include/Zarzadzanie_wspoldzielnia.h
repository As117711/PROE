#ifndef ZARZADZANIE_WSPOLDZIELNIA_H
#define ZARZADZANIE_WSPOLDZIELNIA_H

#include "Firma_remontowa.h"
#include "Lista_budynkow.h"
#include "Obsluga_podatkow.h"
using namespace std;
class Zarzadanie_wspoldzielnia{
	private:
		Lista_budynkow *budynki;	//podobiekt tworzony dynamicznie
		Obsluga_podatkow podatki;   	//podobiekt definiowany automatycznie - hajs musi sie zgadzac
		Firma_remontowa remont;

		static int ilosc_wspoldzielni;
		int stan_konta;
		int liczba_budynkow;
		string nazwa_wspoldzielni;
	public:
		Zarzadanie_wspoldzielnia();
		Zarzadanie_wspoldzielnia(const Zarzadanie_wspoldzielnia &wspoldzielnia);
		~Zarzadanie_wspoldzielnia();

		static int zwroc_ilosc_obiektow();                //---cztery ponizsze zakodzone
		int zwroc_stan_konta();
		string zwroc_nazwe();
		void ustaw_nazwe(string);
		void ustaw_stan_konta(int);
		void info_wspoldzielnia();
						//podatki ---
		void wyswietl_info_podatki();
		void zebranie_podatku();
		void zmien_cene_podatkow();
						//remont
		void wyswietl_info_remont();
		void zmien_nazwe_firmy_remontowej();
		void zmien_ceny_firmy_remontowej();
		void przeprowadz_remont();
						//lista budynkow  ----zakodzone
		void info_lista_budynkow();
		void dodaj_budynek();
		void usun_budynek();

		Zarzadanie_wspoldzielnia& operator=(const Zarzadanie_wspoldzielnia &); // operator przypisania
		Zarzadanie_wspoldzielnia  operator+(const Zarzadanie_wspoldzielnia &);
		bool operator>(Zarzadanie_wspoldzielnia &); // ktora wsp. jest bogatsza
		bool operator<(Zarzadanie_wspoldzielnia &); // ktora wsp. jest biedniejsza
		bool operator==(Zarzadanie_wspoldzielnia &); // czy sa tak samo bogate?
		void operator[] (const string&);
		void operator[] (const char[]);
		void operator[](const int);

		operator int() const;

		void operator!(); // wyzerowanie obiektu.

        friend ostream& operator<<(ostream& ,Zarzadanie_wspoldzielnia &);
};

#endif // ZARZADZANIE_WSPOLDZIELNIA_H
