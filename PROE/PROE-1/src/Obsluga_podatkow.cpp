#include "../include/Obsluga_podatkow.h"
#include<iostream>
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

Obsluga_podatkow::Obsluga_podatkow(const Obsluga_podatkow &kopia){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora kopiujacego klasy Obsluga_podatkow" << endl << endl;
	#endif
	for(int i = 0; i<4;++i){
		cena_prad[i]=kopia.cena_prad[i];
		cena_woda[i]=kopia.cena_woda[i];
		cena_gaz[i]=kopia.cena_gaz[i];
		cena_czynsz[i]=kopia.cena_czynsz[i];
	}
}

Obsluga_podatkow::~Obsluga_podatkow(){
	#ifdef _DEBUG
		cout << "Wywolanie destruktora klasy Obsluga_podatkow" << endl << endl;
	#endif
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
