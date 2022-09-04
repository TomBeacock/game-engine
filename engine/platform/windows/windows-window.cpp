#include "windows-window.h"

Window* Window::create() {
	return new WindowsWindow();
}

WindowsWindow::WindowsWindow()
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Base";

    WNDCLASSW wc = {};

    wc.lpfnWndProc = WindowsWindow::windowProc;
    wc.hInstance = GetModuleHandleW(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClassW(&wc);

    // Create the window.
    windowHandle = CreateWindowExW(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Application",                 // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,                   // Parent window    
        NULL,                   // Menu
        GetModuleHandleW(NULL), // Instance handle
        NULL                    // Additional application data
    );

    SetPropW(windowHandle, L"Window", this);

    ShowWindow(windowHandle, SW_SHOW);
}

void WindowsWindow::setTitle(const std::string& title)
{
    // WARNING ONLY ASCII
    std::wstring temp(title.begin(), title.end());
    SetWindowTextW(windowHandle, temp.c_str());
}

void WindowsWindow::minimise()
{
    ShowWindow(windowHandle, SW_MINIMIZE);
}

void WindowsWindow::maximise()
{
    ShowWindow(windowHandle, SW_MAXIMIZE);
}

void WindowsWindow::restore()
{
    ShowWindow(windowHandle, SW_RESTORE);
}

void WindowsWindow::pollEvents()
{
    // Run the message loop.
    MSG msg = {};
    while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}

LRESULT WindowsWindow::windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    WindowsWindow* window = (WindowsWindow*)GetPropW(hwnd, L"Window");
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}
