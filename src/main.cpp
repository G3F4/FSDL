#include "SDL.hpp"
//#include "Application.hpp"

#include <exception>

int main()
{
	try
	{
        SDL::init();
	}
	catch (...)
	{
		return -1;
	}
	SDL::exit();
	return 0;
}

