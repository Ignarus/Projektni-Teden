#include "SDL.h" 
#include "Koda/SDL_Stuff.h"

int main( int argc, char* args[] ) 
{
	srand(time(NULL));

	//Inicializacija SDL-a 
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//�e bova rabila
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//inicializacija za tekst
			if (TTF_Init() < 0)
			{
				printf("Failed to initialize text!\n");
			}
			else {


				//Main loop flag
				bool quit = false;

				//Event handler
				SDL_Event e;

				//While application is running

				//GameLoop(quit, e);
			}
		}
	}

	//Quit SDL 
	SDL_Quit(); 

	return 0; 
}