#include "Paddle.h"

void Paddle::Draw()
{
	DrawRectangle(x, y, width, height, color);
}

void Paddle::Update()
{
	if (IsKeyDown(KEY_UP))
	{
		y = y - speed;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		y = y + speed;
	}

	checkBoundary();

}

void Paddle::checkBoundary()
{
	if (y <= 0)
	{
		y = 0;
	}
	if (y + height >= GetScreenHeight())
	{
		y = GetScreenHeight() - height;
	}

}
