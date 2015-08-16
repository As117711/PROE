#include "../include/Budynek.h"
#ifndef LISTA_BUDYNKOW_H
#define LISTA_BUDYNKOW_H
using namespace std;
class Lista_budynkow{
	private:
		Budynek *pierwszy;
		Budynek *ostatni;
		int liczba_budynkow;
	public:
		Lista_budynkow();
		~Lista_budynkow();
		Lista_budynkow(const Lista_budynkow &);

		void dodaj(int,char);
		bool usun(int);
		int zwroc_liczbe_budynkow();
		Budynek *zwroc_pierwszy();
};
#endif // LISTA_BUDYNKOW_H
