#include "Window.hpp"
#include <iostream>

Window::Window(std::string title, Uint32 x_position, Uint32 y_position, Uint32 width, Uint32 heigth, Uint32 flags):
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
                                SDL_WINDOW_SHOWN);
}

void Window::update_window_size(void){
    SDL_SetWindowSize(this->window, this->width, this->heigth);
}

void Window::set_width(int w){
    this->width = this->window_box.w = w;
    this->update_window_size();
}

void Window::set_heigth(int h){
    this->heigth = this->window_box.h = h;
    this->update_window_size();
}

void Window::set_window_size(int w, int h){
    this->width = this->window_box.w = w;
    this->heigth = this->window_box.h = h;
    this->update_window_size();
}

int Window::get_width(void){
    return this->width;
}

int Window::get_heigth(void){
    return this->heigth;
}

void Window::update_window_position(void){
    SDL_SetWindowPosition(this->window, this->x_position, this->y_position);
}

void Window::set_x_position(int x){
    this->x_position = this->window_box.x = x;
    this->update_window_position();
}

void Window::set_y_position(int y){
    this->y_position = this->window_box.y = y;
    this->update_window_position();
}

void Window::set_window_position(int x, int y){
    this->x_position = this->window_box.x = x;
    this->y_position = this->window_box.y = y;
    this->update_window_position();
}



void Window::destroy(void){
    SDL_DestroyWindow(this->window);
    this->window = nullptr;
}
