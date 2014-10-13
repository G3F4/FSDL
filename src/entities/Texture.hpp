#ifndef TEXTURE_H_DEFINED
#define TEXTURE_H_DEFINED

#include <SDL2/SDL.h>            // SDL2
#include <SDL2/SDL_video.h>      // SDL2
#include <SDL2/SDL_image.h>      // SDL2_Image

#include <iostream>
#include <string>

#include "abstract/Object.hpp"
#include "../singeltons/Application.hpp"


// Shuts up the compiler about unused parameters.
#define UNUSED(x) ((void)(x))

class Texture: public Object {
public:
	Texture(void);
	void render(void);
	bool load(std::string id, std::string file);
	int get_width(void) { return m_texture_box.w; }
	int get_height(void) { return m_texture_box.h; }
    void set_width(int width) {m_texture_box.w = width;}
    void set_height(int height) {m_texture_box.h = height;}
    int get_x_position(void) { return m_texture_box.x; }
    int get_y_position(void) { return m_texture_box.y; }
    void set_x_position(int x) {m_texture_box.x = x;}
    void set_y_position(int y) {m_texture_box.y = y;}
	std::string get_id(void) { return m_id; }
private:
	SDL_Texture* m_texture;
	SDL_Rect m_texture_box;
	std::string m_file;
	std::string m_id;
};

#endif /* TEXTURE_H_DEFINED */
