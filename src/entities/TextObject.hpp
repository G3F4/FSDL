#ifndef TEXTOBJECT_HPP_DEFINE
#define TEXTOBJECT_HPP_DEFINE

#include <algorithm>
#include <SDL2/SDL_ttf.h>
#include "Texture.hpp"


class TextObject: public Texture {
public:
    TextObject(std::string text);
    void set_text(std::string text);
    std::string get_text(void);
    int length(void) { return (int) m_text.length(); } // casting to int because .length() is returning unsigned long
    void empty(void) { m_text = ""; }
    void capitalize(void) { std::transform(m_text.begin(), m_text.end(),m_text.begin(), ::toupper); }
    void decapitalize(void) { std::transform(m_text.begin(), m_text.end(),m_text.begin(), ::tolower); }

protected:
    ~TextObject() {};

private:
    std::string m_text;
};

#endif /* TEXTOBJECT_HPP_DEFINE */