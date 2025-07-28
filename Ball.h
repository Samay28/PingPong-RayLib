#include <iostream>
#include "ScoreManager.h"
#pragma once

class Ball
{
public:
	float x, y;
	int speedx, speedy;
	int radius;


	void Draw();
	void Update();
	void ResetBall();
};

