// This it's starting point of framework.
// After including gives access to whole framework.

#ifndef FSDL_H_DEFINED
#define FSDL_H_DEFINED

#include <SDL2/SDL.h>            // SDL2
#include <SDL2/SDL_video.h>      // SDL2
#include <SDL2/SDL_image.h>      // SDL2_Image
#include <SDL2/SDL_ttf.h>        // SDL2_TTF
#include <SDL2/SDL_mixer.h>      // SDL2_Mixer

#include "singeltons/Application.hpp"
#include "singeltons/Events.hpp"
#include "singeltons/TextureStash.hpp"
#include "singeltons/TextStash.hpp"
#include "singeltons/SingletonBase.hpp"

//typedef Singleton<Application> application;
//typedef Singleton<Events> events;
//typedef Singleton<TextureStash> texturestash;
//typedef Singleton<TextStash> textstash;

#include <iostream>
#include <string>

#endif /* FSDL_H_DEFINED */