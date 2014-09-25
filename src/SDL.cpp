#include "SDL.hpp"
#include "Application.hpp"
#include "Texture.hpp"
#include <iostream>

bool SDL::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	std::cout << "SDL was initialized" << std::endl;
	SDL_RenderClear(Application::Instance()->get_render());
	Texture* tex = new Texture(Application::Instance()->get_render());
	tex->render();
	std::cout << tex->get_width() << " x " << tex->get_heigth() << std::endl;

	SDL_Delay(2000);
	return true;
}
void SDL::exit()
{
	SDL_Quit();
}

