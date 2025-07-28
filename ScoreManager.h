#pragma once
class ScoreManager
{
public:
	int PlayerScore ;
	int AIScore ;

	static ScoreManager& Get();

	void Initialize();

private:
	ScoreManager() = default;
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
};

