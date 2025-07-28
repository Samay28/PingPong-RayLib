#include "ScoreManager.h"

ScoreManager& ScoreManager::Get()
{
	
		static ScoreManager instance;
		return instance;
	
}

void ScoreManager::Initialize()
{
	AIScore = 0;
	PlayerScore = 0;
}
