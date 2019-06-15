#include "Exceptions.h"
#include "Game.h"
#include "vld.h"

int main()
{
	try
	{
		Game game;
		game.MainLoop();
		
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Following error occurred: " << e.what() << std::endl;
	}
}