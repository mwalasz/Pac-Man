#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Constants.h"
#include "Wall.h"

class Character
{
public:
	Character();
	virtual ~Character() = 0;

	enum Directions{Up = 0, Right, Down, Left};
	
	int counterWalking = 0; //to change? another animation mechanism
	
	/*	Getters	 */
	bool Get_CanMoveUp();
	bool Get_CanMoveDown();
	bool Get_CanMoveRight();
	bool Get_CanMoveLeft();
	Directions Get_Direction();
	sf::Sprite Get_Sprite();
	float Get_MovementSpeed();

	/*	Setters	 */
	void Set_CanMoveUp(bool toSet);
	void Set_CanMoveDown(bool toSet);
	void Set_CanMoveRight(bool toSet);
	void Set_CanMoveLeft(bool toSet);
	void Set_AllCanMoveParameters(bool toSet);
	void Set_Direction(Directions toSet);
	void Set_Position(float x, float y);
	void Set_MovementSpeed(float toSet);

	/*	Methods	 */
	void SetDirectionFromKeyboardInput();
	bool CheckCollision(std::vector<Wall> walls);
	Character::Directions GetRandomDirection(Character::Directions previuosDirection);

protected:
	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;

private:
	bool canMoveUp;
	bool canMoveRight;
	bool canMoveDown;
	bool canMoveLeft;

	Directions direction;

	//int counterWalking = 0; //to change? another animation mechanism
};