#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<iostream>
#include"constants.h"
#include "window.h"

Window* g_Window = nullptr;

bool InitialiseSDL(); // Initialise SDL so a window opens.
bool Update();
void CloseSDL();

int main(int argc, char* argv[])
{
	if (InitialiseSDL())
	{
		bool m_bQuit = false;
		while (!m_bQuit)
		{
			m_bQuit = Update();
		}
	}
	CloseSDL();
	return 0;
}

bool InitialiseSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "COULD NOT INITIALISE SDL. ERROR" << std::endl;
		return false;
	}
	else
	{
		g_Window = new Window();
		g_Window->Create("SDL WINDOW", 100, 100, 500, 500, SDL_WINDOW_SHOWN);
	}
}

bool Update()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type)
	{
		case SDL_QUIT:
			return true;
			break;
	}
	return false;
}

void CloseSDL()
{
	g_Window->Destroy();
	g_Window = nullptr;
	delete g_Window;
	SDL_Quit();
}
