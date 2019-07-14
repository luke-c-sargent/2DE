#include "image_loader.hpp"

//#include <filesystem>
#include <iostream>
#include <vector>

SDL_Surface* ImageLoader::load(const char* image_location) {
	SDL_Surface* image = IMG_Load(image_location);
	if(!image) {
		std::cout << "IMG_Load error:" << IMG_GetError();
		return nullptr;
	}
	return image;
}

/*std::vector<SDL_Surface*> ImageLoader::load_multiple(std::string images_path){
	std::vector<SDL_Surface*> result;
	for (const auto & entry : fs::directory_iterator(path)) {
		result.push_back(ImageLoader::load(entry.path()));
	}
	return result;
}*/