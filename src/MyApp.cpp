#include "MyApp.hpp"
// Simplify usage of singleton. Moreover ensuring having access to it from the begining.
static Application& App = Application::Instance();
static Events& Events = Events::Instance();
static TextureStash& TexStash = TextureStash::Instance();
//static TextStash& Texts = TextStash::Instance();

void MyApp::start()
{
	App.start();
    TexStash.add("ele", "ele.png");
    TextStash::Instance();
//	TextureStash::Instance().add("ele", "ele.png");
//    TextureStash::Instance().add("no", "no-img.png");
//    TextureStash::Instance().add("test", "test.jpg");
//    if(TTF_Init() == -1) {
//        std::cout << TTF_GetError() << std::endl;
//    } else {
//        std::cout << "TTF inited." << std::endl;
//    }
//    TTF_Font* font;
//    font = TTF_OpenFont("assets/fonts/test.ttf", 16);
//    if (!font) {
//        std::cout << TTF_GetError() << std::endl;
//    } else {
//        std::cout << "font opened." << std::endl;
//    }
//    SDL_Color color = {0,0,0};
//    SDL_Surface* surf = TTF_RenderText_Solid(font, "test", color);
//    if (surf != NULL) {
//        std::cout << "surf with text created successfully." << std::endl;
//    }
//    SDL_Texture* tex = SDL_CreateTextureFromSurface(App.get_render(), surf);
//    if (tex != NULL) {
//        std::cout << "tex with text created successfully." << std::endl;
//    }
//    SDL_Rect rect;
//    rect.x = 0;
//    rect.y = 0;
//    rect.w = 0;
//    rect.h = 0;
//    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);

	while(App.is_running()) {
//		App.refresh();
		Events.handle();
//		App.render();
//        SDL_RenderClear(App.get_render());
//        SDL_RenderCopy(App.get_render(), tex, NULL, &rect);
//        SDL_RenderPresent(App.get_render());
        if(Events.key_pressed("Escape")){
            App.stop();
        }
	}
}
void MyApp::stop()
{
	App.stop();
}

