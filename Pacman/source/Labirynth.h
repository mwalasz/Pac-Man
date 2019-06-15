#pragma once
#include <iostream>
#include <vector>
#include "Wall.h"
#include "Food.h"
#include "Dot.h"
#include "Constants.h"

class Labyrinth
{
public:
	Labyrinth();
	Labyrinth(const Labyrinth& l);
	~Labyrinth();

	std::vector<Wall> Get_Walls();
	std::vector<Dot> Get_Dots();
	std::vector<Dot>& Get_Dots_R();

	void Set_Dots(std::vector<Dot> toSet);

	void CreateAllDots();
	void CreateDotsInColumns();
	void CreateDotsInRows();
	void CreateSuperDots();

	bool CheckIfRowIsBad(int i);

private:
	std::vector<Wall> walls;
	std::vector<Dot> dots; 
	
	std::vector<int> X_VALUES_OF_ROWS{ 4, 7, 19, 22, 25 }; //VECTOR WITH X VALUES OF ROWS
};