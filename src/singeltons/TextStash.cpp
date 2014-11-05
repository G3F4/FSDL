#include "TextStash.hpp"

//std::unique_ptr<TextStash> TextStash::m_instance;
//std::once_flag TextStash::m_once_flag;
//
//TextStash& TextStash::Instance() {
//    std::call_once(m_once_flag, [] {
//        m_instance.reset(new TextStash);
//    });
//    return *m_instance.get();
//}

TextStash::TextStash(void) {
    m_font_folder = "assets/fonts/";
    std::cout << "TextStash singelton instantiated." << std::endl;
    if(TTF_Init() == -1) {
        std::cout << TTF_GetError() << std::endl;
    } else {
        std::cout << "TTF inited." << std::endl;
    }
    std::string font_path = m_font_folder + "default.ttf";
    m_fonts["default"] = TTF_OpenFont(font_path.c_str(), 16);
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

TextObject* TextStash::write(std::string text, int x, int y) {
    std::string hash_id = random_string(8);                     // generate random string id
    while(m_texts.count(hash_id) == 1) {                        // check if it already exists
        hash_id = random_string(8);                             // if so, then generate till it's unique
    }
    m_texts[hash_id] = new TextObject(text, x, y);              // create new annonymous text object
    return m_texts[hash_id];                                    // we need to return created font so we can controll it
                                                                // after creation if we need to. Only when created hook up is possible.
}

void TextStash::render_all(void) {
    for ( auto text : m_texts) {
        m_texts[text.first]->render();
    }
}

void TextStash::add(std::string id, std::string text) {
    if (m_texts.count(id) == 1) {
        std::cout << "TextStash already contains text object with id: " << id << std::endl;
    } else {
        m_texts[id] = new TextObject(text);
    }
}

void TextStash::remove(std::string id) {
    if ( m_texts.count(id) == 1) {
        m_texts.erase(id);
    } else {
        std::cout << "TextStash doesn't contains text object with given id: " << std::endl;
    }
}

void TextStash::add_color(std::string id, Uint8 R, Uint8 G, Uint8 B) {
    SDL_Color l_color = {R, G, B};
    if (m_colors.count(id) == 1) {
        std::cout << "TextStash already contains color with id: " << id << std::endl;
    } else {
        m_colors[id] = l_color;
    }
}

void TextStash::remove_color(std::string id) {
    if ( m_colors.count(id) == 1) {
        m_colors.erase(id);
    } else {
        std::cout << "TextStash doesn't contains color with given id: " << std::endl;
    }
}

void TextStash::add_font(std::string id, std::string file, int size) {
    if ( m_fonts.count(id) == 1) {
        std::cout << "TextStash already contains font with given id: " << id << std::endl;
    } else {
        std::string file_path = m_font_folder + file;
        m_fonts[id] = TTF_OpenFont(file_path.c_str(), size);
    }
}