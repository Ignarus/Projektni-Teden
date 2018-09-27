#include "Igra.h"

void igra(bool &quit, SDL_Event &e) {

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	Igra Trenutna_igra(4);

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
		Igralec Novi(to_string(i+1),i);
		Igralci.push_back(Novi);
	}
	for (int i = 0; i < 3; i++) {
		Gumb knof(i,"Ukaz "+to_string(i+1));
		Gumbi.push_back(knof);
	}
}

void Igra::NarisiVse() {
	NarisiIgralnoPolje();
	NarisiPortretIgralcev();
	NarisiGumbe();
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
		Igralci[i].narisi();
	}
}

void Igra::NarisiGumbe() {
	for (int i = 0; i < Gumbi.size(); i++) {
		Gumbi[i].narisi();
	}
}

void Igra::UpdateCurzoe(SDL_Event* e) {
	Curzor.handleEvent(e);
}