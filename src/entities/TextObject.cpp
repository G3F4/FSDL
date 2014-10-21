#include "TextObject.hpp"

TextObject::TextObject(std::string text, int x, int y) : m_text(text) {
    m_font = TextStash::Instance().get_font("default");
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

void TextObject::create() {
    m_font = TTF_OpenFont("assets/fonts/test.ttf", 16);
    m_color = {0,0,0};
    SDL_Surface* surf = TTF_RenderText_Solid(m_font, m_text.c_str(), m_color);
    if (surf == NULL) {
        std::cout << TTF_GetError() << std::endl;
    }
    m_texture = SDL_CreateTextureFromSurface(Application::Instance().get_render(), surf);
    if (m_texture == NULL) {
        std::cout << TTF_GetError() << std::endl;
    }
    SDL_QueryTexture(m_texture, NULL, NULL, &m_box.w, &m_box.h);
}