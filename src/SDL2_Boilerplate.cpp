#include "SDL2_boilerplate.hpp"
#include <iostream>

int init_video(void) {
	std::cout << "Initializing video...\n";
	if ( SDL_Init(SDL_INIT_VIDEO ) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
  return 0;
}

SDL_Window* create_window(int y_offset = 100, int x_offset = 100, int y_resolution = 640, int x_resolution = 480) {
	return SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
}

SDL_Renderer* init_renderer(SDL_Window* win) {
	return SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

int init_SDL(){
	if ( init_video() )
		return 1;
	
	SDL_Window *win = create_window();

	if (win == nullptr) {
		std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = init_renderer(win);

	if (ren == nullptr){
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	return 0;
}