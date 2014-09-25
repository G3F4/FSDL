#include "Application.hpp"
#include <iostream>

Application* Application::instance = 0;
bool Application::instance_flag = false;

Application* Application::Instance(void){
    if (!instance_flag){
        instance = new Application();
        instance_flag = true;
        return instance;
    }
    else {
        return instance;
    }
}

Application::~Application(void){
    render = 0;
    window = 0;
    this->instance_flag = false;
}

Application::Application(std::string title, Uint32 x_position, Uint32 y_position, Uint32 width, Uint32 heigth, Uint32 flags):
        window(nullptr),
        title(title),
        x_position(x_position),
        y_position(y_position),
        width(width),
        heigth(heigth),
        flags(SDL_WINDOW_SHOWN)
{
    this->window_box.x = x_position;
    this->window_box.y = y_position;
    this->window_box.w = width;
    this->window_box.h = heigth;

    window = SDL_CreateWindow(title.c_str(),
                                x_position,
                                y_position,
                                width,
                                heigth,
                                flags);
    create_render();
    this->set_render_color(123,123,123);
    std::cout << "Window was created!" << std::endl;
}

// Application::Application(void):
//     window(0),
//     render(0),
//     x_position(0),
//     y_position(0),
//     width(800),
//     heigth(600),
//     title(""),
//     flags(0),
//     render_flags(0)
// {}

void Application::update_window_size(void){
    SDL_SetWindowSize(this->window, this->width, this->heigth);
}

void Application::set_width(int w){
    this->width = this->window_box.w = w;
    this->update_window_size();
}

void Application::set_heigth(int h){
    this->heigth = this->window_box.h = h;
    this->update_window_size();
}

void Application::set_window_size(int w, int h){
    this->width = this->window_box.w = w;
    this->heigth = this->window_box.h = h;
    this->update_window_size();
}

int Application::get_width(void){
    return this->width;
}

int Application::get_heigth(void){
    return this->heigth;
}

void Application::update_window_position(void){
    SDL_SetWindowPosition(this->window, this->x_position, this->y_position);
}

void Application::set_x_position(int x){
    this->x_position = this->window_box.x = x;
    this->update_window_position();
}

void Application::set_y_position(int y){
    this->y_position = this->window_box.y = y;
    this->update_window_position();
}

void Application::set_window_position(int x, int y){
    this->x_position = this->window_box.x = x;
    this->y_position = this->window_box.y = y;
    this->update_window_position();
}

void Application::create_render(Uint32 flags, int index){
    render = SDL_CreateRenderer(this->window, index, flags);
    if(render == NULL) {
        std::cout << SDL_GetError() << std::endl;
    }
}

void Application::set_render_color(int R, int G, int B, int alpha){
    SDL_SetRenderDrawColor(this->render, R, G, B, alpha);
}

void Application::destroy(void){
    SDL_DestroyWindow(this->window);
    this->window = nullptr;
}
