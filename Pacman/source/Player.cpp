#include "Player.h"

Player::Player() : name("Anonymous"), results()
{
}

Player::~Player()
{
}

std::string Player::Get_Name()
{
	return this->name;
}

void Player::Set_Name(std::string toSet)
{
	this->name = toSet;
}
