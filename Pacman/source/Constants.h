#pragma once
#include <string>

	const int NUMBER_OF_LIFES = 3;
	const int MAX_LENGTH_OF_ENTERED_NAME = 11;

//FILE PATHS & FILE NAMES
	const std::string FONTS_PATH = "../Pacman/fonts/";
	const std::string SOUNDS_PATH = "../Pacman/sounds/";
	const std::string BACKGROUND_PATH = "../Pacman/pictures/background.png";
	const std::string FOOD_PICTURES_PATH = "../Pacman/pictures/food/";
	const std::string SPRITE_SHEETS_PATH = "../Pacman/pictures/spritesheets/";
	const std::string RESULTS_PATH = "../Pacman/results/results.txt";

	const std::string PACMAN_SPRITESHEET = "pacman_ss.png";
	const std::string DEAD_PACMAN_SPRITESHEET = "dead_pacman_ss.png";
	const std::string BLUE_GHOST_SPRITESHEET = "blue_ghost_ss.png";
	const std::string ORANGE_GHOST_SPRITESHEET = "orange_ghost_ss.png";
	const std::string PINK_GHOST_SPRITESHEET = "pink_ghost_ss.png";
	const std::string RED_GHOST_SPRITESHEET = "red_ghost_ss.png";

	const std::string BOING_FONT = "boing.ttf";
	const std::string CHEAPMOT_FONT = "cheapmot.ttf";
	const std::string SIREN_SOUND = "siren_medium.wav";
	const std::string DEATH_SOUND = "death_1.wav";
	const std::string COIN_SOUND = "insert_coin.wav";
	const std::string INTRO_SOUND = "intro.wav";

//WINDOW DIMENSIONS
	const int SCREEN_HEIGHT = 630;
	const int SCREEN_WIDTH = 840;
	const int LINES = 30;
	const int COLUMNS = 28;

//FOR TEXTURE RENDERING
	const unsigned int GRAPHIC_SIZE = 24;
	const unsigned int PACMAN_DRAWN_SIZE = GRAPHIC_SIZE + 5;

//TEXT RENDERING
	const unsigned int FONT_SIZE = 30;
	const unsigned int BIG_FONT_SIZE = 80;
	const float X_INITIAL_POSITION_OF_TEXT = SCREEN_WIDTH - 140.0f;
	const float Y_INITIAL_POSITION_OF_TEXT = 77.0f;
	const float INTERSPACE_BETWEEN_TEXTS = 60.0f;

//DISPLAYED TEXTS
	const std::string REGEX_PATTERN = "^[a-zA-Z]+";

	const std::string PLAYER_LABEL = "Player:";
	const std::string SCORE_LABEL = "Score:";
	const std::string LEVEL_LABEL = "Level:";
	const std::string LIVES_LABEL = "Lives:";

	const std::string NAME_TABLE_LABEL = "NAME";
	const std::string NUMB_TABLE_LABEL = "NUM.";
	const std::string SCORE_TABLE_LABEL = "SCORE";

	const std::string PLAY_MENU = "PLAY";
	const std::string TITLE_MENU = "P A C M A N";
	const std::string HIGHSCORES_MENU = "HIGHSCORES";
	const std::string EXIT_MENU = "EXIT";
	const std::string COMUNICAT_ABOUT_NO_DATA_IN_FILE = "No games were played!";
	const std::string COMUNICAT_ABOUT_WRONG_NAME_ENTERED = "Wrong input!";
	const std::string COMUNICAT_ABOUT_NAME_INPUT = "Please enter your name: ";
	const std::string COMUNICAT_ABOUT_TOO_LONG_INPUT = "TOO LONG INPUT!";
	const std::string PAUSE_LABEL = "GAME PAUSED";
	const std::string START_OF_GAME_INFO = "GET READY!";
	const std::string GAME_OVER_INFO = "GAME OVER!";
	const std::string WIN_INFO = "YOU WON!";
	const int MAX_NUMBER_OF_DISPLAYED_RESULTS = 8;

//LABIRYNTH.CPP
	//CENTER BOX
	const int WIDTH_OF_WALL_CENTER_BOX = 8;

	//GROUP OF 4 WIDER BLOCKS ON THE TOP
	const int LENGTH_UPPER_BLOCKS = 59;
	const int HEIGHT_UPPER_BLOCKS = 41;

	//GROUP OF 4 BLOCKS NEAR TWO EXITS
	const int Y_BLOCKS_NEARBY_SIDE_EXITS = 207;
	const int LENGTH_BLOCKS_NEARBY_SIDE_EXITS = 270;
	const int HEIGHT_BLOCKS_NEARBY_SIDE_EXITS = 78;

	//THREE T-SHAPED BLOCKS ABOVE CENTER OF THE BOARD
	const int WIDTH_OF_T_SHAPED_BLOCKS = 25;
	const int LENGTH_OF_T_SHAPED_CENTER_BLOCK = 125;

	//TWO SMALL BLOCKS UNDER THE CENTER OF BOARD
	const int LENGTH_OF_SMALLER_DOWN_BLOCKS = LENGTH_UPPER_BLOCKS + 20;

	//THREE T-SHAPED BLOCKS AT THE BOTTOM
	const int Y_OF_DOWN_T_SHAPED_BLOCKS = 475;
	const int LENGTH_OF_DOWN_T_SH_BL_HORIZONTAL_PART = 160;

//PACMAN.CPP -> MOVE()
	const int X_LEFT_ENTRY_POINT_SIDE_EXITS = 182;
	const int X_RIGHT_ENTRY_POINT_SIDE_EXITS = 635;
	const float Y_TOP_ENTRY_POINT_SIDE_EXITS = 283.5;
	const float Y_BOTTOM_ENTRY_POINT_SIDE_EXITS = 287.5;

//ROWS AND COLUMNS IN DOTS.H
	const int NUMBER_OF_ROWS = 29;
	const int NUMBER_OF_COLUMNS = 26;

//POINTS VALUE FOR DOTS
	const int SUPER_DOT_POINTS = 100;
	const int DOT_POINTS = 10;

//SUPER DOTS COORDINATES
	const float UP_LEFT_SUPER_DOT = 194.0f;
	const float DOWN_LEFT_SUPER_DOT = 644.0f;
	const float UP_RIGHT_SUPER_DOT = 100.0f;
	const float DOWN_RIGHT_SUPER_DOT = 460.0f;

//MENU
	const int MAX_NUMBER_OF_MENU_OPTIONS = 3;

//INITIAL CHARACTERS POSITIONS
	const float INTERSPACE_BETWEEN_SPRITES = 2.f;

	const float PACMAN_X = 413.f;
	const float PACMAN_Y = 449.f;

	const float BLUE_GHOST_X = 371.f;
	const float BLUE_GHOST_Y = 285.f;
	const float BLUE_GHOST_X_INIT = 186.f;
	const float BLUE_GHOST_Y_INIT = 430.f;

	const float PINK_GHOST_X = BLUE_GHOST_X + INTERSPACE_BETWEEN_SPRITES + GRAPHIC_SIZE;
	const float PINK_GHOST_Y = 285.f;
	const float PINK_GHOST_X_INIT = 636.f;
	const float PINK_GHOST_Y_INIT = 430.f;

	const float ORANGE_GHOST_X = PINK_GHOST_X + INTERSPACE_BETWEEN_SPRITES + GRAPHIC_SIZE;
	const float ORANGE_GHOST_Y = 285.f;
	const float ORANGE_GHOST_X_INIT = 636.f;
	const float ORANGE_GHOST_Y_INIT = 110.f;

	const float RED_GHOST_X = ORANGE_GHOST_X + INTERSPACE_BETWEEN_SPRITES + GRAPHIC_SIZE;
	const float RED_GHOST_Y = 285.f;
	const float RED_GHOST_X_INIT = 186.f;
	const float RED_GHOST_Y_INIT = 110.f;

//INITIAL CHARACTERS MOVEMENT SPEEDS
	const float PACMAN_SPEED_INIT = 0.16f;
	const float PACMAN_SPEED_FRIGHTENING = PACMAN_SPEED_INIT * 2;

	const float RED_GHOST_SPEED_INIT = 0.22f;
	const float RED_GHOST_SPEED_SCARED = RED_GHOST_SPEED_INIT / 2;

	const float ORANGE_GHOST_SPEED_INIT = 0.22f;
	const float ORANGE_GHOST_SPEED_SCARED = ORANGE_GHOST_SPEED_INIT / 2;

	const float BLUE_GHOST_SPEED_INIT = 0.18f;
	const float BLUE_GHOST_SPEED_SCARED = BLUE_GHOST_SPEED_INIT / 2;
	
	const float PINK_GHOST_SPEED_INIT = 0.3f;
	const float PINK_GHOST_SPEED_SCARED = PINK_GHOST_SPEED_INIT / 3;

//DURATION OF ACTIONS
	const float SCARE_MODE_DURATION = 4.0f;