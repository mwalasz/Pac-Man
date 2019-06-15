#pragma once
#include <string>
#include "Results.h"

class Player
{
public:
	Player();
	~Player();

	std::string Get_Name();
	void Set_Name(std::string toSet);

	Results results;

private:
	std::string name;
};

