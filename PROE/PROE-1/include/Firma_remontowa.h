#ifndef FIRMA_REMONTOWA_H
#define FIRMA_REMONTOWA_H
#include<string>
using namespace std;
class Firma_remontowa{
	private:
		int cena[4];
		string nazwa;
	public:
		Firma_remontowa();
		Firma_remontowa(const Firma_remontowa &);
        ~Firma_remontowa();

		int zwroc_cene(int);
		string zwroc_nazwe();
		void info_firma();
		void zmien_nazwe(string&);
		void zmien_cene(int,int);

};
#endif // FIRMA_REMONTOWA_H
