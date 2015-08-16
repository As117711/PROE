#include "../include/Zarzadzanie_wspoldzielnia.h"
#include <iostream>
#include <string>
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
	liczba_budynkow=0;
	budynki=NULL;
}

Zarzadanie_wspoldzielnia::Zarzadanie_wspoldzielnia(const Zarzadanie_wspoldzielnia &kopia){
	#ifdef _DEBUG
		cout << "Wywolanie konstruktora kopiujacego klasy Zarzadzania_wspoldzielnia" << endl << endl;
	#endif
	++ilosc_wspoldzielni;
	if(kopia.budynki != NULL)budynki = new Lista_budynkow(*kopia.budynki);
	else{budynki = 0;}
	podatki=kopia.podatki;
	remont=kopia.remont;
	nazwa_wspoldzielni=kopia.nazwa_wspoldzielni;
	stan_konta=kopia.stan_konta;

}

Zarzadanie_wspoldzielnia::~Zarzadanie_wspoldzielnia(){
	#ifdef _DEBUG
		cout << "Wywolanie destruktora klasy Zarzadzania_wspoldzielnia" << endl << endl;
	#endif
    delete budynki;

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
    if(budynki!=NULL)info_lista_budynkow();
}

void Zarzadanie_wspoldzielnia::info_lista_budynkow(){
    if(budynki!=NULL){
	cout << "W wspoldzielni znajduje sie: " << budynki->zwroc_liczbe_budynkow() <<" Budynkow."<< endl <<endl;
	Budynek *pomoc = budynki->zwroc_pierwszy();
	int licznik = 1;

		while(pomoc!=NULL){
			cout << "Budynek nr. " << licznik << endl;
			cout << "Rodzaj: ";
				if(pomoc->rodzaj == 1)cout << "Dom wolnostojacy" << endl;
				else if(pomoc->rodzaj == 2)cout << "Szeregowiec" << endl;
				else if(pomoc->rodzaj == 3)cout << "Budynek mieszkalny" << endl;
				else cout << "Wiezowiec" << endl;
			if(pomoc!=NULL){
			cout << "Stan budynku " << pomoc->stan_budynku << endl;
			pomoc=pomoc->sasiad;
			cout << endl << endl;
			}
			++licznik;
		}
    }
}

void Zarzadanie_wspoldzielnia::dodaj_budynek(){
	if(budynki == NULL) budynki = new Lista_budynkow;
	int r;
	char c;
	cout << "Prosze podac rodzaj budynku (1-dom wolnostojacy; 2-szeregowiec; 3-blok; 4-wiezowiec)" << endl;
	cin >> r;
	cout << "Prosze podac stan budynku (w skali 1-10)" << endl;
	cin >> c;
		budynki->dodaj(r,c);
}

void Zarzadanie_wspoldzielnia::usun_budynek(){
	int t;
	if(budynki == NULL) cout << "W wspoldzielni nie ma jeszcze zadnych budowli." << endl;
	else{
		cout << "Prosze podac numer bloku przeznaczonego do usuniecia." << endl;
			cin >> t;
		if(budynki->usun(t) == 0) cout << "Podany budynek nie istnieje" << endl;
		else cout << "Operacja udana." << endl << endl;
	}

}


void Zarzadanie_wspoldzielnia::wyswietl_info_remont(){
	remont.info_firma();
}

void Zarzadanie_wspoldzielnia::zmien_nazwe_firmy_remontowej(){
	string s;
	cout << "Prosze podac nowa nazwe firmy remontowej.";
	cin >> s;
	remont.zmien_nazwe(s);
	cout << "Operacja zakonczona.";
}

void Zarzadanie_wspoldzielnia::zmien_ceny_firmy_remontowej(){
	int r,p;
	cout << "Prosze podac rodzaj budynku dla ktorego chcesz zmienic cene. (1-dom wolnostojacy; 2-szeregowiec; 3-blok; 4-wiezowiec)" << endl;
	cin >> r;
	cout << "Prosze podac nowa cene"<<endl;
	cin >> p;
	remont.zmien_cene(p,r);
	cout << "Operacja zakonczona."<<endl;
}

void Zarzadanie_wspoldzielnia::przeprowadz_remont(){
	if(budynki == NULL) cout << "W wspoldzielni nie ma zadnych budynkow." << endl << endl;
	else{
		Budynek *pomoc = budynki->zwroc_pierwszy();
		while(pomoc!=NULL){
			stan_konta-=remont.zwroc_cene(pomoc->rodzaj);
			pomoc=pomoc->sasiad;
		}
	cout << "Remont przeprowadzony, stan konta wynosi: " << stan_konta << endl << endl;
	}
}

void Zarzadanie_wspoldzielnia::zebranie_podatku(){
	if(budynki == NULL) cout << "W wspoldzielni nie ma zadnych budynkow." << endl << endl;
	else{
		Budynek *pomoc = budynki->zwroc_pierwszy();
		while(pomoc!=NULL){
			stan_konta+=podatki.zwroc_cene_prad(pomoc->rodzaj)+podatki.zwroc_cene_woda(pomoc->rodzaj)+podatki.zwroc_cene_gaz(pomoc->rodzaj)+podatki.zwroc_cene_czynsz(pomoc->rodzaj);
			pomoc=pomoc->sasiad;
		}
	cout << "Remont przeprowadzony, stan konta wynosi: " << stan_konta << endl << endl;
	}
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
    cin >> rodzaj;
    cout << "Prosze podac rodzaj oplaty.(1.Prad; 2.Gaz; 3.Woda; 4.Czynsz;)" << endl;
    cin >> rodzaj1;
    cout << "Prosze podac cene." << endl;
    cin >> nowa;
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
    liczba_budynkow=0;
    delete budynki;
    budynki=NULL;
        for(int i=0; i<4;++i)remont.zmien_cene(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_czynsz(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_gaz(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_prad(i,0);
        for(int i=0; i<4;++i)podatki.zmien_cene_woda(i,0);

}

Zarzadanie_wspoldzielnia& Zarzadanie_wspoldzielnia::operator=(const Zarzadanie_wspoldzielnia & kopia){
	if(budynki != NULL){delete budynki;budynki=NULL;}
	if(kopia.budynki != NULL)budynki=new Lista_budynkow(*kopia.budynki);
	podatki=kopia.podatki;
	remont=kopia.remont;
	nazwa_wspoldzielni=kopia.nazwa_wspoldzielni;
	stan_konta=kopia.stan_konta;
}

Zarzadanie_wspoldzielnia Zarzadanie_wspoldzielnia::operator+(const Zarzadanie_wspoldzielnia &kopia){
    Zarzadanie_wspoldzielnia k(*this);
    k.stan_konta+=kopia.stan_konta;
    return k;
}

ostream& operator<<(ostream& s, Zarzadanie_wspoldzielnia &O){
    s << "Nazwa Wspoldzielni to: " << O.nazwa_wspoldzielni << endl << "Stan konta: " << O.stan_konta << endl;
    return s;
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


