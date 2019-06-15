#include "Labirynth.h"

Labyrinth::Labyrinth()
{
	//4 MAIN WALLS
	Wall upWall(0, 0, SCREEN_WIDTH, 49);
	Wall downWall(0, SCREEN_HEIGHT - 49, SCREEN_WIDTH, 49);
	Wall leftWall(0, 0, 182, SCREEN_HEIGHT);
	Wall rightWall(SCREEN_WIDTH - 180, 0, 180, SCREEN_HEIGHT);

	walls.push_back(upWall);
	walls.push_back(downWall);
	walls.push_back(leftWall);
	walls.push_back(rightWall);

	//GROUP OF 4 WIDER BLOCKS ON THE TOP
	Wall firstUpperBlock(leftWall.x + leftWall.length + PACMAN_DRAWN_SIZE,
		upWall.height + PACMAN_DRAWN_SIZE,
		LENGTH_UPPER_BLOCKS,
		HEIGHT_UPPER_BLOCKS);
	Wall secondUpperBlock(leftWall.x + leftWall.length + PACMAN_DRAWN_SIZE * 2 + firstUpperBlock.length,
		upWall.height + PACMAN_DRAWN_SIZE,
		LENGTH_UPPER_BLOCKS + 20,
		HEIGHT_UPPER_BLOCKS);
	Wall thirdUpperBlock(rightWall.x - firstUpperBlock.length - PACMAN_DRAWN_SIZE * 2 - secondUpperBlock.length,
		upWall.height + PACMAN_DRAWN_SIZE,
		LENGTH_UPPER_BLOCKS + 20,
		HEIGHT_UPPER_BLOCKS);
	Wall fourthUpperBlock(rightWall.x - firstUpperBlock.length - PACMAN_DRAWN_SIZE,
		upWall.height + PACMAN_DRAWN_SIZE,
		LENGTH_UPPER_BLOCKS,
		HEIGHT_UPPER_BLOCKS);

	walls.push_back(firstUpperBlock);
	walls.push_back(secondUpperBlock);
	walls.push_back(thirdUpperBlock);
	walls.push_back(fourthUpperBlock);
	
	//ONE WALL AT HALF OF SCREEN ON THE TOP
	Wall middleOfUpperRowWall(secondUpperBlock.x + secondUpperBlock.length + PACMAN_DRAWN_SIZE, 0, 26,
		41 + upWall.height + PACMAN_DRAWN_SIZE);

	walls.push_back(middleOfUpperRowWall);

	//GROUP OF 2 SMALLER BLOCKS UNDER GROUP OF 4 BLOCKS ON THE TOP 
	Wall leftSmallUpperBlock(leftWall.x + leftWall.length + PACMAN_DRAWN_SIZE,
		upWall.height + firstUpperBlock.height + PACMAN_DRAWN_SIZE * 2 + 5,
		LENGTH_UPPER_BLOCKS,
		HEIGHT_UPPER_BLOCKS / 2);
	Wall rightSmallUpperBlock(rightWall.x - leftWall.length + 5 + PACMAN_DRAWN_SIZE + leftSmallUpperBlock.length,
		upWall.height + firstUpperBlock.height + PACMAN_DRAWN_SIZE * 2 + 5,
		LENGTH_UPPER_BLOCKS,
		HEIGHT_UPPER_BLOCKS / 2);

	walls.push_back(leftSmallUpperBlock);
	walls.push_back(rightSmallUpperBlock);

	//GROUP OF 4 BLOCKS NEAR TWO EXITS
	Wall leftCenterUpperBlock(0,
		Y_BLOCKS_NEARBY_SIDE_EXITS,
		LENGTH_BLOCKS_NEARBY_SIDE_EXITS,
		HEIGHT_BLOCKS_NEARBY_SIDE_EXITS);
	Wall leftCenterDownBlock(0,
		Y_BLOCKS_NEARBY_SIDE_EXITS + leftCenterUpperBlock.height + PACMAN_DRAWN_SIZE,
		LENGTH_BLOCKS_NEARBY_SIDE_EXITS,
		HEIGHT_BLOCKS_NEARBY_SIDE_EXITS);
	Wall rightCenterUpperBlock(rightWall.x - leftWall.length + 5 + PACMAN_DRAWN_SIZE + leftSmallUpperBlock.length,
		Y_BLOCKS_NEARBY_SIDE_EXITS,
		LENGTH_BLOCKS_NEARBY_SIDE_EXITS,
		HEIGHT_BLOCKS_NEARBY_SIDE_EXITS);
	Wall rightCenterDownBlock(rightWall.x - leftWall.length + 5 + PACMAN_DRAWN_SIZE + leftSmallUpperBlock.length,
		Y_BLOCKS_NEARBY_SIDE_EXITS + leftCenterUpperBlock.height + PACMAN_DRAWN_SIZE,
		LENGTH_BLOCKS_NEARBY_SIDE_EXITS,
		HEIGHT_BLOCKS_NEARBY_SIDE_EXITS);

	walls.push_back(leftCenterUpperBlock);
	walls.push_back(leftCenterDownBlock);
	walls.push_back(rightCenterUpperBlock);
	walls.push_back(rightCenterDownBlock);

	//THREE T-SHAPED BLOCKS ABOVE CENTER OF THE BOARD
		//LEFT
		Wall leftUpperVerticalT(secondUpperBlock.x,
			leftSmallUpperBlock.y,
			WIDTH_OF_T_SHAPED_BLOCKS,
			(leftSmallUpperBlock.height + leftCenterUpperBlock.height + PACMAN_DRAWN_SIZE + 5));
		Wall leftUpperHorizontalT(secondUpperBlock.x,
			leftCenterUpperBlock.y,
			secondUpperBlock.length,
			WIDTH_OF_T_SHAPED_BLOCKS - 6);

		walls.push_back(leftUpperVerticalT);
		walls.push_back(leftUpperHorizontalT);

		//CENTER
		Wall centerUpperVerticalT(middleOfUpperRowWall.x + 2,
			leftSmallUpperBlock.y,
			middleOfUpperRowWall.length - 4,
			leftCenterUpperBlock.height - 5);
		Wall centerUpperHorizontalT(leftUpperVerticalT.x + leftUpperVerticalT.length + PACMAN_DRAWN_SIZE + 4,
			leftSmallUpperBlock.y,
			LENGTH_OF_T_SHAPED_CENTER_BLOCK,
			leftSmallUpperBlock.height);

		walls.push_back(centerUpperVerticalT);
		walls.push_back(centerUpperHorizontalT);

		//RIGHT
		Wall rightUpperVerticalT(thirdUpperBlock.x + thirdUpperBlock.length - WIDTH_OF_T_SHAPED_BLOCKS,
			leftSmallUpperBlock.y,
			WIDTH_OF_T_SHAPED_BLOCKS,
			leftUpperVerticalT.height);
		Wall rightUpperHorizontalT(thirdUpperBlock.x,
			leftCenterUpperBlock.y,
			thirdUpperBlock.length,
			WIDTH_OF_T_SHAPED_BLOCKS - 6);

		walls.push_back(rightUpperVerticalT);
		walls.push_back(rightUpperHorizontalT);

	//TWO VERTICAL WALLS IN THE MIDDLE OF THE BOARD
	Wall leftVerticalCenterWall(leftUpperVerticalT.x,
		leftCenterDownBlock.y,
		leftUpperVerticalT.length,
		leftCenterDownBlock.height);

	Wall rightVerticalCenterWall(rightUpperVerticalT.x,
		leftCenterDownBlock.y,
		leftUpperVerticalT.length,
		leftCenterDownBlock.height);

	walls.push_back(leftVerticalCenterWall);
	walls.push_back(rightVerticalCenterWall);

	//GROUP OF 2 SMALLER BLOCKS UNDER THE CENTER OF BOARD
	Wall leftSmallDownBlock(leftVerticalCenterWall.x,
		leftCenterDownBlock.y + 107,
		thirdUpperBlock.length,
		HEIGHT_UPPER_BLOCKS / 2);

	Wall rightSmallDownBlock(thirdUpperBlock.x,
		leftCenterDownBlock.y + 107,
		thirdUpperBlock.length,
		HEIGHT_UPPER_BLOCKS / 2);

	walls.push_back(leftSmallDownBlock);
	walls.push_back(rightSmallDownBlock);

	//CENTER BOX (DEPLOY POINT FOR GHOSTS)
	Wall centerBoxUp(centerUpperHorizontalT.x + 1,
		centerUpperHorizontalT.y + 107,
		centerUpperHorizontalT.length,
		WIDTH_OF_WALL_CENTER_BOX);

	Wall centerBoxBottom(centerUpperHorizontalT.x + 1,
		centerUpperHorizontalT.y + 93 +leftCenterDownBlock.height,
		centerUpperHorizontalT.length,
		WIDTH_OF_WALL_CENTER_BOX);

	Wall centerBoxLeft(centerUpperHorizontalT.x + 1,
		centerUpperHorizontalT.y + 107,
		WIDTH_OF_WALL_CENTER_BOX,
		leftCenterDownBlock.height - 5);

	Wall centerBoxRight(centerUpperHorizontalT.x + 1 + centerUpperHorizontalT.length - WIDTH_OF_WALL_CENTER_BOX,
		centerUpperHorizontalT.y + 107,
		WIDTH_OF_WALL_CENTER_BOX,
		leftCenterDownBlock.height - 5);

	walls.push_back(centerBoxUp);
	walls.push_back(centerBoxBottom);
	walls.push_back(centerBoxLeft);
	walls.push_back(centerBoxRight);

	//ONE T-SHAPED BLOCK UNDER CENTER OF THE BOARD
	Wall centerHorizontalT(centerUpperHorizontalT.x + 1,
		368,
		LENGTH_OF_T_SHAPED_CENTER_BLOCK,
		leftSmallUpperBlock.height + 4);
	Wall centerVerticalT(centerUpperVerticalT.x,
		centerHorizontalT.y,
		centerUpperVerticalT.length,
		centerUpperVerticalT.height);

	walls.push_back(centerHorizontalT);
	walls.push_back(centerVerticalT);

	//TWO L-SHAPED BLOCKS AT THE BOTTOM
		//LEFT
		Wall leftVerticalL(leftSmallUpperBlock.x + leftSmallUpperBlock.length - WIDTH_OF_T_SHAPED_BLOCKS,
			leftSmallDownBlock.y,
			WIDTH_OF_T_SHAPED_BLOCKS,
			leftCenterDownBlock.height - 3);
		Wall leftHorizontalL(leftSmallUpperBlock.x + leftSmallUpperBlock.length - (leftSmallUpperBlock.length - 4),
			leftSmallDownBlock.y,
			(leftSmallUpperBlock.length - 4),
			leftSmallDownBlock.height);

		walls.push_back(leftVerticalL);
		walls.push_back(leftHorizontalL);

		//RIGHT
		Wall rightVerticalL(rightCenterDownBlock.x,
			leftSmallDownBlock.y,
			WIDTH_OF_T_SHAPED_BLOCKS,
			leftCenterDownBlock.height - 3);
		Wall rightHorizontalL(rightCenterDownBlock.x,
			leftSmallDownBlock.y,
			(leftSmallUpperBlock.length - 3),
			leftSmallDownBlock.height);

		walls.push_back(rightVerticalL);
		walls.push_back(rightHorizontalL);

	//THREE T-SHAPED BLOCKS AT THE BOTTOM
		//LEFT
		Wall leftDownVerticalT(leftSmallDownBlock.x,
			Y_OF_DOWN_T_SHAPED_BLOCKS,
			WIDTH_OF_T_SHAPED_BLOCKS,
			leftVerticalL.height);
		Wall leftDownHorizontalT(leftHorizontalL.x,
			leftDownVerticalT.y + leftVerticalL.height - (WIDTH_OF_T_SHAPED_BLOCKS - 6),
			LENGTH_OF_DOWN_T_SH_BL_HORIZONTAL_PART,
			WIDTH_OF_T_SHAPED_BLOCKS - 6);

		walls.push_back(leftDownVerticalT);
		walls.push_back(leftDownHorizontalT);

		//CENTER
		Wall centerDownHorizontalT(centerUpperHorizontalT.x + 1,
			Y_OF_DOWN_T_SHAPED_BLOCKS,
			centerUpperHorizontalT.length,
			WIDTH_OF_T_SHAPED_BLOCKS - 6);
		Wall centerDownVerticalT(centerVerticalT.x,
			Y_OF_DOWN_T_SHAPED_BLOCKS,
			centerVerticalT.length,
			centerVerticalT.height);

		walls.push_back(centerDownVerticalT);
		walls.push_back(centerDownHorizontalT);

		//RIGHT
		Wall rightDownVerticalT(rightVerticalCenterWall.x,
			Y_OF_DOWN_T_SHAPED_BLOCKS,
			WIDTH_OF_T_SHAPED_BLOCKS,
			leftVerticalL.height);
		Wall rightDownHorizontalT(rightSmallDownBlock.x + 2,
			leftDownVerticalT.y + leftVerticalL.height - (WIDTH_OF_T_SHAPED_BLOCKS - 6),
			LENGTH_OF_DOWN_T_SH_BL_HORIZONTAL_PART,
			WIDTH_OF_T_SHAPED_BLOCKS - 4);

		walls.push_back(rightDownVerticalT);
		walls.push_back(rightDownHorizontalT);

	//TWO VERY SMALL WALLS AT THE BOTTOM
	Wall leftVerySmallWall(0,
		Y_OF_DOWN_T_SHAPED_BLOCKS,
		215,
		WIDTH_OF_T_SHAPED_BLOCKS - 6);
	Wall rightVerySmallWall(rightSmallUpperBlock.x + rightSmallUpperBlock.length,
		Y_OF_DOWN_T_SHAPED_BLOCKS,
		LENGTH_OF_DOWN_T_SH_BL_HORIZONTAL_PART,
		WIDTH_OF_T_SHAPED_BLOCKS - 4);

	walls.push_back(leftVerySmallWall);
	walls.push_back(rightVerySmallWall);

	CreateAllDots();
}

Labyrinth::Labyrinth(const Labyrinth& l)
{
	this->dots = l.dots;
	this->walls = l.walls;
	this->X_VALUES_OF_ROWS = l.X_VALUES_OF_ROWS;
}

Labyrinth::~Labyrinth()
{
}

std::vector<Wall> Labyrinth::Get_Walls()
{
	return this->walls;
}

std::vector<Dot> Labyrinth::Get_Dots()
{
	return this->dots;
}

std::vector<Dot>& Labyrinth::Get_Dots_R()
{
	return this->dots;
}

void Labyrinth::Set_Dots(std::vector<Dot> toSet)
{
	this->dots = toSet;
}


void Labyrinth::CreateAllDots()
{
	CreateSuperDots();
	CreateDotsInColumns();
	CreateDotsInRows();
}

void Labyrinth::CreateDotsInColumns()
{
	Dot dot(false);
	
	// 2 PAIRS OF DOTS BETWEEN 1 AND 3 COLUMNS AND 7 AND 8
	for (int i = 23; i < NUMBER_OF_ROWS; i++)
	{
		if (i >= 25) //ominiecie scian, zeby na nich nie rysowac
			break;
		dot.circle.setPosition(float(194.0f + (18.0f * 2)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	for (int i = 23; i < NUMBER_OF_ROWS; i++)
	{
		if (i >= 25) //ominiecie scian, zeby na nich nie rysowac
			break;
		dot.circle.setPosition(float(194.0f + (18.0f * 23)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//FIRST COLUMN
	for (int i = 1; i < NUMBER_OF_ROWS - 1; i++)
	{
		if (CheckIfRowIsBad(i) || (i >= 8 && i <= 18) || (i >= 23 && i <= 24) || i == 2)
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 0)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//SECOND COLUMN
	for (int i = 1; i < NUMBER_OF_ROWS; i++)
	{
		if (CheckIfRowIsBad(i) || i >= 26 || i == 22)
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 5)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//THIRD COLUMN
	for (int i = 5; i < NUMBER_OF_ROWS; i++)
	{
		if ((i >= 7 && i <= 22) || (i >= 25 && i <= 26) || i >= 27)
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 8)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//FOURTH COLUMN
	for (int i = 1; i < NUMBER_OF_ROWS; i++)
	{
		if ((i >= 4 && i <= 19) || (i >= 22 && i <= 25) || i >= 28)
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 11)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//FIFTH COLUMN
	for (int i = 1; i < NUMBER_OF_ROWS; i++)
	{
		if ((i >= 4 && i <= 19) || (i >= 22 && i <= 25) || i >= 28)
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 14)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//SIXTH COLUMN
	for (int i = 5; i < NUMBER_OF_ROWS; i++)
	{
		if ((i >= 7 && i <= 22) || (i >= 25 && i <= 26) || i >= 27)
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 17)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//SEVENTH COLUMN
	for (int i = 1; i < NUMBER_OF_ROWS; i++)
	{
		if (CheckIfRowIsBad(i)|| i >= 26 || i == 22)
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 20)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}

	//EIGHTH COLUMN
	for (int i = 1; i < NUMBER_OF_ROWS - 1; i++)
	{
		if (CheckIfRowIsBad(i) || (i >= 8 && i <= 18) || (i >= 23 && i <= 24) || i == 2 )
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * 25)), float(64.0f + (18.0 * i)));
		dots.push_back(dot);
	}
}

void Labyrinth::CreateDotsInRows()
{
	Dot dot(false);

	//FIRST ROW
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		if (i >= 12 && i <= 13) //ominiecie scian, zeby na nich nie rysowac
			continue;
		dot.circle.setPosition(float(194.0f + (18.0f * i)), float(64.0f + (18.0 * 0)));
		dots.push_back(dot);
	}

	//SECOND ROW
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		dot.circle.setPosition(194.0f + (18.0f * i), 64.0f + (18.0 * 4));
		dots.push_back(dot);
	}

	//THIRD ROW
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		if ((i >= 6 && i <= 7) || (i >= 12 && i <= 13) || (i >= 18 && i <= 19))
			continue;
		dot.circle.setPosition(194.0f + (18.0f * i), 64.0f + (18.0 * 7));
		dots.push_back(dot);
	}

	//FOURTH ROW
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		if (i >= 12 && i <= 13)
			continue;
		dot.circle.setPosition(194.0f + (18.0f * i), 64.0f + (18.0 * 19));
		dots.push_back(dot);
	}

	//FIFTH ROW
	for (int i = 1; i < NUMBER_OF_COLUMNS - 1; i++)
	{// FROM 1 TO N_O_C - 1 TO MAKE ROOM FOR SUPER DOTS! 
		if ((i >= 3 && i <= 4) || (i >= 21 && i <= 22))
			continue;
		dot.circle.setPosition(194.0f + (18.0f * i), 64.0f + (18.0 * 22));
		dots.push_back(dot);
	}

	//SIXTH ROW
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		if ((i >= 6 && i <= 7) || (i >= 12 && i <= 13) || (i >= 18 && i <= 19))
			continue;
		dot.circle.setPosition(194.0f + (18.0f * i), 64.0f + (18.0 * 25));
		dots.push_back(dot);
	}

	//SEVENTH ROW
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		dot.circle.setPosition(194.0f + (18.0f * i), 64.0f + (18.0 * 28));
		dots.push_back(dot);
	}
}

void Labyrinth::CreateSuperDots()
{
	Dot dot(true);

	dot.circle.setPosition(UP_LEFT_SUPER_DOT, UP_RIGHT_SUPER_DOT); //UP, LEFT
	dots.push_back(dot);
	dot.circle.setPosition(UP_LEFT_SUPER_DOT, DOWN_RIGHT_SUPER_DOT); //DOWN, LEFT
	dots.push_back(dot);
	dot.circle.setPosition(DOWN_LEFT_SUPER_DOT, UP_RIGHT_SUPER_DOT); //UP, RIGHT
	dots.push_back(dot);
	dot.circle.setPosition(DOWN_LEFT_SUPER_DOT, DOWN_RIGHT_SUPER_DOT); //DOWN, RIGHT
	dots.push_back(dot);

}

bool Labyrinth::CheckIfRowIsBad(int i)
{
	if (std::find(X_VALUES_OF_ROWS.begin(), X_VALUES_OF_ROWS.end(), i) != X_VALUES_OF_ROWS.end())
		return true; //ELEMENT IS FOUND, SO ROW ISN'T GOOD
	else return false;
}