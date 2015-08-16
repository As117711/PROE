#include "../include/Remiza.h"
#include<fstream>
#include<string>

Remiza::Remiza(){
    liczba_krzesel=0;
    liczba_stolikow=0;
    stol_bilardowy=0;
    stol_pingpongowy=0;
}
void Remiza::info_remiza(){
    cout << "Informacje o Remizie. (0 - nie posiada, 1 posiada , >1 liczba elementow)" << endl;
    cout << "Stol Bilardowy: " << stol_bilardowy << endl;
    cout << "Stol do Ping-Ponga: " << stol_pingpongowy << endl;
    cout << "Liczba Krzesel: " << liczba_krzesel << endl;
    cout << "Liczba Stolikow: " << liczba_stolikow << endl;
}

void Remiza::zwieksz_liczbe_stolikow(int ile){
    liczba_stolikow += ile;
}

void Remiza::zwieksz_liczbe_krzesel(int ile){
    liczba_krzesel += ile;
}
void Remiza::kup_stol_bilardowy(){
    stol_bilardowy = true;
}

void Remiza::kup_stol_pingpongowy(){
    stol_pingpongowy = true;
}

int Remiza::ile_krzesel(){
    return liczba_krzesel;
}
int Remiza::ile_stolikow(){
    return liczba_stolikow;
}
bool Remiza::czy_jest_bilard(){
    return stol_bilardowy;
}
bool Remiza::czy_jest_pingpong(){
    return stol_pingpongowy;
}

ostream& operator<<(ostream& s, Remiza &O){
    s << O.liczba_krzesel << endl << O.liczba_stolikow << endl;
    s << O.stol_bilardowy << endl << O.stol_pingpongowy << endl;
    return s;
}

istream& operator>>(istream& s, Remiza &O){
    s >> O.liczba_krzesel >> O.liczba_stolikow;
    s >> O.stol_bilardowy >> O.stol_pingpongowy;
    return s;
}

void Remiza::zapisz_doPliku(string n_plik){
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
void Remiza::wczytaj_zPliku(istream &plik){
    plik >> *(this);
}
