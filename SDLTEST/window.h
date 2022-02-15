#pragma once
#ifndef _WINDOW_H
#define _WINDOW_H
#include <SDL.h>
#include <iostream>

class Window
{
	public:
		Window(); // Constructor.
		~Window(); // Destructor.
		void Create(std::string name, int xPos, int yPos, int width, int height, Uint32 flags); // Create the window.
		void Destroy(); // Cleanup.
		inline SDL_Window* GetWindow() { return m_window; }
	private:

		int width; // Height of the window
		int height; // Width of the window.
		SDL_Window* m_window; // Window.
};

#endif // !_WINDOW_H
