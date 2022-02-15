#pragma once
#ifndef _COMMONS_H
#define _COMMONS_H

struct Vector2D
{
	float x;
	float y;
	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vector2D(int initX, int initY) : x(initX), y(initY)
	{

	}
};

#endif // !_COMMONS_H
