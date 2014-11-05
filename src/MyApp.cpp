#include "MyApp.hpp"
#include "entities/TextObject.hpp"

// Simplify usage of singleton. Moreover ensuring having access to it from the begining.
//static Application& App = Application::Instance();

//static Events& Events = Events::Instance();
//static TextureStash& TexStash = TextureStash::Instance();
//static TextStash& Texts = TextStash::Instance();
Application& App = application::Instance();
Events& Events = events::Instance();
TextureStash& TexStash = texturestash::Instance();
TextStash& Texts = textstash::Instance();
void MyApp::start()
{
	App.start();
    TexStash.add("test", "ele.png");
    for (int i = 0; i < 10; i++) {
        Texts.write("asd " + std::to_string(i), 20*i, 20*i);
    }
	while(App.is_running()) {
		App.clear();
        TexStash.render_all();
        Texts.render_all();
		Events.handle();
        if(Events.key_pressed("Escape")){
            App.stop();
        }
        App.refresh();
	}
}
void MyApp::stop()
{
	App.stop();
}

