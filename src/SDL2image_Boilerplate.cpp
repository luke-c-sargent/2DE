#include <iostream>

#include <SDL2/SDL_image.h>

#include "SDL2image_Boilerplate.h"

int init_SDLimage() {
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=IMG_Init(flags);
	if ((initted&flags) != flags) {
		std::cout << "IMG_Init: Failed to init required jpg and png support!\n" << std::endl;
		std::cout << "IMG_Init: " << IMG_GetError() << std::endl;
		return 1;
	}
	return 0;
}