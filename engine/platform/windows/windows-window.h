#pragma once

#include "system/window.h"
#include <windows.h>

class WindowsWindow : public Window
{
public:
	WindowsWindow();

	virtual void setTitle(const std::string& title) override;

	virtual void minimise() override;
	virtual void maximise() override;
	virtual void restore() override;

	virtual void pollEvents() override;

private:
	static LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	HWND windowHandle;
};