#include "TextStash.hpp"

std::unique_ptr<TextStash> TextStash::m_instance;
std::once_flag TextStash::m_once_flag;

TextStash& TextStash::Instance() {
    std::call_once(m_once_flag, [] {
        m_instance.reset(new TextStash);
    });
    return *m_instance.get();
}

TextStash::TextStash(void) {
    std::cout << "TextStash singelton instantiated." << std::endl;
    if(TTF_Init() == -1) {
        std::cout << TTF_GetError() << std::endl;
    } else {
        std::cout << "TTF inited." << std::endl;
    }
    m_fonts["default"] = TTF_OpenFont("assets/fonts/test.ttf", 16);
    if (m_fonts["default"] == NULL) {
        std::cout << TTF_GetError() << std::endl;
    } else {
        std::cout << "Default font loaded." <<std::endl;
    }
    m_colors["default"] = {0,0,0};
}

TextStash::~TextStash(void) {
    for (auto font : m_fonts) {
        TTF_CloseFont(m_fonts[font.first]);
        std::cout << font.first << " font closed." <<std::endl;
    }
    TTF_Quit();
    std::cout << "TextStash singleton destroyed." << std::endl;
}

TTF_Font* TextStash::get_font(std::string id) {
    return m_fonts[id];
}

SDL_Color TextStash::get_color(std::string id) {
    return m_colors[id];
}
TextObject* TextStash::get_text(std::string id) {
    return m_texts[id];
}

void TextStash::write(std::string text, int x, int y) {
    std::string hash_id = random_string(8);
    m_texts[hash_id] = new TextObject(text, x, y);
}

void TextStash::render_all(void) {
    for ( auto text : m_texts) {
        m_texts[text.first]->render();
    }
}