#include "SDL2_boilerplate.hpp"
#include "SDL2image_boilerplate.hpp"
#include "app.hpp"

int Game::init(){
	return init_SDL() + init_SDLimage();
}

int Game::run(){
	return Game::init();
}