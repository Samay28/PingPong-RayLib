#include "Ball.h"
#include <iostream>
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

	if (y + radius >= GetScreenHeight() || y - radius <= 0)
	{
		speedy *= -1;
	}
	if (x + radius >= GetScreenWidth())
	{
		ScoreManager::Get().AIScore++;
		
		ResetBall();
	}
	if (x - radius <= 0)
	{
		ScoreManager::Get().PlayerScore++;
		ResetBall();
	}
}

void Ball::ResetBall()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	int speedChoices[2] = { -1,1 };
	speedx *= speedChoices[GetRandomValue(0, 1)];
	speedy*= speedChoices[GetRandomValue(0, 1)];
}
