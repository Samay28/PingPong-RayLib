#include "Ball.h"
#include <iostream>
#include "ScoreManager.h"
#include <raylib.h>

void Ball::Draw()
{
	//draw ball
	DrawCircle(x, y, radius, WHITE);
}

void Ball::Update()
{	
	if (ScoreManager::Get().isGameOver)
		return;

	x += speedx;
	y += speedy;

	if (y + radius >= GetScreenHeight() || y - radius <= 0)
	{
		speedy *= -1;
	}
	if (x + radius >= GetScreenWidth())
	{
		ScoreManager::Get().UpdateScoreline("AI");
		
		ResetBall();
	}
	if (x - radius <= 0)
	{
		ScoreManager::Get().UpdateScoreline("Player");
		ResetBall();
	}

	/*if (ScoreManager::Get().PlayerScore == 5 || ScoreManager::Get().AIScore == 5)
	{
		ScoreManager::Get().isGameOver = true;
	}*/
}

void Ball::ResetBall()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	int speedChoices[2] = { -1,1 };
	speedx *= speedChoices[GetRandomValue(0, 1)];
	speedy*= speedChoices[GetRandomValue(0, 1)];
}
