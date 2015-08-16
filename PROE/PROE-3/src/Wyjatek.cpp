#include "../include/Wyjatek.h"
void WYJATEK_CIN_INT(int &wczytaj, int przedzialL, int przedzialP){
wczytaj = 1000;
    do{
        try{
            cin >> wczytaj;
        }
        catch(fstream::failure){
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "BLAD!" << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if(wczytaj > przedzialP || wczytaj < przedzialL)cout << "Prosze powtorzyc probe. Liczba z poza przedzialu" <<endl;
    }while(wczytaj > przedzialP || wczytaj < przedzialL);
}
