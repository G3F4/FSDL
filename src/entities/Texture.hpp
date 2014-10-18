#ifndef TEXTURE_H_DEFINED
#define TEXTURE_H_DEFINED

#include <SDL2/SDL.h>            // SDL2
#include <SDL2/SDL_video.h>      // SDL2
#include <SDL2/SDL_image.h>      // SDL2_Image

#include <iostream>
#include <string>

#include "abstract/BaseObject.hpp"
#include "../singeltons/Application.hpp"


class Texture: public BaseObject {
public:
	Texture(void);
    virtual void render(void);
	virtual bool load(std::string id, std::string file);

    virtual std::string get_id(void) { return m_id; }

private:
	SDL_Texture* m_texture;
	SDL_Rect m_texture_box;
	std::string m_file;
	std::string m_id;
};

#endif /* TEXTURE_H_DEFINED */
