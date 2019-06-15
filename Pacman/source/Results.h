#pragma once
#include <string>
#include <fstream>
#include "Exceptions.h"
#include "Dot.h"

class Results
{
public:
	Results();
	~Results();

	enum PointsForKilledGhost{ONE = 200, TWO = 400, THREE = 800, FOUR = 1600};
	
	/*	Getters	 */
	unsigned int Get_TotalScore();
	unsigned int Get_HighestScore();
	unsigned int Get_PassedLevels();
	unsigned int Get_LifesRemained();

	/*	Setters	 */
	void Set_TotalScore(unsigned int toSet);
	void Set_HighestScore(unsigned int toSet);
	void Set_PassedLevels(unsigned int toSet);
	void Set_LifesRemained(unsigned int toSet);

	/*	Methods	 */
	void AddPointsToTotalScore(Dot dot);
	void AddPointsToTotalScore(int points);
	void ResetAllResultsData();

	void ReadFromFile(std::string fileName);
	void SaveToFile(std::string fileName, std::string playerName, int totalScore);
	void SortVector(std::vector<std::pair<std::string, int>> & vectorToSort);

	std::vector<std::pair<std::string, int>> playersResultsFromFile;

private:
	unsigned int totalScore;
	unsigned int highestScore;
	unsigned int passedLevels;
	unsigned int lifesRemained;
};

