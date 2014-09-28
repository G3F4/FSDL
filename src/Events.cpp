#include "Events.hpp"

Events* Events::instance = 0;
bool Events::instance_flag = false;

Events* Events::Instance(void) {
	if (!instance_flag){
        instance = new Events();
        instance_flag = true;
        return instance;
    }
    else {
        return instance;
    }
}

bool Events::key_pressed(SDL_Scancode key) {
	m_keys_states = SDL_GetKeyboardState(NULL);
	//check if any key has pressed state
	if (m_keys_states != 0) {
		// check if particular key is pressed
		if (m_keys_states[key] == 1) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool Events::click(int button) {
}

void Events::handle(void) {
	while (SDL_PollEvent(&m_event)) {
		switch (m_event.type) {
			case SDL_QUIT:
				Application::Instance()->stop();
				break;
			case SDL_KEYDOWN:
				std::cout << "Key was pressed." << std::endl;
				// Every time key is pressed we update keys states
				m_keys_states = SDL_GetKeyboardState(NULL);
				break;
			case SDL_KEYUP:
				std::cout << "Key was released." << std::endl;
				// Every time key is released we update keys states
				m_keys_states = SDL_GetKeyboardState(NULL);
				break;
			case SDL_MOUSEMOTION:
                std::cout << "Mouse moved." << std::endl;
                break;
            case SDL_MOUSEBUTTONDOWN:
            	std::cout << "Mouse button pressed." << std::endl;

                break;
            case SDL_MOUSEBUTTONUP:
            	std::cout << "Mouse button released." << std::endl;
                break;
			default:
				break;
		}
	}
}