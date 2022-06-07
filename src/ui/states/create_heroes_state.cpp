#include "../../../headers/ui/states/create_heroes_state.hpp"

CreateHeroesState::CreateHeroesState(StatesStack *stackPointer,
									 sf::RenderWindow *window,
									 GraphicSettings *settings,
									 GameController *gameController)
	: State(stackPointer, window, settings, gameController)
{
	this->heroesDescriptions = Descriptions();
	this->initTextures();
	this->initFonts();
	this->initGui();
}

void CreateHeroesState::initTextures()
{
	if (!this->backgroundTX.loadFromFile("../textures/backgrounds/battleback1.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["BUTTON"].loadFromFile("../textures/button.png"))
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

void CreateHeroesState::initFonts()
{
	if (!this->font.loadFromFile("../Dosis-Light.ttf"))
	{
		throw("ERROR::ConfigureHeroesSTATE::COULD NOT LOAD FONT");
	}
}

void CreateHeroesState::initGui()
{
	const sf::Vector2u vm = this->window->getSize();

	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.x,
			(float)vm.y));

	this->backgroundRect.setTexture(&this->backgroundTX);

	this->texts["HERO_DESCRIPTION"] = std::make_shared<sf::Text>("", this->font, (int)(yGrid * 2.3));
	this->texts["HERO_DESCRIPTION"]->setPosition(xGrid * 29, yGrid * 9);
	this->texts["HERO_DESCRIPTION"]->setFillColor(sf::Color::Black);
	this->texts["HERO_DESCRIPTION"]->setStyle(sf::Text::Bold);

	this->texts["MANUAL"] = std::make_shared<sf::Text>(this->heroesDescriptions.getManual(), this->font, (int)(yGrid * 2.3));
	this->texts["MANUAL"]->setPosition(xGrid * 53, yGrid * 9);
	this->texts["MANUAL"]->setFillColor(sf::Color::Black);
	this->texts["MANUAL"]->setStyle(sf::Text::Bold);

	this->texts["PLAYER_1"] = std::make_shared<sf::Text>("PLAYER 1", this->font, (int)(yGrid * 4));
	this->texts["PLAYER_1"]->setPosition(xGrid * 10, yGrid * 11);
	this->texts["PLAYER_1"]->setFillColor(sf::Color::Black);
	this->texts["PLAYER_1"]->setStyle(sf::Text::Bold);

	this->texts["PLAYER_2"] = std::make_shared<sf::Text>("PLAYER 2", this->font, (int)(yGrid * 4));
	this->texts["PLAYER_2"]->setPosition(xGrid * 82, yGrid * 11);
	this->texts["PLAYER_2"]->setFillColor(sf::Color::Black);
	this->texts["PLAYER_2"]->setStyle(sf::Text::Bold);

	this->shapes["LEFT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["LEFT_BG"]->setFillColor(sf::Color(214, 154, 58));
	this->shapes["LEFT_BG"]->setSize(sf::Vector2f{xGrid * 20, yGrid * 84});
	this->shapes["LEFT_BG"]->setPosition(xGrid * 4, yGrid * 8);

	this->shapes["MIDDLE_LEFT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["MIDDLE_LEFT_BG"]->setFillColor(sf::Color(214, 154, 58));
	this->shapes["MIDDLE_LEFT_BG"]->setSize(sf::Vector2f{xGrid * 20, yGrid * 42});
	this->shapes["MIDDLE_LEFT_BG"]->setPosition(xGrid * 28, yGrid * 8);

	this->shapes["MIDDLE_RIGHT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["MIDDLE_RIGHT_BG"]->setFillColor(sf::Color(214, 154, 58));
	this->shapes["MIDDLE_RIGHT_BG"]->setSize(sf::Vector2f{xGrid * 20, yGrid * 42});
	this->shapes["MIDDLE_RIGHT_BG"]->setPosition(xGrid * 52, yGrid * 8);

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


	this->heroButtons["ARCHER_1"] = std::make_shared<SelectButton>(
		xGrid * 6, yGrid * 18, xGrid * 7, yGrid * 12, textures["ARCHER"], sf::Color::Green, heroesDescriptions.getDescription(EArcher), First, EArcher);

	this->heroButtons["KNIGHT_1"] = std::make_shared<SelectButton>(
		xGrid * 6, yGrid * 35, xGrid * 7, yGrid * 12, textures["KNIGHT"], sf::Color::Green, heroesDescriptions.getDescription(EKnight), First, EKnight);

	this->heroButtons["ICE_DRUID_1"] = std::make_shared<SelectButton>(
		xGrid * 6, yGrid * 52, xGrid * 7, yGrid * 12, textures["ICE_DRUID"], sf::Color::Green, heroesDescriptions.getDescription(EIceDruid), First, EIceDruid);

	this->heroButtons["CATAPULT_1"] = std::make_shared<SelectButton>(
		xGrid * 6, yGrid * 69, xGrid * 7, yGrid * 12, textures["CATAPULT"], sf::Color::Green, heroesDescriptions.getDescription(ECatapult), First, ECatapult);

	this->heroButtons["NINJA_1"] = std::make_shared<SelectButton>(
		xGrid * 15, yGrid * 18, xGrid * 7, yGrid * 12, textures["NINJA"], sf::Color::Green, heroesDescriptions.getDescription(ENinja), First, ENinja);

	this->heroButtons["MEDIC_1"] = std::make_shared<SelectButton>(
		xGrid * 15, yGrid * 35, xGrid * 7, yGrid * 12, textures["MEDIC"], sf::Color::Green, heroesDescriptions.getDescription(EMedic), First, EMedic);

	this->heroButtons["WIZARD_1"] = std::make_shared<SelectButton>(
		xGrid * 15, yGrid * 52, xGrid * 7, yGrid * 12, textures["WIZARD"], sf::Color::Green, heroesDescriptions.getDescription(EMage), First, EMage);

	this->heroButtons["TREBUCHET_1"] = std::make_shared<SelectButton>(
		xGrid * 15, yGrid * 69, xGrid * 7, yGrid * 12, textures["TREBUCHET"], sf::Color::Green, heroesDescriptions.getDescription(ETrebuchet), First, ETrebuchet);

	this->heroButtons["ARCHER_2"] = std::make_shared<SelectButton>(
		xGrid * 78, yGrid * 18, xGrid * 7, yGrid * 12, textures["ARCHER"], sf::Color::Green, heroesDescriptions.getDescription(EArcher), Second, EArcher);

	this->heroButtons["KNIGHT_2"] = std::make_shared<SelectButton>(
		xGrid * 78, yGrid * 35, xGrid * 7, yGrid * 12, textures["KNIGHT"], sf::Color::Green, heroesDescriptions.getDescription(EKnight), Second, EKnight);

	this->heroButtons["ICE_DRUID_2"] = std::make_shared<SelectButton>(
		xGrid * 78, yGrid * 52, xGrid * 7, yGrid * 12, textures["ICE_DRUID"], sf::Color::Green, heroesDescriptions.getDescription(EIceDruid), Second, EIceDruid);

	this->heroButtons["CATAPULT_2"] = std::make_shared<SelectButton>(
		xGrid * 78, yGrid * 69, xGrid * 7, yGrid * 12, textures["CATAPULT"], sf::Color::Green, heroesDescriptions.getDescription(ECatapult), Second, ECatapult);

	this->heroButtons["NINJA_2"] = std::make_shared<SelectButton>(
		xGrid * 87, yGrid * 18, xGrid * 7, yGrid * 12, textures["NINJA"], sf::Color::Green, heroesDescriptions.getDescription(ENinja), Second, ENinja);

	this->heroButtons["MEDIC_2"] = std::make_shared<SelectButton>(
		xGrid * 87, yGrid * 35, xGrid * 7, yGrid * 12, textures["MEDIC"], sf::Color::Green, heroesDescriptions.getDescription(EMedic), Second, EMedic);

	this->heroButtons["WIZARD_2"] = std::make_shared<SelectButton>(
		xGrid * 87, yGrid * 52, xGrid * 7, yGrid * 12, textures["WIZARD"], sf::Color::Green, heroesDescriptions.getDescription(EMage), Second, EMage);

	this->heroButtons["TREBUCHET_2"] = std::make_shared<SelectButton>(
		xGrid * 87, yGrid * 69, xGrid * 7, yGrid * 12, textures["TREBUCHET"], sf::Color::Green, heroesDescriptions.getDescription(ETrebuchet), Second, ETrebuchet);
}

CreateHeroesState::~CreateHeroesState()
{
}

void CreateHeroesState::loadHeroes()
{
	for (auto &it : this->heroButtons)
	{
		if (it.second->isChoosen())
		{
			if (it.second->getPlayer() == First)
			{
				this->firstPlayerHeroes.push_back(it.second->getHeroType());
			}
			if (it.second->getPlayer() == Second)
			{
				this->secondPlayerHeroes.push_back(it.second->getHeroType());
			}
		}
	}
}

void CreateHeroesState::updateButtons()
{
	if (this->buttons.find("ERROR") != this->buttons.end())
	{
		if (this->buttons["ERROR"]->isClicked())
		{
			this->buttons.erase("ERROR");
		}
	}

	if (this->buttons["EXIT"]->isClicked())
	{
		this->endState();
	}

	if (this->buttons["START"]->isClicked())
	{
		this->loadHeroes();
		if (this->firstPlayerHeroes.size() != 4 || this->secondPlayerHeroes.size() != 4)
		{
			this->buttons["ERROR"] = std::make_shared<Button>(
				xGrid * 28, yGrid * 54, xGrid * 20, yGrid * 10, std::make_shared<sf::Font>(this->font), "WRONG HEROES NUMBER", 30,
				textures["BUTTON"], sf::Color(214, 154, 58), sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);
			this->firstPlayerHeroes.clear();
			this->secondPlayerHeroes.clear();
		}
		else
		{
			this->states->push(std::make_shared<ConfigureHeroesState>(this->states,
																	  this->window,
																	  this->settings,
																	  this->gameController,
																	  this->firstPlayerHeroes,
																	  this->secondPlayerHeroes));
			this->firstPlayerHeroes.clear();
			this->secondPlayerHeroes.clear();
		}
	}

	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}
}

void CreateHeroesState::updateHeroButtons()
{
	this->texts["HERO_DESCRIPTION"]->setString("");

	for (auto &it : this->heroButtons)
	{
		it.second->update(this->mousePos);
		if (it.second->isHovered())
		{
			this->texts["HERO_DESCRIPTION"]->setString(this->heroButtons[it.first]->getDescription());
		}
	}
}

void CreateHeroesState::update()
{
	this->updateMousePosition();
	this->updateButtons();
	this->updateHeroButtons();
}

void CreateHeroesState::renderButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}
}

void CreateHeroesState::renderHeroButtons()
{
	for (auto &it : this->heroButtons)
	{
		it.second->render(*this->window);
	}
}

void CreateHeroesState::renderTexts()
{
	for (auto &it : this->texts)
	{
		this->window->draw(*it.second);
	}
}
void CreateHeroesState::renderShapes()
{
	for (auto &it : this->shapes)
	{
		this->window->draw(*it.second);
	}
}
void CreateHeroesState::render()
{
	this->window->draw(this->backgroundRect);
	this->renderShapes();
	this->renderHeroButtons();
	this->renderButtons();
	this->renderTexts();
}
