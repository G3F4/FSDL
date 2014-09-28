#include "TextureStash.hpp"

TextureStash* TextureStash::instance = 0;
bool TextureStash::instance_flag = false;


TextureStash* TextureStash::Instance(void) {
	if (!instance_flag){
        instance = new TextureStash();
        instance_flag = true;
        return instance;
    }
    else {
        return instance;
    }
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