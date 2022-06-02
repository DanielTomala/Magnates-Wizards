#include "../../../headers/ui/states/game_state.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <sstream>
#include <stdlib.h> // srand, rand
#include <time.h>	//time
#include <vector>
#include "../../../headers/consts.hpp"
#include "../../../headers/ui/action_menu_buttons.hpp"
#include "../../../headers/ui/HPbar.hpp"

GameState::GameState(StatesStack *stackPointer,
					 sf::RenderWindow *window,
					 GraphicSettings *settings,
					 GameController *gameController)
	: State(stackPointer, window, settings, gameController)
{
	// this->addTestValuesToBoard();
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->initBoardButtons();
	this->initShapesAndTexts();
	this->actionChosen = false;
	this->setActionsLeft(ACTIONS_PER_TURN);
	this->setCurrentPlayer(Player::First);
}

GameState::~GameState()
{
}

Player GameState::getCurrentPlayer()
{
	return this->currentPlayer;
}

unsigned int GameState::getActionsLeft()
{
	return this->actionsLeft;
}

void GameState::setCurrentPlayer(Player player)
{
	this->currentPlayer = player;
}

void GameState::setActionsLeft(unsigned int actionsLeft)
{
	this->actionsLeft = actionsLeft;
}

// Dodać skip turn
void GameState::changeTurn()
{
	setActionsLeft(ACTIONS_PER_TURN);
	if (getCurrentPlayer() == Player::First)
	{
		setCurrentPlayer(Player::Second);
		unfreezeHeores(Player::First);
	}
	else
	{
		setCurrentPlayer(Player::First);
		unfreezeHeores(Player::Second);
	}
	resetLoads();
}

void GameState::unfreezeHeores(Player player)
{
	auto frozenHeroes = gameController->frozenHeroes;
	gameController->frozenHeroes.erase(
		std::remove_if(
			gameController->frozenHeroes.begin(),
			gameController->frozenHeroes.end(),
			[player](std::shared_ptr<Hero> const &h)
			{
				h->sprite.setColor(sf::Color(255, 255, 255));
				return h->getOwner() == player;
			}),
		gameController->frozenHeroes.end());
}

void GameState::updateFrozenHeroes()
{
	for (auto frozenHero : gameController->frozenHeroes)
	{
		frozenHero->sprite.setColor((sf::Color(17, 182, 244)));
	}
}

void GameState::resetLoads()
{
	for (auto field : gameController->getBoard()->getFieldsWithHeroes())
	{
		auto hero = field->getHero();
		HeroType type = hero.value()->getType();
		if (type == ENinja || type == ECatapult || type == ETrebuchet)
		{
			hero.value()->setLoads(LOADS_NUMBER);
		}
	}
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
	hero->sprite.setPosition(buttonX + 10, buttonY);
	hero->sprite.setScale(0.9, 0.9);
	switch (hero->getType())
	{
	case HeroType::EKnight:
		hero->sprite.setTexture(textures["KNIGHT"]);
		break;
	case HeroType::EArcher:
		hero->sprite.setTexture(textures["ARCHER"]);
		break;
	case HeroType::EMage:
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
	auto textureSize = hero->sprite.getTexture()->getSize().x;
	if (hero->getOwner() == Player::First)
	{
		hero->sprite.setScale((xGrid * 5) / textureSize, (yGrid * 80 / 9) / textureSize);
	}
	else
	{
		hero->sprite.setScale(-(xGrid * 5) / textureSize, (yGrid * 80 / 9) / textureSize);
		hero->sprite.move(xGrid * 5, 0);
	}

	window->draw(hero->sprite);
	std::shared_ptr<HPBar> hPBar = std::make_shared<HPBar>(buttonX, buttonY + 90, 100, 10, std::make_shared<sf::Font>(this->font), hero->getMaxHealth());
	this->HPBars[hero] = hPBar;

	HeroType type = hero->getType();
	if (type == ENinja || type == ECatapult || type == ETrebuchet)
	{
		Loads heroLoads(buttonX, buttonY + 50, xGrid * 0.25, sf::Color(210, 3, 6));
		loads[hero] = std::make_shared<Loads>(heroLoads);
	}
}

void GameState::showActionMenu(std::shared_ptr<Button> button)
{
	int buttonId = button->getId();
	auto field = gameController->getBoard()->getFieldByCoordinate(buttonId / BOARD_COLUMNS, buttonId % BOARD_COLUMNS);
	bool isHeroFrozen = false;
	for (auto frozenHero : gameController->frozenHeroes)
	{
		if (field->getHero() != std::nullopt && field->getHero().value() == frozenHero)
		{
			isHeroFrozen = true;
			break;
		}
	}
	if (field->getHero() != std::nullopt && field->getHero().value()->getOwner() == this->getCurrentPlayer() && !isHeroFrozen)
	{
		sf::Texture *actionMenuTX;
		sf::Vector2f actionMenuSize;
		ActionNumber actionNumber;
		switch (field->getHero().value()->getType())
		{
		case EMedic:
			actionMenuTX = &textures["ACTION_MENU_3"];
			actionMenuSize = THREE_ACTION_SIZE;
			actionNumber = ActionNumber::three;
			break;
		case ETrebuchet:
		case ECatapult:
			actionMenuTX = &textures["ACTION_MENU_1"];
			actionMenuSize = ONE_ACTION_SIZE;
			actionNumber = ActionNumber::one;
			break;
		default:
			actionMenuTX = &textures["ACTION_MENU_2"];
			actionMenuSize = TWO_ACTION_SIZE;
			actionNumber = ActionNumber::two;
			break;
		}
		auto butPos = button->getRect().getPosition();
		float coorX = butPos.x + ((FIELD_SIZE - actionMenuSize.x) / 2);
		float coorY = butPos.y - actionMenuTX->getSize().y / 2;

		auto actionPtr = std::make_shared<ActionMenu>(sf::Vector2f(coorX, coorY), actionMenuSize, *actionMenuTX, button, field, actionNumber);
		this->actionMenu = std::make_optional<std::shared_ptr<ActionMenu>>(actionPtr);
	}
}

void GameState::update()
{
	checkIfGameEnded();
	this->updateMousePosition();
	if (this->actionMenu != std::nullopt)
	{
		this->updateActionMenu();
	}
	if (this->actionMenu == std::nullopt || this->actionChosen)
	{
		this->updateButtons();
	}
	if (this->actionMenu != std::nullopt)
	{
		this->checkIfActionHasToBeDone();
	}
	if (this->getActionsLeft() == 0)
	{
		this->changeTurn();
	}
	updateFrozenHeroes();
	updateHPBars();
	updateTexts();
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
			if (!this->actionChosen)
			{
				showActionMenu(it.second);
			}
			else
			{
				int buttonId = it.second->getId();
				auto field = gameController->getBoard()->getFieldByCoordinate(buttonId / BOARD_COLUMNS, buttonId % BOARD_COLUMNS);
				this->chosenField = std::make_optional<std::shared_ptr<Field>>(field);
				this->chosenButton = it.second;
			}
		}
	}
	if (this->buttons["EXIT"]->isClicked())
	{
		this->gameController->resetController();
		this->endState();
	}
}

void GameState::updateActionMenu()
{
	this->actionMenu.value()->update(this->mousePos);
}

void GameState::updateHeroPosition(std::shared_ptr<Hero> hero, std::shared_ptr<Button> newButton)
{
	hero->sprite.setPosition(newButton->getRect().getPosition());
	if (hero->getOwner() == Player::First)
	{
		newButton->setTexture(textures["FIELD_GREEN"]);
	}
	else
	{
		newButton->setTexture(textures["FIELD_RED"]);
		hero->sprite.move(xGrid * 5, 0);
	}
	actionMenu.value()->getParentButton()->setTexture(textures["FIELD"]);
	sf::Vector2f newHPBarPos = sf::Vector2f(newButton->getRect().getPosition().x, newButton->getRect().getPosition().y + 90);
	HPBars[hero]->changePosition(newHPBarPos);

	loads[hero]->changePosition(newButton->getRect().getPosition().x, newButton->getRect().getPosition().y + 50);
}

void GameState::checkIfActionHasToBeDone()
{
	if (this->actionMenu.value()->isAttackClicked())
	{
		this->actionChosen = true;
		if (this->chosenField != std::nullopt)
		{
			bool actionResult = this->gameController->attackAction(this->actionMenu.value()->getField(), this->chosenField.value());
			if (actionResult)
			{
				this->setActionsLeft(this->getActionsLeft() - 1);
				this->actionMenu = std::nullopt;
				this->chosenField = std::nullopt;
				this->chosenButton = std::nullopt;
				this->actionChosen = false;
				// gameOutput();
			}
			else
			{
				this->chosenField = std::nullopt;
			}
		}
	}
	else if (this->actionMenu.value()->isMoveClicked())
	{
		this->actionChosen = true;
		if (this->chosenField != std::nullopt)
		{
			bool actionResult = this->gameController->moveAction(this->actionMenu.value()->getField(), this->chosenField.value());
			if (actionResult)
			{
				auto hero = this->chosenField.value()->getHero().value();
				this->setActionsLeft(this->getActionsLeft() - 1);
				updateHeroPosition(hero, this->chosenButton.value());
				this->actionMenu = std::nullopt;
				this->chosenField = std::nullopt;
				this->chosenButton = std::nullopt;
				this->actionChosen = false;
				// gameOutput();
			}
			else
			{
				this->chosenField = std::nullopt;
			}
		}
	}
	else if (this->actionMenu.value()->isHealClicked())
	{
		this->actionChosen = true;
		if (this->chosenField != std::nullopt)
		{
			bool actionResult = this->gameController->healAction(this->actionMenu.value()->getField(), this->chosenField.value());
			if (actionResult)
			{
				this->setActionsLeft(this->getActionsLeft() - 1);
				this->actionMenu = std::nullopt;
				this->chosenField = std::nullopt;
				this->chosenButton = std::nullopt;
				this->actionChosen = false;
				// gameOutput();
			}
			else
			{
				this->chosenField = std::nullopt;
			}
		}
	}
}

bool GameState::checkIfGameEnded()
{
	auto fieldsWithHeroes = this->gameController->getBoard()->getFieldsWithHeroes();
	bool firstPlayerHasHeroes = false;
	bool secondPlayerHasHeroes = false;

	for (auto field : fieldsWithHeroes)
	{
		if (field->getHero().value()->getOwner() == Player::First)
		{
			firstPlayerHasHeroes = true;
		}
		else
		{
			secondPlayerHasHeroes = true;
		}
	}

	if (!firstPlayerHasHeroes)
	{
		this->texts["WINNER"]->setString("Winner is Player: 2");
		return true;
	}
	else if (!secondPlayerHasHeroes)
	{
		this->texts["WINNER"]->setString("Winner is Player: 1");
		return true;
	}
	return false;
}

void GameState::updateHPBars()
{
	for (auto &it : this->HPBars)
	{
		it.second->update(it.first->getCurrentHealth());
	}
}

void GameState::updateLoads()
{
	for (auto &it : this->loads)
	{
		it.second->update(it.first->getLoads());
	}
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
				if (field->getHero().value()->isAlive())
				{
					window->draw(field->getHero().value()->sprite);
				}
				else
				{
					HPBars.erase(field->getHero().value());
					boardButtons.at(board->findFieldCoordinates(field))->setTexture(textures["FIELD"]);
					field->removeHero();
				}
			}
		}
	}
}

void GameState::renderActionMenu()
{
	if (this->actionMenu != std::nullopt)
	{
		if (this->actionMenu.value()->shouldBeClosed())
		{
			this->actionMenu = std::nullopt;
			this->chosenField = std::nullopt;
			this->chosenButton = std::nullopt;
			this->actionChosen = false;
		}
		else
		{
			this->actionMenu.value()->render(*this->window);
		}
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

void GameState::renderHPBars()
{
	for (auto &it : this->HPBars)
	{
		it.second->render(*this->window);
	}
}

void GameState::renderLoads()
{
	for (auto &it : this->loads)
	{
		it.second->render(*this->window);
	}
}

void GameState::updateTexts()
{
	std::stringstream ss;
	ss << "Current Player: " << getCurrentPlayer() + 1 << "\nActions left: " << getActionsLeft();
	this->texts["ACTION_INFO"]->setString(ss.str());
}

void GameState::initShapesAndTexts()
{
	this->texts["ACTION_INFO"] = std::make_shared<sf::Text>("", this->font, (int)(yGrid * 2.3));
	this->texts["ACTION_INFO"]->setPosition(xGrid * 45, yGrid * 10);
	this->texts["ACTION_INFO"]->setFillColor(sf::Color::Black);
	this->texts["ACTION_INFO"]->setStyle(sf::Text::Bold);

	this->texts["WINNER"] = std::make_shared<sf::Text>("", this->font, (int)(yGrid * 2.3));
	this->texts["WINNER"]->setPosition(xGrid * 45, yGrid * 15);
	this->texts["WINNER"]->setFillColor(sf::Color::Black);
	this->texts["WINNER"]->setStyle(sf::Text::Bold);

	this->shapes["TOP"] = std::make_shared<sf::RectangleShape>();
	this->shapes["TOP"]->setFillColor(sf::Color(214, 154, 58));
	this->shapes["TOP"]->setSize(sf::Vector2f{xGrid * 10, yGrid * 10});
	this->shapes["TOP"]->setPosition(xGrid * 45, yGrid * 10);
}

void GameState::renderShapesAndTexts()
{
	for (auto &it : this->shapes)
	{
		this->window->draw(*it.second);
	}

	for (auto &it : this->texts)
	{
		this->window->draw(*it.second);
	}
}

void GameState::render()
{
	this->window->draw(this->backgroundRect);
	this->renderShapesAndTexts();
	this->renderButtons();
	this->renderHeroes();
	this->renderHPBars();
	this->renderLoads();
	this->renderActionMenu();
}

void GameState::gameOutput()
{
	std::cout << "Game Output" << std::endl;
	for (auto field : this->gameController->getBoard()->getFieldsWithHeroes())
	{
		auto hero = field->getHero().value();
		std::cout << hero->getType() << " " << hero->getCurrentHealth() << "/" << hero->getMaxHealth() << std::endl;
	}
	std::cout << "Actions left: " << this->getActionsLeft() << std::endl;
	std::cout << "---------------------------------" << std::endl;
}