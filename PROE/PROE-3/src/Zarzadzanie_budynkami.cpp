#include "../include/Zarzadzanie_budynkami.h"


void Zarzadzanie_budynkami::info_lista_budynkow(){
	cout << "W wspoldzielni znajduje sie: " << budynki.size() <<" Budynkow."<< endl <<endl;

		for(int i = 0; i<budynki.size(); ++i){
			cout << "Budynek nr. " << i+1 << endl;
			cout << "Rodzaj: ";
				if(budynki[i].zwrocRodzaj() == 1)cout << "Dom wolnostojacy" << endl;
				else if(budynki[i].zwrocRodzaj() == 2)cout << "Szeregowiec" << endl;
				else if(budynki[i].zwrocRodzaj() == 3)cout << "Budynek mieszkalny" << endl;
				else cout << "Wiezowiec" << endl;

			cout << "Stan budynku " << budynki[i].zwrocStan() << endl;
			cout << endl << endl;
		}
}

void Zarzadzanie_budynkami::dodaj_budynek(){
	int r;
	char c;
	cout << "Prosze podac rodzaj budynku (1-dom wolnostojacy; 2-szeregowiec; 3-blok; 4-wiezowiec)" << endl;
	cin >> r;
	cout << "Prosze podac stan budynku (w skali 1-10)" << endl;
	cin >> c;
		budynki.push_back(Budynek(r,c));
}

bool Zarzadzanie_budynkami::usun_budynek(){
	int t;
	if(budynki.size() == 0) cout << "W wspoldzielni nie ma jeszcze zadnych budowli." << endl;
	else{
		cout << "Prosze podac numer bloku przeznaczonego do usuniecia." << endl;
			cin >> t;
		if(t>=budynki.size() || t<0){
		     cout << "Podany budynek nie istnieje" << endl;
		     return 0;
		}
		else{
		    cout << "Operacja udana." << endl << endl;
		    swap(budynki[t-1], budynki[budynki.size()-1]);
		    budynki.pop_back();
		    return 1;
		}
	}

}
