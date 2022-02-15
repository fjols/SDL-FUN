#include "window.h"

Window::Window()
{
	// Initialising done here.
	width = 0;
	height = 0;
	m_window = nullptr;
	std::cout << "Window constructor ran" << std::endl;
}

Window::~Window()
{
	m_window = nullptr;
	delete m_window;
}

void Window::Create(std::string name, int xPos, int yPos, int width, int height, Uint32 flags)
{
	m_window = SDL_CreateWindow(name.c_str(), xPos, yPos, width, height, flags); // Create a window using parameters passed in.
	if (m_window == nullptr) // Error checking
	{
		std::cout << "Could not create a window. " << SDL_GetError();
	}
}

void Window::Destroy()
{
	SDL_DestroyWindow(m_window); // Destroy the window. Call this when finished using window.
}
