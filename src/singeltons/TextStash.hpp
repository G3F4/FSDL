#ifndef TEXTSTASH_H_DEFINED
#define TEXTSTASH_H_DEFINED

#include <SDL2/SDL.h>
#include <iostream>
#include <typeinfo>
#include <map>
#include <memory>
#include <mutex>

#include "Application.hpp"
#include "../entities/TextObject.hpp"

class TextStash {
public:
    static TextStash& Instance(void);
    virtual ~TextStash(void);
    void add(std::string text);
    void remove(std::string id);
    void load_font(std::string id, std::string file);
    void remove_font(std::string id);
    void add_color(std::string id, int R, int G, int B);
    void remove_color(std::string id);

private:
    TextStash();
    // TextStash(const TextStash& src) {}; TODO
    // TextStash& operator=(const TextStash& rhs) {}; TODO
    static std::unique_ptr<TextStash> m_instance;
    static std::once_flag m_once_flag;
    std::map<std::string, TTF_Font*>m_fonts;
    std::map<std::string, SDL_Color>m_colors;
    std::map<std::string, TextObject*>m_texts;

};

#endif /* TEXTSTASH_H_DEFINED */