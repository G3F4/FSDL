#ifndef TEXTOBJECT_HPP_DEFINE
#define TEXTOBJECT_HPP_DEFINE

#include <algorithm>
#include <SDL2/SDL_ttf.h>
#include "Texture.hpp"
#include "abstract/BaseObject.hpp"


class TextObject: public BaseObject {
public:
    TextObject(void);
    TextObject(std::string text);
    TextObject(std::string text, int x, int y);
    TextObject(std::string text, int x)
    void set_text(std::string text) { m_text = text; };
    std::string get_text(void) { return m_text; };
    int length(void) { return (int) m_text.length(); } // casting to int because .length() is returning unsigned long
    void empty(void) { m_text = ""; }
    void capitalize(void) { std::transform(m_text.begin(), m_text.end(),m_text.begin(), ::toupper); }
    void decapitalize(void) { std::transform(m_text.begin(), m_text.end(),m_text.begin(), ::tolower); }
    void render(void);
    void create(void);

protected:
    ~TextObject() {};

private:
    std::string m_text;
};

#endif /* TEXTOBJECT_HPP_DEFINE */