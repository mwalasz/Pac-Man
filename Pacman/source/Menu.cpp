#include "Menu.h"

Menu::Menu(float width, float height) : selectedItemIndex(0)
{
	if (!font.loadFromFile(FONTS_PATH + CHEAPMOT_FONT))
		throw NoFontLoadedException();
	else
	{
		menu[0].setFont(font);
		menu[0].setColor(sf::Color::Yellow);
		menu[0].setString(PLAY_MENU);
		menu[0].setPosition(SCREEN_WIDTH / 2 - 20, height / (MAX_NUMBER_OF_MENU_OPTIONS + 1 ) * 1 + 200);

		menu[1].setFont(font);
		menu[1].setColor(sf::Color::White);
		menu[1].setString(HIGHSCORES_MENU);
		menu[1].setPosition(SCREEN_WIDTH / 2 - 80, height / (MAX_NUMBER_OF_MENU_OPTIONS + 1) * 2 + 100);

		menu[2].setFont(font);
		menu[2].setColor(sf::Color::White);
		menu[2].setString(EXIT_MENU);
		menu[2].setPosition(SCREEN_WIDTH / 2 - 20, height / (MAX_NUMBER_OF_MENU_OPTIONS + 1) * 3);

		mainTitle.setFont(font);
		mainTitle.setCharacterSize(BIG_FONT_SIZE);
		mainTitle.setColor(sf::Color::White);
		mainTitle.setString(TITLE_MENU);
		mainTitle.setPosition(120, 50);

		highScoresMainTitle.setFont(font);
		highScoresMainTitle.setCharacterSize(BIG_FONT_SIZE);
		highScoresMainTitle.setColor(sf::Color::Blue);
		highScoresMainTitle.setString(HIGHSCORES_MENU);
		highScoresMainTitle.setPosition(120, 50);

		numberOfResultToDisply.setFont(font);
		numberOfResultToDisply.setColor(sf::Color::Yellow);

		nameToDisplay.setFont(font);
		nameToDisplay.setColor(sf::Color::White);

		scoreToDisplay.setFont(font);
		scoreToDisplay.setColor(sf::Color::White);

		comunicatAboutNoData.setFont(font);
		comunicatAboutNoData.setColor(sf::Color::Red);
		comunicatAboutNoData.setString(COMUNICAT_ABOUT_NO_DATA_IN_FILE);
		comunicatAboutNoData.setPosition(highScoresMainTitle.getPosition().x + 70, 200);

		titleEnterName.setFont(font);
		titleEnterName.setCharacterSize(FONT_SIZE);
		titleEnterName.setColor(sf::Color::Red);
		titleEnterName.setString(COMUNICAT_ABOUT_NAME_INPUT);
		titleEnterName.setPosition(highScoresMainTitle.getPosition().x + 70, 180);

		enteredName.setFont(font);
		enteredName.setCharacterSize(FONT_SIZE);
		enteredName.setColor(sf::Color::White);
		enteredName.setPosition(highScoresMainTitle.getPosition().x + 140, 400);

		wrongNameEntered.setFont(font);
		wrongNameEntered.setCharacterSize(FONT_SIZE);
		wrongNameEntered.setColor(sf::Color::Yellow);
		wrongNameEntered.setString(COMUNICAT_ABOUT_WRONG_NAME_ENTERED);
		wrongNameEntered.setPosition(highScoresMainTitle.getPosition().x + 180, 300);

		rect.setFillColor(sf::Color::Black);
		rect.setOutlineColor(sf::Color::Blue);
		rect.setOutlineThickness(4);
		rect.setSize(sf::Vector2f(380, 55));
		rect.setPosition(enteredName.getPosition().x - 10, enteredName.getPosition().y - 10);

		tooLongText.setFont(font);
		tooLongText.setCharacterSize(FONT_SIZE);
		tooLongText.setColor(sf::Color::Yellow);
		tooLongText.setString(COMUNICAT_ABOUT_TOO_LONG_INPUT);
		tooLongText.setPosition(highScoresMainTitle.getPosition().x + 170, 500);

		pacman.Set_Position(0.0, 200.0);
	}
}

Menu::~Menu()
{
}

int Menu::Get_PressedItem()
{
	return selectedItemIndex; 
}

void Menu::DisplayHighscores(sf::RenderWindow & window, Results result)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;

			if (event.type == sf::Event::KeyPressed)
				window.clear();
		}

		window.clear();

		window.draw(highScoresMainTitle);

		int vectorSize = result.playersResultsFromFile.size();

		if (vectorSize > MAX_NUMBER_OF_DISPLAYED_RESULTS)
			vectorSize = MAX_NUMBER_OF_DISPLAYED_RESULTS;

		if (vectorSize == 0)
			window.draw(comunicatAboutNoData);
		else
		{
			numberOfResultToDisply.setString(NUMB_TABLE_LABEL);
			numberOfResultToDisply.setPosition(180.f, float(150.f + 0 * 50.f));
			window.draw(numberOfResultToDisply);

			nameToDisplay.setString(NAME_TABLE_LABEL);
			nameToDisplay.setPosition(300.f, float(150.f + 0 * 50.f));
			window.draw(nameToDisplay);

			scoreToDisplay.setString(SCORE_TABLE_LABEL);
			scoreToDisplay.setPosition(550.f, float(150.f + 0 * 50.f));
			window.draw(scoreToDisplay);

			for (int i = 0; i < vectorSize; i++)
			{
				numberOfResultToDisply.setString(std::to_string(i + 1));
				numberOfResultToDisply.setPosition(250.f, float(200.f + i * 50.f));
				window.draw(numberOfResultToDisply);

				nameToDisplay.setString(result.playersResultsFromFile[i].first);
				nameToDisplay.setPosition(300.f, float(200.f + i * 50.f));
				window.draw(nameToDisplay);

				scoreToDisplay.setString(std::to_string(result.playersResultsFromFile[i].second));
				scoreToDisplay.setPosition(550.f, float(200.f + i * 50.f));
				window.draw(scoreToDisplay);
			}
		}
		window.display();
	}
}

void Menu::Draw(sf::RenderWindow & window)
{
	window.draw(mainTitle);

	for (int i = 0; i < MAX_NUMBER_OF_MENU_OPTIONS; i++)
		window.draw(menu[i]);

	PacmanMenuAnimation(window);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_MENU_OPTIONS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;

		if(selectedItemIndex == MAX_NUMBER_OF_MENU_OPTIONS - 1)
			menu[selectedItemIndex].setColor(sf::Color::Red);
		else menu[selectedItemIndex].setColor(sf::Color::Yellow);
	}
}

bool Menu::Get_PlayerName(Player & player, sf::RenderWindow& window) 
{
	std::string tempString;
	std::regex patternToFit(REGEX_PATTERN);
	bool isRegexWrong = false;
	bool isTextTooLong = false;

	enteredName.setString("");

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return false;

			if (event.type == sf::Event::KeyPressed)
			{
				isRegexWrong = false;
				isTextTooLong = false;

				window.clear();
			}

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 123)
				{
					if (event.text.unicode != sf::Keyboard::Key::Enter && event.text.unicode != sf::Keyboard::Key::Escape)
					{
						if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace)
							&& tempString.length() < MAX_LENGTH_OF_ENTERED_NAME)
						{
							tempString += static_cast<char>(event.text.unicode);
							enteredName.setString(tempString);
						} //putting new sign into string
						else if(tempString.length() >= MAX_LENGTH_OF_ENTERED_NAME)
							isTextTooLong = true;
					}
				}
	
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace))
				{
					if (tempString.length() != 0)
					{
						tempString.pop_back();
						enteredName.setString(tempString);
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					tempString.pop_back(); //removing addded enter character on the end
					if (std::regex_match(tempString, patternToFit) && !isTextTooLong)
					{
						enteredName.setString(tempString);
						player.Set_Name(tempString);
						return true;
					}
					else isRegexWrong = true;
				}
			}
			else if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();

		window.draw(titleEnterName);
		window.draw(rect);
		window.draw(enteredName);

		if (isTextTooLong)
			window.draw(tooLongText);

		if(isRegexWrong)
			window.draw(wrongNameEntered);
		
		window.display();
	}
}
