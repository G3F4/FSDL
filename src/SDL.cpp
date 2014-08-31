#include "SDL.hpp"
#include "Window.hpp"
#include <iostream>

bool SDL::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	std::cout << "SDL was initialized" << std::endl;
	Window* window = new Window("test window");
	int w = 0;
	int h = 0;
	while(w < 100){
        w++;
        h++;
        window->set_x_position(w);
        window->set_y_position(h);
        SDL_Delay(10);
	}

	return true;
}
void SDL::exit()
{
	SDL_Quit();
}

