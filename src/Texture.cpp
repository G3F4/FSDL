#include "Texture.hpp"
#include <iostream>

Texture::Texture(void){
	file = "assets/images/no-img.png";
	id = "no-img";
	load(file,id);
}

void Texture::load(std::string id, std::string file){
	std::string file_path = "assets/images/" + file;
	texture = IMG_LoadTexture(Application::Instance()->get_render(),
		file_path.c_str());
	if(texture == nullptr) {
		std::cout << IMG_GetError() << std::endl;
	} else {
		std::cout << "Texture loaded. Size: " 
		<< get_width() << " x " << get_heigth() 
		<< " | File: " << file_path << std::endl;
	}
	texture_box.x = 0;
	texture_box.y = 0;
	texture_box.w = 0;
	texture_box.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texture_box.w, &texture_box.h);
}

void Texture::render(void) {
	SDL_RenderCopy(Application::Instance()->get_render(), texture, NULL, &texture_box);
}