#include "../include/Budynek.h"
#include<fstream>
#include<string>
using namespace std;
Budynek::Budynek(int r, char s){
    rodzaj=r;
    stan=s;
}

char Budynek::zwrocStan(){
    return stan;
}
int Budynek::zwrocRodzaj(){
    return rodzaj;
}
void Budynek::poprawStan(int t){
    rodzaj+=t;
}

ostream& operator<<(ostream& s, Budynek &O){
    s << O.rodzaj << endl << O.stan << endl;
    return s;
}

istream& operator>>(istream& s, Budynek &O){
    s >> O.rodzaj >> O.stan;
    return s;
}

void Budynek::zapisz_doPliku(string n_plik){
    fstream plik;
    plik.exceptions(fstream::failbit | fstream::badbit);
    try{
        plik.open( n_plik.c_str(),std::ios::out | std::ios::app);
    }
    catch(fstream::failure e){
            cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "BLAD!" << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
    }
    plik << *(this);
    plik.close();
}
void Budynek::wczytaj_zPliku(istream &plik){
    plik >> *(this);
}
