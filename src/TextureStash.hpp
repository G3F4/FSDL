#ifndef TEXTURESTASH_H_DEFINED
#define TEXTURESTASH_H_DEFINED

#include "Texture.hpp"
#include <string>
#include <iostream>
#include <map>

class TextureStash {
public:
	static TextureStash* Instance(void);
	bool add(std::string id, std::string file_path);
	std::string get_folder(void) { return folder; }
	void set_folder(std::string new_folder) { folder = new_folder; }
	void render_all(void);
private:
	TextureStash(void);
	~TextureStash(void);
	std::string folder;
	static TextureStash* instance;
	static bool instance_flag;
	std::map<std::string, Texture*> textures_set;
};

#endif /* TEXTURESTASH_H_DEFINED */