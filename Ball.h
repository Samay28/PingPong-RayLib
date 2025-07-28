#include <iostream>
#pragma once

class Ball
{
public:
	float x, y;
	int speedx, speedy;
	int radius;

	void Draw();
	void Update();
};

