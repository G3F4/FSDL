#include "BaseObject.hpp"

BaseObject::BaseObject() {
    m_box.x = 0;
    m_box.y = 0;
    m_box.w = 0;
    m_box.h = 0;
    m_alpha = 255;
    m_angle = 0.0;
    m_pivot_point->x = 0;
    m_pivot_point->y = 0;
    m_flip = SDL_FLIP_NONE;
}

void BaseObject::render(void) {
    SDL_RenderCopyEx(
            Application::Instance().get_render(),
            m_texture, NULL, &m_texture_box,
            m_angle,
            m_pivot_point,
            m_flip);
}