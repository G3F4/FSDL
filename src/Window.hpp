#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <string>
#include "SDL.hpp"

const int h = 400;
const int w = 400;

class Window
{
public:                                         // defaults:
	Window(std::string title = "SDL App",       // window title
            Uint32 x_position = 0,              // x position of left upper corner of the window
            Uint32 y_position = 0,              // y position of left upper corner of the window
            Uint32 width = 640,                 // width of the window
            Uint32 heigth = 480,                // heigth of the window
            Uint32 flags = SDL_WINDOW_SHOWN);   // SDL_WindowFlags, default window is simply shown
                                                // some others options: ( can be or'ed with || )
                                                // SDL_WINDOW_FULLSCREEN - full screen window
                                                // SDL_WINDOW_FULLSCREEN_DESKTOP - fullscreen window at the current desktop resolution
                                                // SDL_WINDOW_HIDDEN - window is not visible
                                                // SDL_BORDERLESS - no window decoration
                                                // SDL_RESIZABLE - window can be resized
                                                // SDL_WINDOW_MINIMIZED - window is minimized
                                                // SDL_WINDOW_MAXIMIZED - window is maximized
                                                // SDL_WINDOW_INPUT_GRABBED - window has grabbed input foucs
                                                // SDL_WINDOW_INPUT_FOCUS - window has input focus
                                                // SDL_WINDOW_MOUSE_FOCUS - window has mouse focus
    void destroy(void);                         // destroy SDL_Window and set window pointer to nullptr

    void set_width(int w);                      // set width of the window
    void set_heigth(int h);                     // set heigth of the window
    void set_window_size(int w, int h);         // set window size
    int get_width(void);                        // get width of the window
    int get_heigth(void);                       // get heigth of the window

    void set_x_position(int x);                 // set x position of the window
    void set_y_position(int y);                 // set y position of the window
    void set_window_position(int x, int y);     // set window position
    int get_x_position(void);                   // get window x position
    int get_y_position(void);                   // get window y position
    SDL_Rect window_box;

private:
    void update_window_position(void);          // update position of the window when changed
    void update_window_size(void);              // update size of the window when changed

    SDL_Window* window;                         // SDL_Window pointer to window structure
    std::string title;                          // literal representing window title
    Uint32 x_position;                          // variable to store x position of the window
    Uint32 y_position;                          // variable to store y position of the window
    Uint32 width;                               // variable to store width of the window
    Uint32 heigth;                              // variable to store heigth of the wondow
    Uint32 flags;                               // variable to store SDL_WindowFlags

//    SDL_Rect window_box;                        // SDL_Rect structure holding window dimensions and position
};

#endif //WINDOW_H_DEFINED

