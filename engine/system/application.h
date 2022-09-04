#pragma once

#define START_APPLICATION(name) int main(int argc, char** argv) { name app; return app.execute(argc, argv); }

class Window;

class Application
{
public:
	Application();

	int execute(int argc, char** argv);

	Window* const getWindow() const { return mainWindow; };

private:
	Window* mainWindow;
};