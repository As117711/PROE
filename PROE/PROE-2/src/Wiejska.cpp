#include "../include/Wiejska.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Wiejska::kup_krzesla(){
    int ile;
    cout << "Ile krzesel dostawic na impreze?" << endl;
        WYJATEK_CIN_INT(ile,0,1000000000);
    remiza.zwieksz_liczbe_krzesel(ile);
}
void Wiejska::kup_stoliki(){
    int ile;
    cout << "Ile stolikow dostawic na impreze?" << endl;
        WYJATEK_CIN_INT(ile,0,1000000000);
    remiza.zwieksz_liczbe_stolikow(ile);
}
void Wiejska::kup_stol_bilardowy(){
    remiza.kup_stol_bilardowy();
}
void Wiejska::kup_stol_pingpongowy(){
    remiza.kup_stol_pingpongowy();
}

void Wiejska::info_remiza(){
    remiza.info_remiza();
}

void Wiejska::info_wspoldzielnia(){
    cout << "Liczba wszystkich wspoldzielni: " << zwroc_ilosc_obiektow() << endl;
    cout << "Nazwa wspoldzielni: " << nazwa_wspoldzielni << endl;
    cout << "Stan konta wspoldzielni: " << stan_konta << endl << endl;

    info_remiza();
    wyswietl_info_podatki();
    wyswietl_info_remont();
    info_lista_budynkow();


}

void Wiejska::zapisz_doPliku(){
    string n_plik;
    cout << "Prosze podac nazwe pliku do ktorego chcesz zapisac obiekt." << endl;
    cin >> n_plik;
    fstream plik;
    plik.exceptions(fstream::failbit | fstream::badbit);
    try{
    plik.open( n_plik.c_str(), std::ios::out);
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
    remiza.zapisz_doPliku(n_plik);
    for(int i = 0; i<budynki.size();++i)budynki[i].zapisz_doPliku(n_plik);
    remont.zapisz_doPliku(n_plik);
    podatki.zapisz_doPliku(n_plik);
}

void Wiejska::wczytaj_zPliku(){
    string n_plik;
    int t;
    cout << "Prosze podac nazwe pliku z ktorego chcesz wczytac obiekt." << endl;
    cin >> n_plik;
    fstream plik;
    plik.exceptions(fstream::failbit | fstream::badbit);
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
    remiza.wczytaj_zPliku(plik);
    for(int i = 0; i<t;++i)budynki[i].wczytaj_zPliku(plik);
    remont.wczytaj_zPliku(plik);
    podatki.wczytaj_zPliku(plik);
    plik.close();
}
