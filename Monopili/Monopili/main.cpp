#include "Koda/SDL_Stuff.h"
#include "Koda/Igra.h"


int main( int argc, char* args[] ) 
{

	SDL_SetMainReady();

	//Inicializacija SDL-a 
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Èe bova rabila
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Inicializacija za tekst
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

				igra(quit, e);

			}
		}
	}

	//zapri SDL 
	SDL_Quit(); 

	return 0; 
}