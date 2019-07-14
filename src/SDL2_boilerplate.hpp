#pragma once
#include <SDL2/SDL.h>

int init_video(void);
SDL_Window* create_window(int, int, int, int);
SDL_Renderer* init_renderer(SDL_Window*);

int init_SDL(void); // we'll use defaults for now