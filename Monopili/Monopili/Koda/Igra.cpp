#include "Igra.h"

void igra(bool &quit, SDL_Event &e) {

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	Igra Trenutna_igra(3);


	while (!quit) {
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			Trenutna_igra.UpdateCurzoe(&e);

		}

		SDL_SetRenderDrawColor(gRenderer, 0x55, 0x55, 0x55, 0xFF);
		SDL_RenderClear(gRenderer);

		Trenutna_igra.NarisiVse();

		SDL_RenderPresent(gRenderer);
	}
}

Igra::Igra(int stIgralcev) {
	Igralno_polje.x = SCREEN_WIDTH / 16 * 4.5;
	Igralno_polje.y = SCREEN_HEIGHT / 9 * 0.25;
	Igralno_polje.w = SCREEN_WIDTH / 16 * 7;
	Igralno_polje.h = SCREEN_HEIGHT / 9 * 7;
	for (int i = 0; i < stIgralcev; i++) {
		Igralec Novi("Igralec "+to_string(i+1),i);
		Igralci.push_back(Novi);
	}
	for (int i = 0; i < 3; i++) {
		Gumb knof(i,"Ukaz "+to_string(i+1));
		Gumbi.push_back(knof);
	}
	for (int i = 0; i < 40; i++) {
		switch (i)
		{
		case 0:
		case 2:
		case 4:
		case 7:
		case 10:
		case 17:
		case 20:
		case 22:
		case 30:
		case 33:
		case 36:
		case 38:
			Polja.push_back(new PoljeZAkcijo(i, *this));
			break;
		case 5:
		case 12:
		case 15:
		case 25:
		case 28:
		case 35:
			Polja.push_back(new PosebnoPolje(i, *this));
			break;
		default:
			Polja.push_back(new GradbenoPolje(i, *this));
			break;
		}
	}
}

/*Igra::~Igra() {
	for (int i = 0; i < Polja.size(); i++)
	{
		delete (Polja[i]);
	}
	Polja.clear();
}*/

void Igra::NarisiVse() {
	NarisiIgralnoPolje();
	NarisiPortretIgralcev();
	NarisiGumbe();
	NarisiVsaPolja();
	NarisiFigure();
}

void Igra::NarisiVsaPolja() {
	for (int i = 0; i < 40; i++)
	{
		Polja[i]->narisi();
	}
}

void Igra::NarisiIgralnoPolje() {
	SDL_SetRenderDrawColor(gRenderer, 0xCD, 0xE6, 0xD0, 0xFF);
	SDL_RenderFillRect(gRenderer, &Igralno_polje);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(gRenderer, &Igralno_polje);
}

SDL_Rect Igra::GetIgralnoPolje() {
	return Igralno_polje;
}

void Igra::NarisiPortretIgralcev() {
	for (int i = 0; i < Igralci.size(); i++) {
		Igralci[i].narisi(igralec==i);
	}
}

void Igra::NarisiGumbe() {
	for (int i = 0; i < Gumbi.size(); i++) {
		Gumbi[i].narisi();
	}
}


void Igra::NarisiFigure() {
	for (int i = 0; i < Igralci.size(); i++) {
		Igralci[i].narisiFiguro(Polja[Igralci[i].getLokacijo()]->getKvadrat());
	}
}

void Igra::UpdateCurzoe(SDL_Event* e) {
	Curzor.handleEvent(e);
	if (Curzor.getZadnjaAkcija() == LeviGumbGor) {
		SDL_Point Klik = Curzor.getPozicija();
		if (Klik.x < SCREEN_WIDTH / 16 * 4.5 || Klik.x > SCREEN_WIDTH / 16 * 11.5) {//prever èe je igralec kliknil na podatke od igralca
			for (int i = 0; i < Igralci.size(); i++) {
				SDL_Rect Portret = Igralci[i].getKvadrat();
				if (Portret.x < Klik.x && Klik.x < Portret.x + Portret.w && Portret.y < Klik.y && Klik.y < Portret.y + Portret.h) {
					printf("\n klik: %s \n", Igralci[i].getName());
				}
			}
		}
		else if (Klik.y > SCREEN_HEIGHT / 9 + 7.25) { // preveri èe je igralec kliknil na gumb za ukaz
			for (int i = 0; i < Gumbi.size(); i++) {
				SDL_Rect Kvadrat = Gumbi[i].getKvadrat();
				if (Kvadrat.x < Klik.x && Klik.x < Kvadrat.x + Kvadrat.w && Kvadrat.y < Klik.y && Klik.y < Kvadrat.y + Kvadrat.h) {
					printf("\n klik: %s \n", Gumbi[i].getUkaz());
					if (Gumbi[i].getUkaz() == "Ukaz 1") {
						int ena, dva;
						ena = (rand() % 6 + 1);
						dva = (rand() % 6 + 1);
						Igralci[igralec].premikIgralca( ena + dva );
						printf("ena: %i dva: %i, lokacija %i \n", ena, dva, Igralci[igralec].getLokacijo());
						NaslednijIgralec();
					}

				}
			}
		}
	}
}


void Igra::NaslednijIgralec() {
	igralec++;
	if (igralec >= Igralci.size()) {
		igralec = 0;
	}
}