#include "TextObject.hpp"

TextObject::TextObject(std::string text, int x, int y) : m_text(text) {
    m_font = TextStash::Instance().get_font("default");
    m_color = TextStash::Instance().get_color("default");
    if (m_font == nullptr) {
        std::cout << TTF_GetError() << std::endl;
    }
    m_box.x = x;
    m_box.y = y;
    create();
}

void TextObject::set_font(std::string ID) {
    m_font = TextStash::Instance().get_font(ID);
    create();
}

bool TextObject::create() {
    SDL_Surface* surf = TTF_RenderText_Solid(m_font, m_text.c_str(), m_color);
    if (surf == NULL) {
        std::cout << TTF_GetError() << std::endl;
        return false;
    }
    m_texture = SDL_CreateTextureFromSurface(Application::Instance().get_render(), surf);
    if (m_texture == NULL) {
        std::cout << TTF_GetError() << std::endl;
        return false;
    }
    SDL_QueryTexture(m_texture, NULL, NULL, &m_box.w, &m_box.h);
    return true;
}