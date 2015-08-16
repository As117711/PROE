#include "../include/Zarzadzanie_wspoldzielnia.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int Zarzadanie_wspoldzielnia::ilosc_wspoldzielni = 0;

int Zarzadanie_wspoldzielnia::zwroc_ilosc_obiektow(){
	return ilosc_wspoldzielni;
}



Zarzadanie_wspoldzielnia::Zarzadanie_wspoldzielnia(){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora klasy Zarzadzania_wspoldzielnia" << endl << endl;
	#endif
	++ilosc_wspoldzielni;
	stan_konta=1000000;
	nazwa_wspoldzielni="domyslna";
}


int Zarzadanie_wspoldzielnia::zwroc_stan_konta(){
	return stan_konta;
}

string Zarzadanie_wspoldzielnia::zwroc_nazwe(){
	return nazwa_wspoldzielni;
}

void Zarzadanie_wspoldzielnia::ustaw_nazwe(string nazwa){
	nazwa_wspoldzielni=nazwa;
}

void Zarzadanie_wspoldzielnia::ustaw_stan_konta(int nowy_stan_konta){
	stan_konta=nowy_stan_konta;
}

void Zarzadanie_wspoldzielnia::info_wspoldzielnia(){
    cout << "Liczba wszystkich wspoldzielni: " << zwroc_ilosc_obiektow() << endl;
    cout << "Nazwa wspoldzielni: " << nazwa_wspoldzielni << endl;
    cout << "Stan konta wspoldzielni: " << stan_konta << endl << endl;

    wyswietl_info_podatki();
    wyswietl_info_remont();
    info_lista_budynkow();
}

void Zarzadanie_wspoldzielnia::wyswietl_info_remont(){
	remont.info_firma();
}

void Zarzadanie_wspoldzielnia::zmien_nazwe_firmy_remontowej(){
	string s;
	cout << "Prosze podac nowa nazwe firmy remontowej." << endl;
	cin >> s;
	remont.zmien_nazwe(s);
	cout << "Operacja zakonczona." << endl;
}

void Zarzadanie_wspoldzielnia::zmien_ceny_firmy_remontowej(){
	int r,p;
	cout << "Prosze podac rodzaj budynku dla ktorego chcesz zmienic cene. (1-dom wolnostojacy; 2-szeregowiec; 3-blok; 4-wiezowiec)" << endl;
	WYJATEK_CIN_INT(r,1,4);
	cout << "Prosze podac nowa cene"<<endl;
	WYJATEK_CIN_INT(p,0,1000000000);
	remont.zmien_cene(p,r);
	cout << "Operacja zakonczona."<<endl;
}

void Zarzadanie_wspoldzielnia::przeprowadz_remont(){
	if(budynki.size() == 0) cout << "W wspoldzielni nie ma zadnych budynkow." << endl << endl;

		for(int i = 0; i<budynki.size();++i){
		    stan_konta-=remont.zwroc_cene(budynki[i].zwrocRodzaj());
		    budynki[i].poprawStan(1);
		    }

	cout << "Remont przeprowadzony, stan konta wynosi: " << stan_konta << endl << endl;

}

void Zarzadanie_wspoldzielnia::zebranie_podatku(){
	if(budynki.size() == 0) cout << "W wspoldzielni nie ma zadnych budynkow." << endl << endl;
		for(int i = 0; i<budynki.size();++i){
			stan_konta+=podatki.zwroc_cene_prad(budynki[i].zwrocRodzaj())+podatki.zwroc_cene_woda(budynki[i].zwrocRodzaj())+podatki.zwroc_cene_gaz(budynki[i].zwrocRodzaj())+podatki.zwroc_cene_czynsz(budynki[i].zwrocRodzaj());
		}
	cout << "Remont przeprowadzony, stan konta wynosi: " << stan_konta << endl << endl;
}

void Zarzadanie_wspoldzielnia::wyswietl_info_podatki(){
    cout << "Lista oplat wspoldzielni: " << endl;
    string napis[4] = {"Dom wolnostojacy: ", "Szeregowiec: ", "Budynek Mieszkalny: ", "Wiezowiec: "};
    for(int i = 0; i<4; ++i){
        cout << napis[i] << endl << "Czynsz: " << podatki.zwroc_cene_czynsz(i) << endl << "Prad: "<< podatki.zwroc_cene_czynsz(i) << endl;
        cout << "Woda: "<< podatki.zwroc_cene_woda(i) << endl << "Gaz: "<< podatki.zwroc_cene_gaz(i) << endl;
    }
}

void Zarzadanie_wspoldzielnia::zmien_cene_podatkow(){
    int rodzaj,rodzaj1,nowa;
    cout << "Prosze podac rodzaj budynku ktoremu chcemy zmienic oplaty.(1.Dom; 2.Szeregowiec; 3.Budynek; 4.Wiezowiec;)" << endl;
    WYJATEK_CIN_INT(rodzaj,1,4);
    cout << "Prosze podac rodzaj oplaty.(1.Prad; 2.Gaz; 3.Woda; 4.Czynsz;)" << endl;
    WYJATEK_CIN_INT(rodzaj1,1,4);
    cout << "Prosze podac cene." << endl;
    WYJATEK_CIN_INT(nowa,0,1000000000);
    if(rodzaj1 == 1)podatki.zmien_cene_prad(rodzaj, nowa);
    else if(rodzaj1 == 2)podatki.zmien_cene_gaz(rodzaj, nowa);
    else if(rodzaj1 == 3)podatki.zmien_cene_woda(rodzaj, nowa);
    else if(rodzaj1 == 4)podatki.zmien_cene_czynsz(rodzaj, nowa);
}



bool Zarzadanie_wspoldzielnia::operator>(Zarzadanie_wspoldzielnia &Obiekt){
	if(stan_konta>Obiekt.zwroc_stan_konta())return 1;
	else return 0;
}

bool Zarzadanie_wspoldzielnia::operator<(Zarzadanie_wspoldzielnia &Obiekt){
	if(stan_konta<Obiekt.zwroc_stan_konta())return 1;
	else return 0;
}

bool Zarzadanie_wspoldzielnia::operator==(Zarzadanie_wspoldzielnia &Obiekt){
	if(stan_konta==Obiekt.zwroc_stan_konta())return 1;
	else return 0;
}

void Zarzadanie_wspoldzielnia::operator!(){
    stan_konta=0;
    nazwa_wspoldzielni = "";
    budynki.resize(0);
        for(int i=0; i<4;++i)remont.zmien_cene(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_czynsz(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_gaz(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_prad(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_woda(i,0);

}

Zarzadanie_wspoldzielnia Zarzadanie_wspoldzielnia::operator+(const Zarzadanie_wspoldzielnia &kopia){
    Zarzadanie_wspoldzielnia k(*this);
    k.stan_konta+=kopia.stan_konta;
    return k;
}



void Zarzadanie_wspoldzielnia::operator[](const char s[]){
    ustaw_nazwe((string)s);
}

void Zarzadanie_wspoldzielnia::operator[](const string& s){
    ustaw_nazwe(s);
}
void Zarzadanie_wspoldzielnia::operator[](const int t){
    ustaw_stan_konta(t);
}

Zarzadanie_wspoldzielnia::operator int() const
{
    return stan_konta;
}

ostream& operator<<(ostream& s,Zarzadanie_wspoldzielnia &O){
    s << O.nazwa_wspoldzielni << endl << O.stan_konta << endl;
    s << O.budynki.size() << endl;
    return s;
}

istream& operator>>(istream& s,Zarzadanie_wspoldzielnia &O){
    getline(s, O.nazwa_wspoldzielni);
    s >> O.stan_konta;
    return s;
}

void Zarzadanie_wspoldzielnia::zapisz_doPliku(){
    string n_plik;
    cout << "Prosze podac nazwe pliku do ktorego chcesz zapisac obiekt." << endl;
    cin >> n_plik;
    fstream plik;
    plik.exceptions(fstream::failbit | fstream::badbit);
    try{
    plik.open( n_plik.c_str(), std::ios::out | ios::trunc);
    }
    catch(fstream::failure e){
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "BLAD!" << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
    }
        plik << (*this);
    plik.close();

    for(int i = 0; i<budynki.size();++i)budynki[i].zapisz_doPliku(n_plik);
    remont.zapisz_doPliku(n_plik);
    podatki.zapisz_doPliku(n_plik);
}

void Zarzadanie_wspoldzielnia::wczytaj_zPliku(){
    string n_plik;
    int t;
    cout << "Prosze podac nazwe pliku z ktorego chcesz wczytac obiekt." << endl;
    cin >> n_plik;
    fstream plik;
    plik.exceptions(ifstream::failbit | ifstream::badbit);
    try{
        plik.open( n_plik.c_str(), std::ios::in);
    }
    catch(fstream::failure e){
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "BLAD!" << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
    }
        plik >> (*this);
    plik >> t;
    budynki.resize(t);
    for(int i = 0; i<t;++i)budynki[i].wczytaj_zPliku(plik);
    remont.wczytaj_zPliku(plik);
    podatki.wczytaj_zPliku(plik);
    plik.close();
}


