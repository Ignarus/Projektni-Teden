#ifndef POLJE_H
#define POLJE_H

#include "SDL_Stuff.h"
#include "Igralec.h"
#include "Igra.h"

enum Akciija
{
	Zacetek,
	DrzavnaBanka,
	DavekNaDohodek,
	Piloznost,
	Zapor,
	Parking,
	PojdiZapor,
	DavekNaPremozenje
};

enum Posebno
{
	Zahod,
	Elektrika,
	Sever,
	Vzhod,
	Voda,
	Jug
};

class IPolje {
protected:
	int ID;
	SDL_Rect KvadratPolje;//polje mesta
public:
	SDL_Rect getKvadrat();//vrne rect vrednosti
	//virtual void action() = 0;
	virtual void narisi() = 0;
};

/*referenca oz. zaèasno

class IgralnaPovrsina : IPolje {
public:
	IgralnaPovrsina() {
		int w, h;
		ID = 0;
		SDL_GetWindowSize(SDL_Window* ImeNasegaOkna, w, h);//zdi se mi da tko nekako dela e ne pa mal priredim
		KvadratPolje.x = (w / 16) * (9/2);
		KvadratPolje.y = (h / 9);
		KvadratPolje.width = (w / 16) * 7; //razmerna širina igrlane plošèe
		if (((h/9)*5) < KvadratPolje.width)
		{
			KvadratPolje.height = (h / 9) * 5;
			KvadratPolje.width = (w / 16) * 7;
		}
		else
		{
			KvadratPolje.height = KvadratPolje.width;

		}
	}
};

Konec reference*/

class PoljeZAkcijo: IPolje {
private:
	SDL_Texture* Slikca;
	int Vrsta_Akcije;//enum Akcija
public:
	PoljeZAkcijo(int i);//konstruktor
	void narisi();
};

/*dodano
class PoljeKot :PoljeZAkcijo {
	int Koti;//doloèi kateri kot (0=start,1=Zapor,2=Parking,3=Pojdi v Zapor)

};
*/

class ILastniskoPolje: IPolje {
private:
	int cena;
	int IndexIgralec;
public:
	virtual void narisi() = 0;
};

class GradbenoPolje: ILastniskoPolje {
protected:
	//barva
	SDL_Rect KvadratBarva;//Katero barveno skupino spada izrisat
	int cenaHiske;
	int cenaHotela;
	int BarvenoSkupina;
public:
	GradbenoPolje(int i);//konstruktor
	void narisi();
};

class PosebnoPolje: ILastniskoPolje {
private:
	SDL_Texture * Slikca;
	int VrstaPolja;//enum Posebno
public:
	PosebnoPolje(int i);//konstruktor
	void narisi();
};

#endif