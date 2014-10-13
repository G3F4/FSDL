#include "Texture.hpp"

Texture::Texture(void){
	m_texture = nullptr;
	m_file = "assets/images/no-img.png";
	m_id = "no-img";
}

bool Texture::load(std::string id, std::string file){
	m_id = id;
	m_file = file;
	std::string file_path = "assets/images/" + m_file;
	m_texture = IMG_LoadTexture(Application::Instance().get_render(),
		file_path.c_str());
	m_texture_box.x = 0;
	m_texture_box.y = 0;
	m_texture_box.w = 0;
	m_texture_box.y = 0;
	if(m_texture == nullptr) {
		std::cout << "Texture loading error! Error message: " << IMG_GetError() << std::endl;
		return false;
	} else {
		SDL_QueryTexture(m_texture, NULL, NULL, &m_texture_box.w, &m_texture_box.h);
		std::cout << "Texture loaded | "
		<< "Id: " << get_id()
		<< " | Size: " << get_width() << " x " << get_height()
		<< " | File: " << file_path << std::endl;
		return true;
	}
	
}

void Texture::render(void) {
	SDL_RenderCopy(Application::Instance().get_render(), m_texture, NULL, &m_texture_box);
}