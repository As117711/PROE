#include "../include/Obsluga_podatkow.h"
#include<iostream>
#include<fstream>

using namespace std;
Obsluga_podatkow::Obsluga_podatkow(){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora klasy Obsluga_podatkow" << endl << endl;
	#endif
	for(int i = 0; i<4;++i){
		cena_prad[i]=(i+1)*100;
		cena_woda[i]=(i+1)*100;
		cena_gaz[i]=(i+1)*100;
		cena_czynsz[i]=(i+1)*100;
	}
}

void Obsluga_podatkow::zmien_cene_prad(int rodzaj,int nowa_cena){
	cena_prad[rodzaj]=nowa_cena;
}
void Obsluga_podatkow::zmien_cene_gaz(int rodzaj,int nowa_cena){
	cena_gaz[rodzaj]=nowa_cena;
}
void Obsluga_podatkow::zmien_cene_woda(int rodzaj,int nowa_cena){
	cena_woda[rodzaj]=nowa_cena;
}
void Obsluga_podatkow::zmien_cene_czynsz(int rodzaj,int nowa_cena){
	cena_czynsz[rodzaj]=nowa_cena;
}

int Obsluga_podatkow::zwroc_cene_prad(int rodzaj){
	return cena_prad[rodzaj];
}
int Obsluga_podatkow::zwroc_cene_gaz(int rodzaj){
	return cena_gaz[rodzaj];
}
int Obsluga_podatkow::zwroc_cene_woda(int rodzaj){
	return cena_woda[rodzaj];
}
int Obsluga_podatkow::zwroc_cene_czynsz(int rodzaj){
	return cena_czynsz[rodzaj];
}

ostream& operator<<(ostream& s,Obsluga_podatkow &podatki){
    for(int i = 0; i<4; ++i){
        s << podatki.zwroc_cene_czynsz(i) << endl << podatki.zwroc_cene_prad(i) << endl;
        s << podatki.zwroc_cene_woda(i) << endl << podatki.zwroc_cene_gaz(i) << endl;
    }
    return s;
}

istream& operator>>(istream& s,Obsluga_podatkow &podatki){
    for(int i = 0; i<4; ++i){
        s >> podatki.cena_czynsz[i] >> podatki.cena_prad[i];
        s >> podatki.cena_woda[i] >> podatki.cena_gaz[i];
    }
    return s;
}

void Obsluga_podatkow::zapisz_doPliku(string n_plik){
    fstream plik;
    plik.exceptions(fstream::failbit | fstream::badbit);
        try{
    plik.open( n_plik.c_str(),std::ios::out | std::ios::app);
    }
    catch(fstream::failure e){
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "BLAD!" << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
    }
    plik << *(this);
    plik.close();
}
void Obsluga_podatkow::wczytaj_zPliku(istream& plik){
    plik >> *(this);
}

