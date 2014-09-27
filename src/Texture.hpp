#ifndef TEXTURE_H_DEFINED
#define TEXTURE_H_DEFINED

#include <SDL2/SDL.h>            // SDL2
#include <SDL2/SDL_video.h>      // SDL2
#include <SDL2/SDL_image.h>      // SDL2_Image
#include <SDL2/SDL_ttf.h>        // SDL2_TTF
#include <SDL2/SDL_mixer.h>      // SDL2_Mixer
#include <SDL2/SDL2_rotozoom.h>      // SDL2_GFX
#include <SDL2/SDL2_gfxPrimitives.h> // SDL2_GFX

#include <iostream>
#include <string>
#include "Application.hpp"


// Shuts up the compiler about unused parameters.
#define UNUSED(x) ((void)(x))

class Texture{
public:
	Texture(void);
	void render(void);
	void load(std::string id, std::string file);
	int get_width(void) { return texture_box.w; }
	int get_heigth(void) { return texture_box.h; }
	std::string get_id(void) { return id; }
private:
	SDL_Texture* texture;
	SDL_Rect texture_box;
	std::string file;
	std::string id;
};

#endif /* TEXTURE_H_DEFINED */
