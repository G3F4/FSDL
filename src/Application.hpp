#ifndef APPLICATION_H_DEFINED
#define APPLICATION_H_DEFINED

#include <string>
#include "MyApp.hpp"


class Application
{
public:              
    static Application* Instance(void);              // Instance method used to acces the class
                                                // defaults:
	Application(std::string title = "SDL App",       // window title
            Uint32 x_position = 0,              // x position of left upper corner of the window
            Uint32 y_position = 1000,              // y position of left upper corner of the window
            Uint32 width = 640,                 // width of the window
            Uint32 heigth = 480,                // heigth of the window
            Uint32 flags = SDL_WINDOW_SHOWN);   // SDL_ApplicationFlags, default window is simply shown
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
    void destroy(void);                         // destroy SDL_Application and set window pointer to nullptr

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
    void set_title(std::string title);          // set the title of the window
    std::string get_title(void);                // get the title of the window
    void hide(void);                            // hide window
    void show(void);                            // show window
    bool set_brightness(float brightness);      // set the brightness of the window
    float get_brightness(void);                 // get level of the brightness of the window
    ~Application(void);                              // destructor
    SDL_Renderer* get_render(void){ return render;}
    void start(void);
    void pause(Uint32 ms);                      // delay application for given amount of miliseconds
    void refresh(void);
//private:
    void update_window_position(void);          // update position of the window when changed
    void update_window_size(void);              // update size of the window when changed
    void create_render(                         // create a render for this window
        Uint32 flags = SDL_RENDERER_ACCELERATED,
        int index = -1);
    void set_render_color(
        int R = 0,
        int G = 0,
        int B = 0,
        int alpha = 100);
    SDL_Renderer* render;                        // Application Renderer
    SDL_Window* window;                         // SDL_Application pointer to window structure
    std::string title;                          // literal representing window title
    Uint32 x_position;                          // variable to store x position of the window
    Uint32 y_position;                          // variable to store y position of the window
    Uint32 width;                               // variable to store width of the window
    Uint32 heigth;                              // variable to store heigth of the wondow
    Uint32 flags;                               // variable to store SDL_ApplicationFlags
    Uint32 render_flags;                        // variable to store SDL_RendererFlags
    SDL_Rect window_box;                        // SDL_Rect structure holding window dimensions and position
    static Application* instance;                    // pointer to instance, access point
    static bool instance_flag;                  // instance flag
    SDL_RendererInfo* render_info;
};

#endif //APPLICATION_H_DEFINED

