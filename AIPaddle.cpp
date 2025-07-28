#include "AIPaddle.h"
#include <raylib.h>


void AIPaddle::Update(int bally)
{
	if (y + height / 2 > bally)
	{
		y = y - speed;
	}
	if (y + height / 2 <= bally)
	{
		y = y + speed;
	}

	checkBoundary();
}
