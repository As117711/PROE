#include "../include/Lista_budynkow.h"
#include<iostream>
Lista_budynkow::Lista_budynkow(){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora klasy Lista_budynkow" << endl << endl;
	#endif
	pierwszy=ostatni=NULL;
	liczba_budynkow=0;
}

Budynek* Lista_budynkow::zwroc_pierwszy(){
	return pierwszy;
}

Lista_budynkow::Lista_budynkow(const Lista_budynkow &kopia){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora kopiujacego klasy Lista_budynkow" << endl << endl;
	#endif

	pierwszy=NULL;
	ostatni=NULL;

	Budynek *pomoc = kopia.pierwszy;
	while(pomoc!=NULL){
		dodaj(pomoc->rodzaj,pomoc->stan_budynku);
		pomoc=pomoc->sasiad;
	}
}

Lista_budynkow::~Lista_budynkow(){
	#ifdef _DEBUG
		cout << "Wywolanie destruktora klasy Lista_budynkow" << endl << endl;
	#endif
    Budynek *p = pierwszy;
	while(p!=NULL){
		pierwszy=p;
		p=p->sasiad;
		delete pierwszy;
	}
}



void Lista_budynkow::dodaj(int rodzaj, char stan){
	++liczba_budynkow;
	if(ostatni == NULL){
		ostatni = new Budynek();
		pierwszy = ostatni;
		ostatni->rodzaj=rodzaj;
		ostatni->stan_budynku=stan;
		ostatni->sasiad=NULL;
	}
	else{
		Budynek *nowy;
		nowy = new Budynek();
		ostatni->sasiad=nowy;
		ostatni=nowy;

		ostatni->rodzaj=rodzaj;
		ostatni->stan_budynku=stan;
		ostatni->sasiad=NULL;
	}
}

bool Lista_budynkow::usun(int numer_budynku){
	Budynek *pomoc;
	Budynek *pomoc_do;
	bool wartownik = 0;
	pomoc = pierwszy;

	for(int i = 1; i<=numer_budynku-2; ++i){
		pomoc=pomoc->sasiad;
		if(pomoc == NULL){wartownik = 1; break;}
	}

	if(wartownik)return 0;
    --liczba_budynkow;
	if(numer_budynku == 1){
		pomoc=pierwszy->sasiad;
		delete pierwszy;
		pierwszy = pomoc;
	}
	else{
		pomoc_do=pomoc->sasiad;
		pomoc->sasiad=pomoc->sasiad->sasiad;
		delete pomoc_do;
	}

	return 1;
}

int Lista_budynkow::zwroc_liczbe_budynkow(){
	return liczba_budynkow;
}
