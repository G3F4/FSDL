#ifndef TEXTURESTASH_H_DEFINED
#define TEXTURESTASH_H_DEFINED

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>

#include "../entities/Texture.hpp"

class Texture;

class TextureStash {
public:
	static TextureStash& Instance(void);
	bool add(std::string id, std::string file_path);
	std::string get_folder(void) { return folder; }
	void set_folder(std::string new_folder) { folder = new_folder; }
	void render_all(void);
	~TextureStash(void);
private:
	static std::unique_ptr<TextureStash> m_instance;
	static std::once_flag m_once_flag;
	TextureStash(void);
	std::string folder;
	std::map<std::string, Texture*> textures_set;
};

#endif /* TEXTURESTASH_H_DEFINED */