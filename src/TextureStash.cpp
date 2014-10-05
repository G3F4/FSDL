#include "TextureStash.hpp"

std::unique_ptr<TextureStash> TextureStash::m_instance;
std::once_flag TextureStash::m_once_flag;

TextureStash& TextureStash::Instance(void) {
	std::call_once(m_once_flag, [] {
		m_instance.reset(new TextureStash);
	});
	return *m_instance.get();
}

TextureStash::~TextureStash(void) {
	
}

TextureStash::TextureStash(void) {
	folder = "/assets/images/";
	std::cout << "TextureStash created." << std::endl;
}

bool TextureStash::add(std::string id, std::string file_path) {
	// check if the passed id already in set.
	if (textures_set.count(id) == 1) {
		std::cout << "Cannot create texture. Set contains texture of given id." << std::endl;
		return false;
	} else {
		Texture* tmp = new Texture();
		if ( tmp->load(id, file_path) ) {
			textures_set[id] = tmp;
			return true;
		} else {
			return false;
		}
		
	}
}

void TextureStash::render_all(void) {
	if (textures_set.size() > 0) {
		for (auto texture : textures_set) {
			textures_set[texture.first]->render();
		}
	} else {
		std::cout << "No textures to render!";
	}
}