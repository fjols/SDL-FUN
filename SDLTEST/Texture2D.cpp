#include "Texture2D.h"

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

Texture2D::~Texture2D()
{
	Free();
	m_renderer = nullptr;
}

bool Texture2D::CreateTextureFromFile(std::string filePath)
{
	Free();
	SDL_Surface* l_surface = IMG_Load(filePath.c_str());
	if (l_surface != nullptr)
	{
		SDL_SetColorKey(l_surface, SDL_TRUE, SDL_MapRGB(l_surface->format, 0, 0xFF, 0xFF));
		m_texture = SDL_CreateTextureFromSurface(m_renderer, l_surface);
		if (m_texture == nullptr)
			std::cout << "m_texture is nullptr. ERROR: " << SDL_GetError();
	}
	else
	{
		m_width = l_surface->w;
		m_height = l_surface->h;
	}
	return m_texture != nullptr;
}

void Texture2D::Free()
{
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_height = 0;
		m_width = 0;
	}
}

void Texture2D::Render(Vector2D pos, SDL_RendererFlip flip, double angle)
{
	SDL_Rect renderLoc = { pos.x, pos.y, m_width, m_height };
	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLoc, 0, nullptr, flip);
}
