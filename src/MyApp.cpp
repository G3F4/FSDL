#include "MyApp.hpp"
// Simplify usage of singleton. Moreover ensuring having access to it from the begining.
static Application& App = Application::Instance();
static Events& Events = Events::Instance();


void MyApp::start()
{
	App.start();
	TextureStash::Instance().add("ele", "ele.png");
    TextureStash::Instance().add("no", "no-img.png");
    TextureStash::Instance().add("test", "test.jpg");
	while(App.is_running()) {
		App.refresh();
		Events.handle();
		App.render();
        if(Events.key_pressed("Escape")){
            App.stop();
        }
	}
}
void MyApp::stop()
{
	App.stop();
}

