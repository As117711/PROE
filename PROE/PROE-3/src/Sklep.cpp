#include "../include/Sklep.h"
#include<fstream>
Sklep::Sklep(char s, string rs)
{
   rodzaj = 3;  //kazdy
   stan = s;
   rodzaj_sklepu = rs;
}

string Sklep::zwroc_rodzaj_sklepu(){
    return rodzaj_sklepu;
}

void Sklep::zapisz_doPliku(string n_plik){
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
    plik << rodzaj_sklepu;
    plik.close();
}
void Sklep::wczytaj_zPliku(istream &plik){
    plik >> *(this);
    getline(plik, rodzaj_sklepu);  //znowu trik z wczytaniem linii do konca.
    getline(plik, rodzaj_sklepu);
}

