#ifndef API_H_DEFINED
#define API_H_DEFINED

#include <SDL2/SDL.h>            // SDL2
#include <SDL2/SDL_video.h>      // SDL2
#include <SDL2/SDL_image.h>      // SDL2_Image
#include <SDL2/SDL_ttf.h>        // SDL2_TTF
#include <SDL2/SDL_mixer.h>      // SDL2_Mixer
#include <SDL2/SDL2_rotozoom.h>      // SDL2_GFX
#include <SDL2/SDL2_gfxPrimitives.h> // SDL2_GFX

#include "Application.hpp"
#include "Events.hpp"
#include "TextureStash.hpp"

#include <iostream>
#include <string>

static Application* App = Application::Instance();
static Events* Events = Events::Instance();
static TextureStash* TextureStash = TextureStash::Instance();

#endif /* API_H_DEFINDE */