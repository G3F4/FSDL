#include "Texture.hpp"
#include <iostream>

Texture::Texture(SDL_Renderer* render){
	this->file_path = "assets/images/no-img.png";
	load(this->file_path, render);
}

void Texture::load(std::string file, SDL_Renderer* render){
	texture = IMG_LoadTexture(render,
		file.c_str());
	if(texture == nullptr) {
		std::cout << IMG_GetError() << std::endl;
	}
	else {
		std::cout << "Texture was loaded" << std::endl;
	}
	texture_box.x = texture_box.y = texture_box.w = texture_box.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texture_box.w, &texture_box.h);
}

void Texture::render(void){

	SDL_RenderCopy(Application::Instance()->get_render(), texture, NULL, &texture_box);
	SDL_RenderPresent(Application::Instance()->get_render());
}