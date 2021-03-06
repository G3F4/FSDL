#include "Application.hpp"

std::unique_ptr<Application> Application::m_instance;
std::once_flag Application::m_once_flag;

Application& Application::Instance() {
    std::call_once(m_once_flag, [] {
        m_instance.reset(new Application);
    });
    return *m_instance.get();
}

void Application::pause(Uint32 ms) {
    SDL_Delay(ms);
}

void Application::start(void){
    this->Instance();
}

void Application::stop(void) {
    std::cout << "Application stopped." << std::endl;
    m_running = false;
}

Application::~Application(void){
    Application::destroy();
    m_render = 0;
    m_window = 0;
    SDL_Quit();
    std::cout << "TextureStash singleton destroyed." << std::endl;
}

Application::Application(std::string title, int x_position, int y_position, int width, int heigth, Uint32 flags):
        m_window(nullptr),
        m_title(title),
        m_x_position(x_position),
        m_y_position(y_position),
        m_width(width),
        m_heigth(heigth),
        m_flags(flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout << "SDL was initialized" << std::endl;
    m_window_box.x = x_position;
    m_window_box.y = y_position;
    m_window_box.w = width;
    m_window_box.h = heigth;

    m_window = SDL_CreateWindow(m_title.c_str(),
                                m_x_position,
                                m_y_position,
                                m_width,
                                m_heigth,
                                m_flags);
    create_render();
    set_render_color(127,127,127);
    SDL_RenderClear(m_render);
    SDL_RenderPresent(m_render);
    m_running = true;
    std::cout << "Application singleton instantiated." << std::endl;
}


void Application::update_window_size(void){
    SDL_SetWindowSize(m_window, m_width, m_heigth);
}

void Application::set_width(int w){
    m_width = m_window_box.w = w;
    update_window_size();
}

void Application::set_height(int h){
    m_heigth = m_window_box.h = h;
    update_window_size();
}

void Application::set_window_size(int w, int h){
    m_width = m_window_box.w = w;
    m_heigth = m_window_box.h = h;
    update_window_size();
}

int Application::get_width(void){
    return m_width;
}

int Application::get_height(void){
    return m_heigth;
}

void Application::update_window_position(void){
    SDL_SetWindowPosition(m_window, m_x_position, m_y_position);
}

void Application::set_x_position(int x){
    m_x_position = m_window_box.x = x;
    update_window_position();
}

void Application::set_y_position(int y){
    m_y_position = m_window_box.y = y;
    update_window_position();
}

void Application::set_window_position(int x, int y){
    m_x_position = m_window_box.x = x;
    m_y_position = m_window_box.y = y;
    update_window_position();
}

void Application::create_render(Uint32 flags, int index){
    m_render = SDL_CreateRenderer(m_window, index, flags);
    if(m_render == NULL) {
        std::cout << SDL_GetError() << std::endl;
    }
}

void Application::set_render_color(int R, int G, int B, int alpha){
    SDL_SetRenderDrawColor(m_render, (Uint8) R, (Uint8) G, (Uint8) B, (Uint8) alpha);
}

void Application::destroy(void){
    SDL_DestroyRenderer(m_render);
    SDL_DestroyWindow(m_window);
}

void Application::refresh(void) {
    SDL_RenderPresent(m_render);
}

void Application::clear(void) {
    SDL_RenderClear(m_render);
}

void Application::set_title(std::string title) {
    SDL_SetWindowTitle(m_window, title.c_str());
}

std::string Application::get_title() {
    return SDL_GetWindowTitle(m_window);
}