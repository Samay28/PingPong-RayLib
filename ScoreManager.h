#pragma once
#include <iostream>
#include <string>
using namespace std;
class ScoreManager
{
public:
	int PlayerScore ;
	int AIScore ;

	static ScoreManager& Get();
	bool isGameOver;

	void Initialize();
	void UpdateScoreline(const string& Names);

private:
	ScoreManager() = default;
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
};

