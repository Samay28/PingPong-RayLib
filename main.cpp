#include <raylib.h>
#include <iostream>
#include "Ball.h"
using namespace std;

Ball ball;

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

	while (WindowShouldClose()==false)
	{
		BeginDrawing();

		ball.Update();

		ClearBackground(BLACK); //to clear old values of ball and paddle
		
		DrawLine(sw / 2, 0, sw / 2, sh, WHITE);
		ball.Draw();
		DrawRectangle(10, sh / 2 - 60, 25, 120, RED);
		DrawRectangle(sw - 35, sh / 2 - 60, 25, 120, BLUE);  //rectange is drawn from top left corner mind you
		
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}