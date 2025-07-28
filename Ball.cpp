#include "Ball.h"
#include <raylib.h>

void Ball::Draw()
{
	//draw ball
	DrawCircle(x, y, radius, WHITE);
}

void Ball::Update()
{
	x += speedx;
	y += speedy;
}
