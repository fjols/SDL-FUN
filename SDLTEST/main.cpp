#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<iostream>
#include"constants.h"
#include "window.h"
#include "Texture2D.h"

Window* g_Window = nullptr;
Texture2D* g_texture = nullptr;
SDL_Renderer* g_renderer = nullptr;

bool InitialiseSDL(); // Initialise SDL so a window opens.
void Render();
bool Update();
void CloseSDL();

int main(int argc, char* argv[])
{
	if (InitialiseSDL())
	{
		bool m_bQuit = false;
		while (!m_bQuit)
		{
			Render();
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
	g_renderer = SDL_CreateRenderer(g_Window->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
	if (g_renderer != nullptr)
	{
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags))
		{
			std::cout << "SDL_IMAGE COULD NOT BE INITIALISED. ERROR" << IMG_GetError();
			return false;
		}
	}
	else
	{
		std::cout << "RENDERER COULD NOT BE INITIALISED. ERROR" << SDL_GetError();
		return false;
	}

	g_texture = new Texture2D(g_renderer);
	if (!g_texture->CreateTextureFromFile("Images/test.jpg"))
	{
 		std::cout << "TEXTURE COULD NOT BE LOADED" << std::endl;
		return false;
	}
	
}

void Render()
{
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0x0  F, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);
	g_texture->Render(Vector2D(), SDL_FLIP_NONE);
	SDL_RenderPresent(g_renderer);
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
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;
	delete g_texture;
	g_texture = nullptr;
	SDL_Quit();
}
