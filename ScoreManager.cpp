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

void ScoreManager::UpdateScoreline(const string& Name)
{
	if (Name == "Player")
	{
		PlayerScore++;
	}
	else if (Name == "AI")
	{
		AIScore++;
	}

	if (PlayerScore == 5 || AIScore == 5)
	{
		isGameOver = true;
	}

}
