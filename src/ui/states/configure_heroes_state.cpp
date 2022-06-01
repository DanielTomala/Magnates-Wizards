#include "../../../headers/ui/states/configure_heroes_state.hpp"

#include <iostream>
ConfigureHeroesState::ConfigureHeroesState(StatesStack *stackPointer,
										   sf::RenderWindow *window,
										   GraphicSettings *settings,
										   GameController *gameController,
										   std::vector<HeroType> firstPlayerHeroes,
										   std::vector<HeroType> secondPlayerHeroes)
	: State(stackPointer, window, settings, gameController)
{
	this->initHeroes(firstPlayerHeroes, secondPlayerHeroes);
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->initBoard();
	this->resetGui();
}

ConfigureHeroesState::~ConfigureHeroesState() {}

void ConfigureHeroesState::initHeroes(std::vector<HeroType> firstPlayerHeroes,
									  std::vector<HeroType> secondPlayerHeroes)
{
	for (auto &it : firstPlayerHeroes)
	{
		auto newHero = this->createHero(it);
		newHero->setOwner(First);
		this->firstPlayerHeroes.push_back(std::move(newHero));
	}
	for (auto &it : secondPlayerHeroes)
	{
		auto newHero = this->createHero(it);
		newHero->setOwner(Second);
		this->secondPlayerHeroes.push_back(std::move(newHero));
	}
}

std::shared_ptr<Hero> ConfigureHeroesState::createHero(HeroType heroType)
{
	switch (heroType)
	{
	case EKnight:
		return std::make_shared<Knight>();
		break;
	case EWizard:
		return std::make_shared<Mage>();
		break;
	case EMedic:
		return std::make_shared<Medic>();
		break;
	case ENinja:
		return std::make_shared<Ninja>();
		break;
	case EIceDruid:
		return std::make_shared<IceDruid>();
		break;
	case EArcher:
		return std::make_shared<Archer>();
		break;
	case ECatapult:
		return std::make_shared<Catapult>();
		break;
	case ETrebuchet:
		return std::make_shared<Trebuchet>();
		break;
	default:
		return std::make_shared<Trebuchet>();
	}
}

void ConfigureHeroesState::initTextures()
{
	if (!this->backgroundTX.loadFromFile("../textures/backgrounds/battleback1.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["BUTTON"].loadFromFile("../textures/button.png"))
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
	if (!this->textures["ARCHER"].loadFromFile("../textures/archer.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["KNIGHT"].loadFromFile("../textures/knight.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["WIZARD"].loadFromFile("../textures/wizard.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ICE_DRUID"].loadFromFile("../textures/ice_druid.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["CATAPULT"].loadFromFile("../textures/catapult.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["MEDIC"].loadFromFile("../textures/medic.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["NINJA"].loadFromFile("../textures/ninja.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["TREBUCHET"].loadFromFile("../textures/trebuchet.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}

void ConfigureHeroesState::initFonts()
{
	if (!this->font.loadFromFile("../src/ui/states/Dosis-Light.ttf"))
	{
		throw("ERROR::CreateHeroesSTATE::COULD NOT LOAD FONT");
	}
}

void ConfigureHeroesState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

void ConfigureHeroesState::initGui()
{
	const sf::Vector2u vm = this->window->getSize();
	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.x,
			(float)vm.y));

	this->backgroundRect.setTexture(&this->backgroundTX);

	this->texts["PLAYER_1"] = std::make_shared<sf::Text>("PLAYER 1", this->font, (int)(yGrid * 4));
	this->texts["PLAYER_1"]->setPosition(xGrid * 10, yGrid * 11);
	this->texts["PLAYER_1"]->setFillColor(sf::Color::Black);
	this->texts["PLAYER_1"]->setStyle(sf::Text::Bold);

	this->texts["PLAYER_2"] = std::make_shared<sf::Text>("PLAYER 2", this->font, (int)(yGrid * 4));
	this->texts["PLAYER_2"]->setPosition(xGrid * 82, yGrid * 11);
	this->texts["PLAYER_2"]->setFillColor(sf::Color::Black);
	this->texts["PLAYER_2"]->setStyle(sf::Text::Bold);

	float position_y = yGrid * 18;

	for (auto &it : this->firstPlayerHeroes)
	{
		this->heroButtons[{it->getType(), First}] = std::make_shared<Button>(xGrid * 10.5, position_y, xGrid * 7, yGrid * 12,
																			 std::make_shared<sf::Font>(this->font), "", 0,
																			 this->textures[heroTypeToString(it->getType())], sf::Color::White,
																			 sf::Color::Green, sf::Color::Yellow, 1);
		position_y += yGrid * 17;
	}

	position_y = yGrid * 18;

	for (auto &it : this->secondPlayerHeroes)
	{
		this->heroButtons[{it->getType(), Second}] = std::make_shared<Button>(xGrid * 82.5, position_y, xGrid * 7, yGrid * 12,
																			  std::make_shared<sf::Font>(this->font), "", 0,
																			  this->textures[heroTypeToString(it->getType())], sf::Color::White,
																			  sf::Color::Green, sf::Color::Yellow, 1);
		position_y += yGrid * 17;
	}

	this->shapes["LEFT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["LEFT_BG"]->setFillColor(sf::Color(214, 154, 58));
	this->shapes["LEFT_BG"]->setSize(sf::Vector2f{xGrid * 20, yGrid * 84});
	this->shapes["LEFT_BG"]->setPosition(xGrid * 4, yGrid * 8);

	this->shapes["RIGHT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["RIGHT_BG"]->setFillColor(sf::Color(214, 154, 58));
	this->shapes["RIGHT_BG"]->setSize(sf::Vector2f{xGrid * 20, yGrid * 84});
	this->shapes["RIGHT_BG"]->setPosition(xGrid * 76, yGrid * 8);

	this->buttons["EXIT"] = std::make_shared<Button>(
		xGrid * 93, yGrid * 0, xGrid * 7, yGrid * 6, std::make_shared<sf::Font>(this->font), "BACK", 30,
		textures["BUTTON"], sf::Color(214, 154, 58), sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);

	this->buttons["START"] = std::make_shared<Button>(
		xGrid * 93, yGrid * 94, xGrid * 7, yGrid * 6, std::make_shared<sf::Font>(this->font), "START", 30,
		textures["BUTTON"], sf::Color(214, 154, 58), sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);
}

void ConfigureHeroesState::initBoard()
{
	auto board = this->gameController->getBoard();
	for (unsigned int row = 0; row < BOARD_ROWS; row++)
	{
		int boardLeftTopX = xGrid * 25;
		int boardLeftTopY = yGrid * 42;

		for (unsigned int column = 0; column < BOARD_COLUMNS; column++)
		{
			auto field = board->getFieldByCoordinate(row, column);
			int buttonX = boardLeftTopX + xGrid * 5 * column;
			int buttonY = boardLeftTopY + yGrid * 80 / 9 * row;
			int buttonId = row * BOARD_COLUMNS + column;

			this->boardButtons[std::make_tuple(row, column)] = std::make_shared<Button>(buttonX, buttonY, xGrid * 5, yGrid * 80 / 9, std::make_shared<sf::Font>(this->font),
																						"", 0, textures["FIELD"],
																						sf::Color::White, sf::Color::Green, sf::Color::Yellow, buttonId);
		}
	}
}

void ConfigureHeroesState::showHero(std::shared_ptr<Hero> hero, int buttonX, int buttonY)
{
	hero->sprite.setPosition(buttonX, buttonY);
	hero->sprite.setScale((xGrid * 5) / 100, (yGrid * 80 / 9) / 100);
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
		hero->sprite.setScale(- (xGrid * 5) / 100, (yGrid * 80 / 9) / 100);
		hero->sprite.move(xGrid * 5, 0);
	}
}

void ConfigureHeroesState::updateButtons()
{

	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons.find("ERROR") != this->buttons.end())
	{
		if (this->buttons["ERROR"]->isClicked())
		{
			this->buttons.erase("ERROR");
		}
	}

	if (this->buttons.find("CLOSE") != this->buttons.end())
	{
		if (this->buttons["CLOSE"]->isClicked())
		{
			this->hideMenu();
			this->choosenHero = std::nullopt;
		}
	}

	if (this->buttons.find("RANGE") != this->buttons.end())
	{
		if (this->buttons["RANGE"]->isClicked())
		{
			this->choosenHero.value()->setPersonalisation(Personalisation::Range);
		}
	}

	if (this->buttons.find("BALANCED") != this->buttons.end())
	{
		if (this->buttons["BALANCED"]->isClicked())
		{
			this->choosenHero.value()->setPersonalisation(Personalisation::Balanced);
		}
	}

	if (this->buttons.find("DAMAGE") != this->buttons.end())
	{
		if (this->buttons["DAMAGE"]->isClicked())
		{
			this->choosenHero.value()->setPersonalisation(Personalisation::Damage);
		}
	}

	if (this->buttons["EXIT"]->isClicked())
	{
		this->gameController->resetController();
		this->endState();
	}
	if (this->buttons["START"]->isClicked())
	{
		unsigned int heroesCounter = 0;
		for (auto &row : gameController->getBoard()->getFields())
		{
			for (auto &field : row)
			{
				if (field->isFree() == false)
				{
					heroesCounter++;

					auto hero = field->getHero().value();
					hero->setAttributes();
					std::cout << hero->getMaxHealth() << '\n';
				}
			}
		}
		if (heroesCounter == 8)
		{
			this->states->pop();
			this->states->push(new GameState(this->states,
											 this->window,
											 this->settings,
											 this->gameController));
			this->endState();
		}
		else
		{
			this->buttons["ERROR"] = std::make_shared<Button>(
				xGrid * 48, yGrid * 28, xGrid * 24, yGrid * 12, std::make_shared<sf::Font>(this->font), "WRONG HEROES NUMBER", 30,
				textures["BUTTON"], sf::Color::Yellow, sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);
		}
	}
}

void ConfigureHeroesState::updateHeroButtons()
{
	for (auto &it : this->heroButtons)
	{
		it.second->update(this->mousePos);
		if (it.second->isClicked())
		{
			for (auto &hero : firstPlayerHeroes)
			{
				if (std::get<0>(it.first) == hero->getType() && std::get<1>(it.first) == hero->getOwner())
				{
					this->choosenHero = hero;
				}
			}
			for (auto &hero : secondPlayerHeroes)
			{
				if (std::get<0>(it.first) == hero->getType() && std::get<1>(it.first) == hero->getOwner())
				{
					this->choosenHero = hero;
					break;
				}
			}
			this->showMenu();
		}
	}
}

void ConfigureHeroesState::updateBoardButtons()
{
	for (auto &it : this->boardButtons)
	{
		int x = std::get<1>(it.first);
		int y = std::get<0>(it.first);
		if (gameController->getBoard()->getFieldByCoordinate(y, x)->isFree())
		{
			it.second->setTexture(textures["FIELD"]);
		}
		if (choosenHero != std::nullopt && choosenHero.value()->getOwner() == Player::First)
		{
			if (x >= 0 && x <= 2)
			{
				it.second->setTexture(textures["FIELD_GREEN"]);
			}
		}
		if (choosenHero != std::nullopt && choosenHero.value()->getOwner() == Player::Second)
		{
			if (x >= 7 && x <= 9)
			{
				it.second->setTexture(textures["FIELD_RED"]);
			}
		}

		if (it.second->isClicked() && choosenHero != std::nullopt)
		{
			this->putHero(choosenHero.value(), std::get<0>(it.first), std::get<1>(it.first));
		}
		it.second->update(this->mousePos);
	}
}

std::string ConfigureHeroesState::heroTypeToString(HeroType herotype)
{
	switch (herotype)
	{
	case EWizard:
		return "WIZARD";
	case EKnight:
		return "KNIGHT";
	case EArcher:
		return "ARCHER";
	case EMedic:
		return "MEDIC";
	case EIceDruid:
		return "ICE_DRUID";
	case ETrebuchet:
		return "TREBUCHET";
	case ECatapult:
		return "CATAPULT";
	case ENinja:
		return "NINJA";
	default:
		return "HERO";
	}
}

void ConfigureHeroesState::showMenu()
{
	this->shapes["MIDDLE_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["MIDDLE_BG"]->setFillColor(sf::Color(214, 154, 58));
	this->shapes["MIDDLE_BG"]->setSize(sf::Vector2f{xGrid * 44, yGrid * 32});
	this->shapes["MIDDLE_BG"]->setPosition(sf::Vector2f{xGrid * 28, yGrid * 8});

	this->shapes["ZCHOOSEN_IMAGE"] = std::make_shared<sf::RectangleShape>(); // Z... will render last
	this->shapes["ZCHOOSEN_IMAGE"]->setPosition(xGrid * 29, yGrid * 13);
	this->shapes["ZCHOOSEN_IMAGE"]->setSize(sf::Vector2f{xGrid * 7, yGrid * 12});
	this->shapes["ZCHOOSEN_IMAGE"]->setTexture(&textures[heroTypeToString(choosenHero.value()->getType())]);

	if (choosenHero.value()->getOwner() == Player::First)
	{
		this->texts["PLAYER"] = std::make_shared<sf::Text>("PLAYER 1", this->font, (int)(yGrid * 2.3));
	}
	else
	{
		this->texts["PLAYER"] = std::make_shared<sf::Text>("PLAYER 2", this->font, (int)(yGrid * 2.3));
	}
	this->texts["PLAYER"]->setPosition(xGrid * 30, yGrid * 10);
	this->texts["PLAYER"]->setFillColor(sf::Color::Black);
	this->texts["PLAYER"]->setStyle(sf::Text::Bold);

	this->buttons["DAMAGE"] = std::make_shared<Button>(
		xGrid * 40, yGrid * 13, xGrid * 7, yGrid * 6, std::make_shared<sf::Font>(this->font), "DAMAGE", (int)(yGrid * 2.3),
		textures["BUTTON"], sf::Color::Yellow, sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);

	this->buttons["BALANCED"] = std::make_shared<Button>(
		xGrid * 47, yGrid * 13, xGrid * 7, yGrid * 6, std::make_shared<sf::Font>(this->font), "BALANCED", (int)(yGrid * 2.3),
		textures["BUTTON"], sf::Color::Yellow, sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);

	this->buttons["RANGE"] = std::make_shared<Button>(
		xGrid * 54, yGrid * 13, xGrid * 7, yGrid * 6, std::make_shared<sf::Font>(this->font), "RANGE", (int)(yGrid * 2.3),
		textures["BUTTON"], sf::Color::Yellow, sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);

	this->buttons["CLOSE"] = std::make_shared<Button>(
		xGrid * 69, yGrid * 8, xGrid * 3, yGrid * 4.5, std::make_shared<sf::Font>(this->font), "X", (int)(yGrid * 2.3),
		textures["BUTTON"], sf::Color::Yellow, sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);
}

void ConfigureHeroesState::hideMenu()
{
	if (this->choosenHero == std::nullopt)
		return;
	this->shapes.erase("MIDDLE_BG");
	this->shapes.erase("ZCHOOSEN_IMAGE");
	this->buttons.erase("DAMAGE");
	this->buttons.erase("BALANCED");
	this->buttons.erase("RANGE");
	this->buttons.erase("CLOSE");
	this->texts.erase("PLAYER");
}

void ConfigureHeroesState::putHero(std::shared_ptr<Hero> hero, int xCoo, int yCoo)
{
	auto field = this->gameController->getBoard()->getFieldByCoordinate(xCoo, yCoo);
	int maxFirst = 2, maxSecond = 7;
	bool inRange = false;
	if (yCoo <= maxFirst && hero->getOwner() == Player::First)
	{
		inRange = true;
	}
	if (yCoo >= maxSecond && hero->getOwner() == Player::Second)
	{
		inRange = true;
	}

	if (inRange)
	{
		for (unsigned int col = 0; col < BOARD_COLUMNS; col++)
		{
			for (unsigned int row = 0; row < BOARD_ROWS; row++)
			{
				auto field = gameController->getBoard()->getFieldByCoordinate(row, col);
				if (field->getHero() == hero)
				{
					field->removeHero();
					boardButtons[std::make_tuple(row, col)]->setTexture(textures["FIELD"]);
				}
			}
		}
		field->addHero(hero);
		if (hero->getOwner() == Player::First)
		{
			boardButtons[std::make_tuple(xCoo, yCoo)]->setTexture(textures["FIELD_GREEN"]);
		}
		if (hero->getOwner() == Player::Second)
		{
			boardButtons[std::make_tuple(xCoo, yCoo)]->setTexture(textures["FIELD_RED"]);
		}
		int xPos = (xGrid * 25) + (yCoo * xGrid * 5);
		int yPos = (yGrid * 42) + (xCoo * yGrid * 80 / 9);
		this->showHero(hero, xPos, yPos);
	}
}

void ConfigureHeroesState::update()
{
	this->updateMousePosition();
	this->updateButtons();
	this->updateHeroButtons();
	this->updateBoardButtons();
}

void ConfigureHeroesState::renderHeroes()
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

void ConfigureHeroesState::renderBackground()
{
	this->window->draw(this->backgroundRect);
}

void ConfigureHeroesState::renderBoardButtons()
{
	for (auto &it : this->boardButtons)
	{
		it.second->render(*this->window);
	}
}

void ConfigureHeroesState::renderHeroButtons()
{
	for (auto &it : this->heroButtons)
	{
		it.second->render(*this->window);
	}
}

void ConfigureHeroesState::renderShapes()
{
	for (auto &it : this->shapes)
	{
		this->window->draw(*it.second);
	}
}

void ConfigureHeroesState::renderTexts()
{
	for (auto &it : this->texts)
	{
		this->window->draw(*it.second);
	}
}

void ConfigureHeroesState::renderButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}
}

void ConfigureHeroesState::render()
{
	this->renderBackground();
	this->renderShapes();
	this->renderHeroButtons();
	this->renderButtons();
	this->renderTexts();
	this->renderBoardButtons();
	this->renderHeroes();
}