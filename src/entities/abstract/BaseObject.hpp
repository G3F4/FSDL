#ifndef BASEOBJECT_H_DEFINED
#define BASEOBJECT_H_DEFINED

#include <SDL2/SDL.h>

#include "../../singeltons/Application.hpp"
#include "Object.hpp"

class BaseObject: public Object {
public:
    virtual int get_width(void) { return m_box.w; }
    virtual int get_height(void) { return m_box.h; }
    virtual void set_width(int width) { m_box.w = width; }
    virtual void set_height(int height) { m_box.h = height; }
    virtual int get_x_position(void) { return m_box.x; }
    virtual int get_y_position(void) { return m_box.y; }
    virtual void set_x_position(int x) { m_box.x = x; }
    virtual void set_y_position(int y) { m_box.y = y; }
    virtual Uint8* get_alpha(void);
    virtual void set_alpha(Uint8 alpha);
    virtual double get_angle(void) { return m_angle; }
    virtual void set_angle(int angle) { m_angle = angle; }
    virtual SDL_Point* get_pivot_point(void) { return m_pivot_point; }
    virtual void set_pivot_point(SDL_Point* pivot_point) { m_pivot_point = pivot_point; }
    virtual void set_pivot_point(int x, int y) { m_pivot_point->x = x; m_pivot_point->y = y; }
    virtual void flip_horizontally(void) { m_flip = SDL_FLIP_HORIZONTAL; }
    virtual void flip_vertically(void) { m_flip = SDL_FLIP_VERTICAL; }
    virtual void render(void);

protected:
    ~BaseObject(void);
    BaseObject(void); // make it protected so only derrived classes could create objects
    SDL_Texture* m_texture;
    SDL_Rect m_box;
    Uint8 m_alpha;
    double m_angle;
    SDL_Point* m_pivot_point;
    SDL_RendererFlip m_flip;
};

#endif /* BASEOBJECT_H_DEFINED */