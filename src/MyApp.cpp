#include "MyApp.hpp"
#include "Application.hpp"
#include "TextureStash.hpp"
#include <iostream>

void MyApp::start()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	std::cout << "SDL was initialized" << std::endl;
	TextureStash::Instance()->add("ele", "ele.png");
	TextureStash::Instance()->add("no-img", "no-img.png");
	TextureStash::Instance()->render_all();
	Application::Instance()->refresh();
	Application::Instance()->pause(2000);
}
void MyApp::exit()
{
	SDL_Quit();
}

