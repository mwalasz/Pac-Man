#include "Results.h"

Results::Results() : totalScore (0), highestScore (0), passedLevels (1), lifesRemained(NUMBER_OF_LIFES)
{
	ReadFromFile(RESULTS_PATH);
}

Results::~Results()
{
}

#pragma region Setters

void Results::Set_TotalScore(unsigned int toSet)
{
	this->totalScore = toSet;
}

void Results::Set_HighestScore(unsigned int toSet)
{
	this->highestScore = toSet;
}

void Results::Set_PassedLevels(unsigned int toSet)
{
	this->passedLevels = toSet;
}

void Results::Set_LifesRemained(unsigned int toSet)
{
	this->lifesRemained = toSet;
}
#pragma endregion

#pragma region Getters

unsigned int Results::Get_TotalScore()
{
	return this->totalScore;
}

unsigned int Results::Get_HighestScore()
{
	return this->highestScore;
}

unsigned int Results::Get_PassedLevels()
{
	return this->passedLevels;
}

unsigned int Results::Get_LifesRemained()
{
	return this->lifesRemained;
}

#pragma endregion

void Results::AddPointsToTotalScore(Dot dot)
{
	if (dot.isSuperDot)
		this->Set_TotalScore(this->Get_TotalScore() + SUPER_DOT_POINTS);
	else
		this->Set_TotalScore(this->Get_TotalScore() + DOT_POINTS);
}

void Results::AddPointsToTotalScore(int points)
{
	this->Set_TotalScore(this->Get_TotalScore() + points);
}

void Results::ResetAllResultsData()
{
	Set_TotalScore(0);
	Set_PassedLevels(1);
	Set_LifesRemained(NUMBER_OF_LIFES);
}

void Results::ReadFromFile(std::string fileName)
{
	if (!playersResultsFromFile.empty())
		playersResultsFromFile.clear();

	std::ifstream file(fileName);

	std::string name;
	int score = 0;

	if (file)
	{
		while (file >> name >> score)
		{
			auto pair = std::make_pair(name, score);
			playersResultsFromFile.push_back(pair);
		}
		file.close();
	}
	else throw FileOperationException();

	SortVector(playersResultsFromFile);
}

void Results::SaveToFile(std::string fileName, std::string playerName, int totalScore)
{
	std::ofstream file;
	file.open(fileName, std::ios::app);

	if (file)
	{
		file << playerName << " " << totalScore << std::endl;
		file.close();
	}
	else throw FileOperationException();
}

void Results::SortVector(std::vector<std::pair<std::string, int>>& vectorToSort)
{
	std::sort(vectorToSort.begin(), vectorToSort.end(), [](auto & left, auto & right) {
		return left.second > right.second;
		});
}
