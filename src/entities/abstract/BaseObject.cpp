#include "BaseObject.hpp"

BaseObject::BaseObject() {
    m_box.x = 0;
    m_box.y = 0;
    m_box.w = 0;
    m_box.h = 0;
    m_alpha = 255;
    m_angle = 0.0;
    m_pivot_point = nullptr;
    m_flip = SDL_FLIP_NONE;
    m_texture = nullptr;
}

BaseObject::~BaseObject() {
    m_texture = nullptr;
    m_pivot_point = nullptr;
}

void BaseObject::render(void) {
    if (SDL_RenderCopyEx(
            Application::Instance().get_render(),
            m_texture,
            NULL,
            &m_box,
            m_angle,
            m_pivot_point,
            m_flip) < 0) {
        std::cout << SDL_GetError() << std::endl;
    }
}

void BaseObject::set_alpha(Uint8 alpha) {
    if (SDL_SetTextureAlphaMod(m_texture, alpha) < 0) {
        std::cout << SDL_GetError() << std::endl;
    }
}

Uint8* BaseObject::get_alpha(void) {
    Uint8 *alpha = nullptr;
    if (SDL_GetTextureAlphaMod(m_texture, alpha) < 0) {
        std::cout << SDL_GetError() << std::endl;
    } else {
        return alpha;
    }
    return alpha;

}