#include "MyApp.hpp"
// Simplify usage of singleton. Moreover ensuring having access to it from the begining.
static Application& App = Application::Instance();
static Events& Events = Events::Instance();

void MyApp::start()
{
	App.start();
	TextureStash::Instance().add("ele", "ele.png");
	while(App.is_running()) {
		App.refresh();
		Events.handle();
		Events.mouse_clicked("left");
		Events.key_pressed("Left");
		Events.key_pressed("w");
		App.render();
	}
}
void MyApp::exit()
{
	App.stop();
}

