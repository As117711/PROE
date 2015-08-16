#ifndef OBSLUGA_PODATKOW_H
#define OBSLUGA_PODATKOW_H
class Obsluga_podatkow{
	private:
		int cena_prad[4];
		int cena_gaz[4];
		int cena_woda[4];
		int cena_czynsz[4];
	public:
		Obsluga_podatkow();
		Obsluga_podatkow(const Obsluga_podatkow &);
		~Obsluga_podatkow();

		void zmien_cene_prad(int,int);
		void zmien_cene_gaz(int,int);
		void zmien_cene_woda(int,int);
		void zmien_cene_czynsz(int,int);

		int zwroc_cene_prad(int);
		int zwroc_cene_gaz(int);
		int zwroc_cene_woda(int);
		int zwroc_cene_czynsz(int);
};
#endif // OBSLUGA_PODATKOW_H
