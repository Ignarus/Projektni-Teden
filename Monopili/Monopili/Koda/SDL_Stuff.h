#ifndef SDL_STUFF_H
#define SDL_STUFF_H


#include <SDL.h>
#include <SDL_image.h> 
#include <SDL_ttf.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>


const int SCREEN_WIDTH = 640 * 2;
const int SCREEN_HEIGHT = 480 * 2;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
__declspec(selectany) SDL_Window* gWindow = NULL;

//The window renderer
__declspec(selectany) SDL_Renderer* gRenderer = NULL;

__declspec(selectany) TTF_Font *gFont = NULL;




#endif