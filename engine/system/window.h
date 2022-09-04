#pragma once

#include <string>

class Window
{
public:
	static Window* create();

public:
	virtual void setTitle(const std::string& title) = 0;

	virtual void minimise() = 0;
	virtual void maximise() = 0;
	virtual void restore() = 0;

	virtual void pollEvents() = 0;
};