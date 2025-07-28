#pragma once
#include <iostream>
#include <raylib.h>

class Paddle
{
public:
	float x, y;
	float height, width;
	int speed;
	Color color;

	void Draw();
	void Update();

	void checkBoundary();
};

