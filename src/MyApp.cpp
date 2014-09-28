#include "MyApp.hpp"
#include "API.hpp"

void MyApp::start()
{
	App->start();
	TextureStash->add("ele", "ele.png");
	while(App->is_running()) {
		App->refresh();
		Events->handle();
		if(Events->key_pressed(KEY::LEFT)) {
			std::cout << "left pressed" << std::endl;
		}
		if(Events->key_pressed(KEY::UP)) {
			std::cout << "up pressed" << std::endl;
		}
		if(Events->key_pressed(KEY::DOWN)) {
			std::cout << "down pressed" << std::endl;
		}
		if(Events->key_pressed(KEY::RIGHT)) {
			std::cout << "right pressed" << std::endl;
		}
		App->render();
	}
}
void MyApp::exit()
{
	App->stop();
}

