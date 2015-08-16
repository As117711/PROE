#include "include/Zarzadzanie_wspoldzielnia.h"
#include<iostream>
#include<cstdio>
using namespace std;
void Testuj_dynamicznie(Zarzadanie_wspoldzielnia *spoldzielnia){
    if(spoldzielnia == NULL)spoldzielnia = new Zarzadanie_wspoldzielnia;
    Zarzadanie_wspoldzielnia obiekt_poczatkowy(*spoldzielnia);
    spoldzielnia->ustaw_nazwe("Spoldzielnia dynamiczna");
    spoldzielnia->ustaw_stan_konta(1000000);

    spoldzielnia->dodaj_budynek();
    spoldzielnia->dodaj_budynek();
    spoldzielnia->dodaj_budynek();

    spoldzielnia->info_wspoldzielnia();

    spoldzielnia->usun_budynek();

    spoldzielnia->info_lista_budynkow();

    spoldzielnia->zmien_cene_podatkow();

    spoldzielnia->wyswietl_info_podatki();

    spoldzielnia->zmien_ceny_firmy_remontowej();
    spoldzielnia->zmien_ceny_firmy_remontowej();

    spoldzielnia->wyswietl_info_remont();

    spoldzielnia->zebranie_podatku();
    spoldzielnia->przeprowadz_remont();

    spoldzielnia->info_wspoldzielnia();
    cout << "Obiekt poczatkawy: " << endl << endl;
    obiekt_poczatkowy.info_wspoldzielnia();

}

void Testuj_statycznie(Zarzadanie_wspoldzielnia &spoldzielnia){
    Zarzadanie_wspoldzielnia obiekt_poczatkowy(spoldzielnia);
    spoldzielnia.ustaw_nazwe("Spoldzielnia dynamiczna");
    spoldzielnia.ustaw_stan_konta(1000000);

    spoldzielnia.dodaj_budynek();
    spoldzielnia.dodaj_budynek();
    spoldzielnia.dodaj_budynek();

    spoldzielnia.info_wspoldzielnia();

    spoldzielnia.usun_budynek();

    spoldzielnia.info_lista_budynkow();

    spoldzielnia.zmien_cene_podatkow();

    spoldzielnia.wyswietl_info_podatki();

    spoldzielnia.zmien_ceny_firmy_remontowej();
    spoldzielnia.zmien_ceny_firmy_remontowej();

    spoldzielnia.wyswietl_info_remont();

    spoldzielnia.zebranie_podatku();
    spoldzielnia.przeprowadz_remont();

    spoldzielnia.info_wspoldzielnia();
    cout << "Obiekt poczatkawy: " << endl << endl;
    obiekt_poczatkowy.info_wspoldzielnia();

}
void Testuj_operatory(){
    Zarzadanie_wspoldzielnia obiekt1,obiekt2;
    obiekt1.ustaw_nazwe("obiekt1");
    obiekt2.ustaw_nazwe("obiekt2");
    cout << "Dzialanie operatora << polega na wyswietleniu na konsoli informacji o stanie konta i nazwie wspoldzielni." << endl;
    cout << obiekt1 << endl << endl;
    cout << obiekt2 << endl << endl;
    getchar();
    cout << "Dzialanie operatora + polega na zwroceniu obiektu, ktorego konto bedzie suma kont obiektow, natomiast pozostale parametry otrzymuje od obiektu po lewej stronie" << endl;
    getchar();
    Zarzadanie_wspoldzielnia obiekt3(obiekt1+obiekt2);
    cout << obiekt3;
    cout << "Dzialanie operatorw <,>,== polega na porownaniu stanow kont spoldzielni." << endl;
    cout << obiekt1;
    getchar();
    if(obiekt1 == obiekt2)cout << "Obiekt1 i Obiekt 2 posiadaja tyle samo pieniedzy." << endl;
    if(obiekt1 < obiekt3)cout << "Obiekt 1 jest biedniejszy od obiektu 3" << endl;
    if(obiekt3 < obiekt2)cout << "Obiekt 3 jest biedniejszy od obiektu 2" << endl;
    else if(obiekt3 > obiekt2) cout << "cout << Obiekt 3 jest bogatszy od obiektu 2" << endl;
    cout << "Dzialanie operatora ! polega na wyzerowaniu obiektu. Wyzerujmy obiekt 3" << endl;
    getchar();
    !obiekt3;
    obiekt3.info_wspoldzielnia();
    cout << "Dzialanie operatora = zaprezentuje na podstawie obiektu 4, ktory bedzie kopia obiektu 1." << endl;
    cout << "Dodajmy najpierw budynek do obiektu 1" << endl;
        obiekt1.dodaj_budynek();
        Zarzadanie_wspoldzielnia obiekt4;
        obiekt4=obiekt1;
    cout << "Z obiektu 4 usunmy blok, ktory dodalismy w obiekcie 1." << endl;
    obiekt4.usun_budynek();
    obiekt4.info_lista_budynkow();
    obiekt1.info_lista_budynkow();
    cout << "Jezeli nie podallismy zadnej glupiej wartosci to widzimy ze obiekty 1 i 4 nie operuja na tych samych elementach" << endl << endl;
    cout << "Operatory [] maja za zadanie ustawienie nazwy i konta wspoldzelni. Zmienmy nazwe i stan konta obiektu 1 na 'lol' i 100." << endl;
    getchar();
    obiekt1["lol"];
    obiekt1[100];
    cout << obiekt1;
    cout << "operator konwersji na int zwraca stan konta wspoldzelni.";
    getchar();
    cout << (int)obiekt1;




}

int main(){
    int tryb;
    Zarzadanie_wspoldzielnia* obiekt_dynamiczny;
    Zarzadanie_wspoldzielnia obiekt_statyczny;

    cout << "Wybierz tryb testowanie klasy." << endl;
    cout << "1.Testowanie obiekty dynamicznego."<<endl;
    cout << "2.Testowanie obiektu statycznego." <<endl;
    #ifdef TEST
    cout << "3.Testowanie operatorow." << endl;
    #endif
    cin >> tryb;

    if(tryb == 1)Testuj_dynamicznie(obiekt_dynamiczny);
    else if(tryb==2)Testuj_statycznie(obiekt_statyczny);
    #ifdef TEST
    else if(tryb==3)Testuj_operatory();
    #endif
    return 0;
}









/*#include <iostream>
#include <string>
using namespace std;
class MyClass
{
    public:
        void operator[] (const string&);
};

int main()
{
    MyClass obj;
    obj["20"];
}

void MyClass::operator[] (const string& key) { cout << key << endl;}
*/
