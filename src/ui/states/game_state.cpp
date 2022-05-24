#include "../../../headers/ui/states/game_state.hpp"

#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <stdlib.h> // srand, rand
#include <time.h>	//time
#include "../../../headers/consts.hpp"

GameState::GameState(StatesStack *stackPointer,
					 sf::RenderWindow *window,
					 GraphicSettings *settings,
					 GameController *gameController)
	: State(stackPointer, window, settings, gameController)
{
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->initBoardButtons();
	this->drawBoard();
}

GameState::~GameState()
{
}

void GameState::initTextures()
{
	std::array<std::string, 10> paths = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
	std::stringstream backgroundPath;
	srand(time(NULL));
	backgroundPath << "../textures/backgrounds/battleback" << paths[rand() % 10] << ".png";
	if (!this->backgroundTX.loadFromFile(backgroundPath.str()))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["START_BUTTON"].loadFromFile("../textures/button.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["EXIT_BUTTON"].loadFromFile("../textures/button.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["FIELD"].loadFromFile("../textures/field.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["FIELD_RED"].loadFromFile("../textures/field_red.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["FIELD_GREEN"].loadFromFile("../textures/field_green.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["KNIGHT"].loadFromFile("../textures/knight.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ARCHER"].loadFromFile("../textures/archer.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ICE_DRUID"].loadFromFile("../textures/ice_druid.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["WIZARD"].loadFromFile("../textures/wizard.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["CATAPULT"].loadFromFile("../textures/catapult.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["TREBUCHET"].loadFromFile("../textures/trebuchet.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["NINJA"].loadFromFile("../textures/ninja.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["MEDIC"].loadFromFile("../textures/medic.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("../src/ui/states/Dosis-Light.ttf"))
	{
		throw("ERROR::GameSTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initGui()
{
	const sf::VideoMode &vm = this->settings->resolution;

	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.width,
			(float)vm.height));

	this->backgroundRect.setTexture(&this->backgroundTX);

	// float buttonWidth = 200, buttonHeight = 100;
	// float topLeft_x = (vm.width - buttonWidth) / 2;
	// float topLeft_y = 200;

	// topLeft_y += 2*buttonHeight;

	// this->buttons["EXIT"] = std::make_shared<Button>(
	// 	0, 0, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "EXIT", 30,
	// 	textures["EXIT_BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1);
}

void GameState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

void GameState::initBoardButtons()
{
	auto board = this->gameController->getBoard();
	for (unsigned int row = 0; row < BOARD_ROWS; row++)
	{
		int boardLeftTopX = (this->settings->resolution.width / 2) - (BOARD_COLUMNS * FIELD_SIZE / 2);
		int boardLeftTopY = (this->settings->resolution.height / 2) - (BOARD_ROWS * FIELD_SIZE / 2);

		for (unsigned int column = 0; column < BOARD_COLUMNS; column++)
		{
			auto field = board->getFieldByCoordinate(row, column);
			int buttonX = boardLeftTopX + FIELD_SIZE * column;
			int buttonY = boardLeftTopY + FIELD_SIZE * row;
			int buttonId = row * BOARD_COLUMNS + column;
			sf::Texture fieldTX;
			if (field->getHero() == std::nullopt)
			{
				fieldTX = textures["FIELD"];
			}
			else
			{
				if (field->getHero().value()->getOwner() == Player::First)
				{
					fieldTX = textures["FIELD_GREEN"];
				}
				else
				{
					fieldTX = textures["FIELD_RED"];
				}
			}

			this->boardButtons[std::make_tuple(row, column)] = std::make_shared<Button>(buttonX, buttonY, 100, 100, std::make_shared<sf::Font>(this->font),
																						"", 0, textures["FIELD"],
																						sf::Color::White, sf::Color::Green, sf::Color::Yellow, buttonId);
		}
	}
}

void GameState::drawBoard()
{
	updateSprites();
	auto board = this->gameController->getBoard();
	for (auto row : board->getFields())
	{
		for (auto field : row)
		{
			this->window->draw(field->sprite);

			if (field->isFree() == false)
			{
				auto hero = field->getHero();
				window->draw(hero.value()->sprite);
			}
		}
	}
}

void GameState::updateSprites()
{
}

void GameState::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}
	for (auto &it : this->boardButtons)
	{
		it.second->update(this->mousePos);
	}
	// if (this->buttons["EXIT"]->isClicked())
	// {
	// 	this->endState();
	// }
}

void GameState::update()
{
	this->updateMousePosition();
	this->updateButtons();
}

void GameState::renderButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}
	for (auto &it : this->boardButtons)
	{
		it.second->render(*this->window);
	}
}

void GameState::render()
{
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}
