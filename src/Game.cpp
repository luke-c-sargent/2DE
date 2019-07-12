#include "SDL2_Boilerplate.h"
#include "SDL2image_Boilerplate.h"
#include "Game.h"

int Game::init(){
	return init_SDL() + init_SDLimage();
}

int Game::run(){
	return Game::init();
}