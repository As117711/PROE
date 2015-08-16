#include "../include/Miejska.h"
#include <string>
#include <fstream>

void Miejska::dodaj_sklep(){
    string rodzaj_sklepu;
    int stan;
    cout << "Podaj rodzaj sklepu." << endl;
        getline(cin,rodzaj_sklepu); //Znowu nie wczytuje za pierwszym razem.
        getline(cin,rodzaj_sklepu);
    cout << "Podaj stan sklepu. (W skali od 1 - 10)" << endl;
    WYJATEK_CIN_INT(stan,1,10);
    Sklep s = Sklep(stan,rodzaj_sklepu);
    pasaz_handlowy.push_back(s);
}

void Miejska::usun_sklep(){
    int index;
    cout << "Podaj numer sklepu, ktory chcesz usunac sklepu.";
    WYJATEK_CIN_INT(index,1,pasaz_handlowy.size());
    swap(pasaz_handlowy[index-1], pasaz_handlowy[pasaz_handlowy.size()-1]);
    pasaz_handlowy.pop_back();

}

void Miejska::wyswietl_liste_sklepow(){
    for(int i = 0; i<pasaz_handlowy.size();++i){
        cout << "Sklep nr. " << i+1 << "; Sklep: " << pasaz_handlowy[i].zwroc_rodzaj_sklepu();
    }

}

void Miejska::zapisz_doPliku(){
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
        plik << pasaz_handlowy.size();
    plik.close();
    for(int i = 0; i<budynki.size();++i)budynki[i].zapisz_doPliku(n_plik);
    remont.zapisz_doPliku(n_plik);
    podatki.zapisz_doPliku(n_plik);

    for(int i = 0; i<pasaz_handlowy.size(); ++i)pasaz_handlowy[i].zapisz_doPliku(n_plik);
}

void Miejska::wczytaj_zPliku(){
    string n_plik;
    int budyn,skl;
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
    plik >> budyn;
    plik >> skl;
    budynki.resize(budyn);
    for(int i = 0; i<budyn;++i)budynki[i].wczytaj_zPliku(plik);
    remont.wczytaj_zPliku(plik);
    podatki.wczytaj_zPliku(plik);
    for(int i = 0; i<skl;++i)pasaz_handlowy[i].wczytaj_zPliku(plik);
    plik.close();
}









