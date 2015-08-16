#include "include/Miejska.h"
#include "include/Wiejska.h"
#include<iostream>
#include<fstream>
using namespace std;

Zarzadzanie_budynkami *polimorfizm[3];
int wybor;
int wyborl;

void testowanie_polimorfizmu(){
    cout << "Przedstawienie mozliwosci polimorfizmu (Pokazanie funkcji wirtualnej)." << endl;

    for(int i = 0; i<3; ++i)polimorfizm[i]->info_wspoldzielnia();
}
void menuW(){
    cout << "4. Dodac krzesla" << endl;
    cout << "5. Dodaj stoliki" << endl;
    cout << "6. Dodac stol bilardowy" << endl;
    cout << "7. Dodac stol pingpongowy" << endl;
    WYJATEK_CIN_INT(wyborl,1,7);
        if(wyborl == 4)((Wiejska*)polimorfizm[wybor-1])->kup_krzesla();
        else if(wyborl == 5)((Wiejska*)polimorfizm[wybor-1])->kup_stoliki();
        else if(wyborl == 6)((Wiejska*)polimorfizm[wybor-1])->kup_stol_bilardowy();
        else if(wyborl == 7)((Wiejska*)polimorfizm[wybor-1])->kup_stol_pingpongowy();
}
void menuM(){
    cout << "4. Dodac Sklep" << endl;
    cout << "5. Usun Sklep" << endl;
    WYJATEK_CIN_INT(wyborl,1,5);
        if(wyborl == 4)((Miejska*)polimorfizm[wybor-1])->dodaj_sklep();
        else if(wyborl == 5)((Miejska*)polimorfizm[wybor-1])->usun_sklep();
}

void menuZW(){
    cout << "Co chcesz zmodyfikowac?" << endl;
    cout << "1. Zmien firme remontowa." << endl;
    cout << "2. Zmien podatki." << endl;
    cout << "3. Zmien liste budynkow" << endl;
    if(wybor == 2)menuW();
    else if(wybor == 3)menuM();
    else if(wybor == 1)WYJATEK_CIN_INT(wyborl,1,3);
    if(wyborl == 1){
        cout << endl;

        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Zmien nazwe firmy remontowej" << endl;
        cout << "2. Zmien ceny firmy remontowej" << endl;
        WYJATEK_CIN_INT(wyborl,1,2);
            if(wyborl == 1)((Zarzadanie_wspoldzielnia*)polimorfizm[wybor-1])->zmien_nazwe_firmy_remontowej();
            else if(wyborl == 2)((Zarzadanie_wspoldzielnia*)polimorfizm[wybor-1])->zmien_ceny_firmy_remontowej();
    }

    else if(wyborl == 2){
        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Zbierz podatki" << endl;
        cout << "2. Zmien ceny podatkow" << endl;
        WYJATEK_CIN_INT(wyborl,1,2);
             if(wyborl == 1)((Zarzadanie_wspoldzielnia*)polimorfizm[wybor-1])->zebranie_podatku();
             else if(wyborl == 2)((Zarzadanie_wspoldzielnia*)polimorfizm[wybor-1])->zmien_cene_podatkow();
    }

    else if(wyborl == 3){
        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Dodaj budynek" << endl;
        cout << "2. Usun budynek" << endl;
        cout << "3. Przeprowadz remont" << endl;
            WYJATEK_CIN_INT(wyborl,1,3);
              if(wyborl == 1)polimorfizm[wybor-1]->dodaj_budynek();
              else if(wyborl == 2)polimorfizm[wybor-1]->usun_budynek();
              else if(wyborl == 3)((Zarzadanie_wspoldzielnia*)polimorfizm[wybor-1])->przeprowadz_remont();
    }
}

void mod_ZW(){
    cout << "Modyfikowanie Obiektu" << endl;
        menuZW();
}
void menu(){

    cout << "Testowanie Obiektow Zarzadzania budynkami. Wcisnij: " << endl;
    cout << "1. Modyfikuj Obiekt Zarzadzania wspoldzielnia (bazowa)" << endl;
    cout << "2. Modyfikuj Obiekt Wiejska (bazowa)" << endl;
    cout << "3. Modyfikuj Obiekt Zarzadzania wspoldzielnia (bazowa)" << endl;
    cout << "4. Testowanie Polimorfizmu" << endl;
    cout << "5. Zapis do pliku" << endl;
    cout << "6. Wczytaj z pliku" << endl;
    cout << "7. Wyjdz z programu" << endl;
      WYJATEK_CIN_INT(wybor,1,7);
    if(wybor == 1 || wybor == 2 || wybor == 3) mod_ZW();
    else if(wybor == 4)testowanie_polimorfizmu();
    else if(wybor == 5){
        cout << "Prosze podac rodzaj obiektu (1-bazowy, 2-wiejski, 3-miejski)" << endl;
        WYJATEK_CIN_INT(wyborl,1,3);
        polimorfizm[wyborl-1]->zapisz_doPliku();
    }
    else if(wybor == 6){
        cout << "Prosze podac rodzaj obiektu (1-bazowy, 2-wiejski, 3-miejski)" << endl;
        WYJATEK_CIN_INT(wyborl,1,3);
        polimorfizm[wyborl-1]->wczytaj_zPliku();
    }

}

int main(){

    polimorfizm[0] = new Zarzadanie_wspoldzielnia();
    polimorfizm[1] = new Wiejska();
    polimorfizm[2] = new Miejska();

    cin.exceptions(ifstream::failbit | ifstream::badbit);

    while(wybor != 7)menu();

    return 0;
}









