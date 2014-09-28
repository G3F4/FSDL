#ifndef EVENTS_H_DEFINED
#define EVENTS_H_DEFINED
#include <SDL2/SDL.h>
#include <iostream>
#include <typeinfo>

#include "Application.hpp"
#include "Keys.hpp"


class Events {
public:
	static Events* Instance(void);
	void handle(void);
	bool key_pressed(SDL_Scancode key);
	bool click(int button);
private:
	SDL_Event m_event;
	static Events* instance;
	static bool instance_flag;
	const Uint8* m_keys_states;
};

#endif /* EVENTS_H_DEFINED */