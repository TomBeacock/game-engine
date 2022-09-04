#include "application.h"

#include "window.h"

Application::Application()
	: mainWindow(Window::create())
{

}

int Application::execute(int argc, char** argv)
{
	while (true)
	{
		mainWindow->pollEvents();
	}

	return 0;
}
