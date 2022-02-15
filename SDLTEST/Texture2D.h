#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include "commons.h"

class Texture2D
{
	public:
		Texture2D(SDL_Renderer* renderer);
		~Texture2D();
		bool CreateTextureFromFile(std::string filePath);
		void Free();
		void Render(Vector2D pos, SDL_RendererFlip flip, double angle = 0.0);
		inline int GetHeight() { return m_height; }
		inline int GetWidth() { return m_width; }
	private:
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		int m_width;
		int m_height;
};


#endif // !_TEXTURE2D_H
