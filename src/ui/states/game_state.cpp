#include "../../../headers/ui/states/game_state.hpp"

#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <stdlib.h> // srand, rand
#include <time.h>	//time
#include "../../../headers/consts.hpp"
#include "../../../headers/ui/action_menu_buttons.hpp"

GameState::GameState(StatesStack *stackPointer,
					 sf::RenderWindow *window,
					 GraphicSettings *settings,
					 GameController *gameController)
	: State(stackPointer, window, settings, gameController)
{
	this->addTestValuesToBoard();
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->initBoardButtons();
	// this->drawBoard();
}

GameState::~GameState()
{
}

void GameState::addTestValuesToBoard()
{
	auto board = this->gameController->getBoard();
	auto field1 = board->getFieldByCoordinate(0, 2);
	auto hero1 = std::make_shared<Knight>();
	hero1->setOwner(Player::First);
	field1->addHero(hero1);
	auto field2 = board->getFieldByCoordinate(4, 0);
	auto hero2 = std::make_shared<Catapult>();
	hero2->setOwner(Player::First);
	field2->addHero(hero2);
	auto field3 = board->getFieldByCoordinate(5, 1);
	auto hero3 = std::make_shared<Medic>();
	hero3->setOwner(Player::First);
	field3->addHero(hero3);
	auto field4 = board->getFieldByCoordinate(3, 4);
	auto hero4 = std::make_shared<Mage>();
	hero4->setOwner(Player::First);
	field4->addHero(hero4);

	auto field5 = board->getFieldByCoordinate(3, 7);
	auto hero5 = std::make_shared<Archer>();
	hero5->setOwner(Player::Second);
	field5->addHero(hero5);
	auto field6 = board->getFieldByCoordinate(0, 9);
	auto hero6 = std::make_shared<Trebuchet>();
	hero6->setOwner(Player::Second);
	field6->addHero(hero6);
	auto field7 = board->getFieldByCoordinate(2, 6);
	auto hero7 = std::make_shared<Ninja>();
	hero7->setOwner(Player::Second);
	field7->addHero(hero7);
	auto field8 = board->getFieldByCoordinate(5, 8);
	auto hero8 = std::make_shared<IceDruid>();
	hero8->setOwner(Player::Second);
	field8->addHero(hero8);
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
	if (!this->textures["ACTION_MENU_1"].loadFromFile("../textures/action_menu_1.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ACTION_MENU_2"].loadFromFile("../textures/action_menu_2.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ACTION_MENU_3"].loadFromFile("../textures/action_menu_3.png"))
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

	this->buttons["EXIT"] = std::make_shared<Button>(
		vm.width - 100.f, 0.f, 100.f, 50.f, std::make_shared<sf::Font>(this->font), "EXIT", 30,
		textures["EXIT_BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1);
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
				showHero(field->getHero().value(), buttonX, buttonY);
			}

			this->boardButtons[std::make_tuple(row, column)] = std::make_shared<Button>(buttonX, buttonY, 100, 100, std::make_shared<sf::Font>(this->font),
																						"", 0, fieldTX,
																						sf::Color::White, sf::Color::Green, sf::Color::Yellow, buttonId);
		}
	}
}

void GameState::showHero(std::shared_ptr<Hero> hero, int buttonX, int buttonY)
{
	hero->sprite.setPosition(buttonX, buttonY);
	switch (hero->getType())
	{
	case HeroType::EKnight:
		hero->sprite.setTexture(textures["KNIGHT"]);
		break;
	case HeroType::EArcher:
		hero->sprite.setTexture(textures["ARCHER"]);
		break;
	case HeroType::EWizard:
		hero->sprite.setTexture(textures["WIZARD"]);
		break;
	case HeroType::EIceDruid:
		hero->sprite.setTexture(textures["ICE_DRUID"]);
		break;
	case HeroType::ECatapult:
		hero->sprite.setTexture(textures["CATAPULT"]);
		break;
	case HeroType::EMedic:
		hero->sprite.setTexture(textures["MEDIC"]);
		break;
	case HeroType::ENinja:
		hero->sprite.setTexture(textures["NINJA"]);
		break;
	case HeroType::ETrebuchet:
		hero->sprite.setTexture(textures["TREBUCHET"]);
		break;
	default:
		hero->sprite.setTexture(textures["KNIGHT"]);
		break;
	}
	if (hero->getOwner() == Player::Second)
	{
		hero->sprite.setTextureRect(sf::IntRect(FIELD_SIZE, 0, -FIELD_SIZE, FIELD_SIZE)); // Symetria względem osi OY
	}
	window->draw(hero->sprite);
}

void GameState::showActionMenu(std::shared_ptr<Button> button)
{
	int buttonId = button->getId();
	auto field = gameController->getBoard()->getFieldByCoordinate(buttonId / BOARD_COLUMNS, buttonId % BOARD_COLUMNS);
	if (field->getHero() != std::nullopt)
	{
		sf::Texture *actionMenuTX;
		sf::Vector2f actionMenuSize;
		switch (field->getHero().value()->getType())
		{
		case EMedic:
			actionMenuTX = &textures["ACTION_MENU_3"];
			actionMenuSize = THREE_ACTION_SIZE;
			break;
		case ETrebuchet:
		case ECatapult:
			actionMenuTX = &textures["ACTION_MENU_1"];
			actionMenuSize = ONE_ACTION_SIZE;
			break;
		default:
			actionMenuTX = &textures["ACTION_MENU_2"];
			actionMenuSize = TWO_ACTION_SIZE;
			break;
		}
		auto butPos = button->getRect().getPosition();
		float coorX = butPos.x + ((FIELD_SIZE - actionMenuSize.x) / 2);
		float coorY = butPos.y - actionMenuTX->getSize().y / 2;

		this->actionMenu = std::make_shared<ActionMenu>(sf::Vector2f(coorX, coorY), actionMenuSize, *actionMenuTX, button);
	}
}

void GameState::update()
{
	this->updateMousePosition();
	this->updateButtons();
	if (this->actionMenu != std::nullopt)
	{
		this->updateActionMenu();
	}
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
		if (it.second->isClicked())
		{
			showActionMenu(it.second);
		}
	}
	if (this->buttons["EXIT"]->isClicked())
	{
		this->endState();
	}
}

void GameState::updateActionMenu()
{
	this->actionMenu.value()->update(this->mousePos);
}

void GameState::renderHeroes()
{
	auto board = gameController->getBoard();
	for (auto row : board->getFields())
	{
		for (auto field : row)
		{
			if (field->getHero() != std::nullopt)
			{
				window->draw(field->getHero().value()->sprite);
			}
		}
	}
}

void GameState::renderActionMenu()
{
	if (this->actionMenu.value()->shouldBeClosed())
	{
		this->actionMenu = std::nullopt;
	}
	else
	{
		this->actionMenu.value()->render(*this->window);
	}
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
	// std::cout << this->settings->resolution.width << "  " << this->settings->resolution.height << std::endl;
	this->window->draw(this->backgroundRect);
	this->renderButtons();
	this->renderHeroes();
	if (this->actionMenu != std::nullopt)
	{
		this->renderActionMenu();
	}
}
