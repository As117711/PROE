#include "../include/Firma_remontowa.h"
#include <iostream>
using namespace std;
Firma_remontowa::Firma_remontowa(){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora klasy Firma_remontowa" << endl << endl;
	#endif
	nazwa="Firma remontowa";
	for(int i = 0; i<4;++i)cena[i]=(i+1)*100;
}

Firma_remontowa::Firma_remontowa(const Firma_remontowa &kopia){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora kopiujacego klasy Firma_remontowa" << endl << endl;
	#endif
	nazwa=kopia.nazwa;
	for(int i = 0; i<4;++i)cena[i]=kopia.cena[i];
}

Firma_remontowa::~Firma_remontowa(){
	#ifdef _DEBUG
		cout << "Wywolanie Destruktora klasy Firma_remontowa" << endl << endl;
	#endif
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
