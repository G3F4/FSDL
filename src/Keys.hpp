#ifndef KEYS_H_DEFINED
#define KEYS_H_DEFINED

#include "SDL2/SDL.h"

// simplify usage of SDL_Scancode
class Keys {
public:
	static const SDL_Scancode left = SDL_SCANCODE_LEFT;
	static const SDL_Scancode LEFT = SDL_SCANCODE_LEFT;
	static const SDL_Scancode up = SDL_SCANCODE_UP;
	static const SDL_Scancode UP = SDL_SCANCODE_UP;
	static const SDL_Scancode right = SDL_SCANCODE_RIGHT;
	static const SDL_Scancode RIGHT = SDL_SCANCODE_RIGHT;
	static const SDL_Scancode down = SDL_SCANCODE_DOWN;
	static const SDL_Scancode DOWN = SDL_SCANCODE_DOWN;
};
typedef Keys keys;
typedef Keys KEYS;
typedef Keys key;
typedef Keys KEY;

class Mouse {
	static const int left = 0;
	static const int LEFT = 0;
	static const int middle = 1;
	static const int MIDDLE = 1;
	static const int right = 2;
	static const int RIGHT = 2;
};
typedef Mouse mouse;
typedef Mouse MOUSE;

#endif /* KEYS_H_DEFINED */