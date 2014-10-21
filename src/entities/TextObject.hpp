#ifndef TEXTOBJECT_HPP_DEFINE
#define TEXTOBJECT_HPP_DEFINE

#include <algorithm>
#include <SDL2/SDL_ttf.h>
#include "abstract/BaseObject.hpp"
#include "../singeltons/TextStash.hpp"


class TextObject: public BaseObject {
public:
    TextObject(std::string text = "", int x = 0, int y = 0);
    TextObject(std::string text, int x, int y, TTF_Font* font);
    TextObject(std::string text, int x, int y, SDL_Color& color);
    TextObject(std::string text, int x, int y, SDL_Color& color, TTF_Font* font);
    TextObject(std::string text, int x, int y, TTF_Font* font, SDL_Color& color);
    void set_text(std::string text) { m_text = text; };
    std::string get_text(void) { return m_text; };
    void set_font(std::string ID);
    std::string get_font_name(void);
    TTF_Font* get_font(void) { return m_font; }
    SDL_Color& get_color(void) { return m_color; }
    void set_color(std::string ID);
    void set_color(SDL_Color color);
    void set_color(int R, int G, int B);
    int length(void) { return (int) m_text.length(); } // casting to int because .length() is returning unsigned long
    void empty(void) { m_text = ""; }
    void capitalize(void) { std::transform(m_text.begin(), m_text.end(),m_text.begin(), ::toupper); }
    void decapitalize(void) { std::transform(m_text.begin(), m_text.end(),m_text.begin(), ::tolower); }
    void create(void);

protected:
    ~TextObject() {};

private:
    std::string m_text = "";
    TTF_Font* m_font = nullptr;
    SDL_Color m_color = {0,0,0};
};

#endif /* TEXTOBJECT_HPP_DEFINE */