#include "SDL_Stuff.h"

void igra(bool &quit, SDL_Event &e) {

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	while (!quit) {
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			SDL_SetRenderDrawColor(gRenderer, 0xCD, 0xE6, 0xD0, 0xFF);
			SDL_RenderClear(gRenderer);

			SDL_SetRenderDrawColor(gRenderer, 0xCD, 0xE6, 0xD0, 0xFF);

			SDL_RenderPresent(gRenderer);
		}
	}
}