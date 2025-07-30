#include <raylib.h>
#include <iostream>
#include "Paddle.h"
#include "AIPaddle.h"
#include "Ball.h"
#include "ScoreManager.h"
using namespace std;


Ball ball;
Paddle player;
AIPaddle AI;


int main()
{	
	const int sw = 1200;
	const int sh = 800;
	InitWindow(sw, sh, "PingPong");
	SetTargetFPS(60);


	ball.radius = 20;
	ball.x = sw / 2;
	ball.y = sh / 2;
	ball.speedx = 7;
	ball.speedy = 7;


	player.width = 25;
	player.height = 120;
	player.x = sw - 35;
	player.y = sh/2 - player.height / 2;
	player.speed = 6;
	player.color = RED;

	AI.width = 25;
	AI.height = 120;
	AI.x = 10;
	AI.y = sh / 2 - AI.height / 2;
	AI.speed = 6;
	AI.color = BLUE;

	while (WindowShouldClose()==false)
	{
		BeginDrawing();

		ball.Update();
		player.Update();
		AI.Update(ball.y);


		if (CheckCollisionCircleRec(Vector2{ ball.x+ ball.radius,ball.y+ball.radius }, ball.radius, Rectangle{ player.x,player.y,player.width,player.height }))
		{	
			ball.speedx *= -1;
		}
		if (CheckCollisionCircleRec(Vector2{ ball.x + ball.radius,ball.y + ball.radius }, ball.radius, Rectangle{ AI.x,AI.y,AI.width,AI.height }))
		{
			ball.speedx *= -1;
		}

		ClearBackground(BLACK); //to clear old values of ball and paddle
		
		DrawLine(sw / 2, 0, sw / 2, sh, WHITE);
		ball.Draw();
		player.Draw();
		AI.Draw();
		
		DrawText(TextFormat("%i", ScoreManager::Get().AIScore), sw / 4 - 20, 20, 80, BLUE);
		DrawText(TextFormat("%i", ScoreManager::Get().PlayerScore), 3 * sw / 4 - 20, 20, 80, RED);

		if (ScoreManager::Get().isGameOver && GetKeyPressed())
		{
			ScoreManager::Get().restartGame();
		}
			
		EndDrawing();
	}

	CloseWindow();
	return 0;
}