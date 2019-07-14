#pragma once

#include <SDL2/SDL_image.h>

#include <vector>

class ImageLoader {
	static SDL_Surface* load(const char*);
	//static std::vector<SDL_Surface*> load_multiple(std::string);
};