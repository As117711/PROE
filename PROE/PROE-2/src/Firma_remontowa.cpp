#include "../include/Firma_remontowa.h"
#include <iostream>
#include <fstream>
using namespace std;
Firma_remontowa::Firma_remontowa(){

	nazwa="Firma remontowa";
	for(int i = 0; i<4;++i)cena[i]=(i+1)*100;
}

int Firma_remontowa::zwroc_cene(int rodzaj){
	return cena[rodzaj];
}

string Firma_remontowa::zwroc_nazwe(){
	return nazwa;
}

void Firma_remontowa::info_firma(){
	cout << "Nazwa firmy wspoldzielni: " << nazwa << endl;
	cout << "Cena za remont Domku rodzinnego: " << cena[0] <<"zl" << endl;
	cout << "Cena za remont Szeregowca: " << cena[1] << "zl" << endl;
	cout << "Cena za remont Budynku: " << cena[2] << "zl" << endl;
	cout << "Cena za remont Wiezowca: " << cena[3] << "zl" << endl;
}

void Firma_remontowa::zmien_nazwe(string &nowa_nazwa){
	nazwa = nowa_nazwa;
}

void Firma_remontowa::zmien_cene(int rodzaj, int nowa_cena){
	cena[rodzaj]=nowa_cena;
}

ostream& operator<<(ostream& s,Firma_remontowa &O){
 	s << O.nazwa << endl;
	for(int i = 0; i<4; ++i)s<<O.cena[i]<<endl;
	return s;
}

istream& operator>>(istream& s,Firma_remontowa &O){
 	getline(s, O.nazwa); //przejscie do nastepnej linii, marny trik pewnie da sie lepiej no ale coz.... dziala to dziala :)
 	getline(s, O.nazwa);
	for(int i = 0; i<4; ++i)s>>O.cena[i];
	return s;
}

void Firma_remontowa::zapisz_doPliku(string n_plik){
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
}
void Firma_remontowa::wczytaj_zPliku(istream& plik){
    plik >> *(this);
}

