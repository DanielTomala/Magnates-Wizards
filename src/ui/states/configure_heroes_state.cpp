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
		for(auto &it: firstPlayerHeroes){
			auto newHero = this->createHero(it);
			newHero->setOwner(First);
			this->firstPlayerHeroes.push_back(std::move(newHero));
		}
		for(auto &it: secondPlayerHeroes){
			auto newHero = this->createHero(it);
			newHero->setOwner(Second);
			this->secondPlayerHeroes.push_back(std::move(newHero));
		}
	}

std::shared_ptr<Hero> ConfigureHeroesState::createHero(HeroType heroType){
	switch(heroType){
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

void ConfigureHeroesState::initTextures(){
	if (!this->backgroundTX.loadFromFile("../textures/backgrounds/battleback1.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["BUTTON"].loadFromFile("../textures/button.png")){
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
	if (!this->textures["ARCHER"].loadFromFile("../textures/archer.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["KNIGHT"].loadFromFile("../textures/knight.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["WIZARD"].loadFromFile("../textures/wizard.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ICE_DRUID"].loadFromFile("../textures/ice_druid.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["CATAPULT"].loadFromFile("../textures/catapult.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["MEDIC"].loadFromFile("../textures/medic.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["NINJA"].loadFromFile("../textures/ninja.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["TREBUCHET"].loadFromFile("../textures/trebuchet.png")){
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

void ConfigureHeroesState::initGui(){
	const sf::Vector2u vm = this->window->getSize();
	std::cout<<vm.x<<" "<<vm.y<<"\n";
	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.x,
			(float)vm.y)
	);

	this->backgroundRect.setTexture(&this->backgroundTX);

	this->texts["PLAYER_1"] = std::make_shared<sf::Text>("PLAYER 1", this->font, 30);
	this->texts["PLAYER_1"] -> setPosition(130.f, 100.f);
	this->texts["PLAYER_1"] -> setFillColor(sf::Color::Black);
	this->texts["PLAYER_1"] -> setStyle(sf::Text::Bold);

	this->texts["PLAYER_2"] = std::make_shared<sf::Text>("PLAYER 2", this->font, 30);
	this->texts["PLAYER_2"] -> setPosition(vm.x - 230.f, 100.f);
	this->texts["PLAYER_2"] -> setFillColor(sf::Color::Black);
	this->texts["PLAYER_2"] -> setStyle(sf::Text::Bold);

	sf::Vector2f position{125.f, 150.f}; 
	for(auto &it: this->firstPlayerHeroes){
		this->heroButtons[{it->getType(), First}] = std::make_shared<Button>(position.x, position.y, 100.f, 100.f,
																			std::make_shared<sf::Font>(this->font), "", 0,
																			this->textures[heroTypeToString(it->getType())], sf::Color::White,
																			sf::Color::Green, sf::Color::Yellow, 1);
	position.y += 150;
	}

	position = {vm.x-225.f, 150.f};

	for(auto &it: this->secondPlayerHeroes){
		this->heroButtons[{it->getType(), Second}] = std::make_shared<Button>(position.x, position.y, 100.f, 100.f,
																			std::make_shared<sf::Font>(this->font), "", 0,
																			this->textures[heroTypeToString(it->getType())], sf::Color::White,
																			sf::Color::Green, sf::Color::Yellow, 1);
	position.y += 150;
	}

	this->shapes["LEFT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["LEFT_BG"] -> setFillColor(sf::Color(214, 154, 58));
	this->shapes["LEFT_BG"] -> setSize(sf::Vector2f{300.f, 650.f});
	this->shapes["LEFT_BG"] -> setPosition(sf::Vector2f{25.f, 75.f});

	this->shapes["RIGHT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["RIGHT_BG"] -> setFillColor(sf::Color(214, 154, 58));
	this->shapes["RIGHT_BG"] -> setSize(sf::Vector2f{300.f, 650.f});
	this->shapes["RIGHT_BG"] -> setPosition(sf::Vector2f{vm.x-325.f, 75.f});

	this->shapes["MIDDLE_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["MIDDLE_BG"] -> setFillColor(sf::Color(214, 154, 58));
	this->shapes["MIDDLE_BG"] -> setSize(sf::Vector2f{vm.x - 700.f, 300.f});
	this->shapes["MIDDLE_BG"] -> setPosition(sf::Vector2f{350.f, 75.f});

	float buttonWidth = 100, buttonHeight = 50;
	float topLeft_x = vm.x - buttonWidth;
	float topLeft_y = 0.f;

	this->buttons["EXIT"] = std::make_shared<Button>(
		topLeft_x, topLeft_y, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "BACK", 30,
		textures["BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);

	this->buttons["START"] = std::make_shared<Button>(
		topLeft_x, vm.y-buttonHeight, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "START", 30,
		textures["BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);
}

void ConfigureHeroesState::initBoard()
{
	auto board = this->gameController->getBoard();
	for (unsigned int row = 0; row < BOARD_ROWS; row++)
	{
		int boardLeftTopX = (this->settings->resolution.width / 2) - 250;
		int boardLeftTopY = 425;

		for (unsigned int column = 0; column < BOARD_COLUMNS; column++)
		{
			auto field = board->getFieldByCoordinate(row, column);
			int buttonX = boardLeftTopX + FIELD_SIZE/2 * column;
			int buttonY = boardLeftTopY + FIELD_SIZE/2 * row;
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

			this->boardButtons[std::make_tuple(row, column)] = std::make_shared<Button>(buttonX, buttonY, 50, 50, std::make_shared<sf::Font>(this->font),
																						"", 0, fieldTX,
																						sf::Color::White, sf::Color::Green, sf::Color::Yellow, buttonId);
		}
	}
}

void ConfigureHeroesState::showHero(std::shared_ptr<Hero> hero, int buttonX, int buttonY)
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
		hero->sprite.setTextureRect(sf::IntRect(FIELD_SIZE/2, 0, -FIELD_SIZE/2, FIELD_SIZE/2)); // Symetria względem osi OY
	}
	window->draw(hero->sprite);
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

void ConfigureHeroesState::updateButtons(){
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	for (auto &it : this->heroButtons)
	{
		it.second->update(this->mousePos);
	}
		for (auto &it : this->boardButtons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons["EXIT"]->isClicked()){
		this->endState();
	}
   	if (this->buttons["START"]->isClicked()){
		// this->gameController->getBoard()->getFieldByCoordinate(0,0)->addHero(firstPlayerHeroes[0]);
		// this->gameController->getBoard()->getFieldByCoordinate(1,0)->addHero(firstPlayerHeroes[1]);
		// this->gameController->getBoard()->getFieldByCoordinate(2,0)->addHero(firstPlayerHeroes[2]);
		// this->gameController->getBoard()->getFieldByCoordinate(3,0)->addHero(firstPlayerHeroes[3]);

		// this->gameController->getBoard()->getFieldByCoordinate(0,9)->addHero(secondPlayerHeroes[0]);
		// this->gameController->getBoard()->getFieldByCoordinate(1,9)->addHero(secondPlayerHeroes[1]);
		// this->gameController->getBoard()->getFieldByCoordinate(2,9)->addHero(secondPlayerHeroes[2]);
		// this->gameController->getBoard()->getFieldByCoordinate(3,9)->addHero(secondPlayerHeroes[3]);
    	this->states->pop();
		this->states->push(new GameState(this->states,
                                         this->window,
                                         this->settings,
										 this->gameController));
		this->endState();
    }

}

void ConfigureHeroesState::update(){
	this->updateMousePosition();
	this->updateButtons();
}

void ConfigureHeroesState::renderButtons()
{
	for (auto &it : this->shapes)
	{
		this->window->draw(*it.second);
	}	

	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}

	for (auto &it : this->heroButtons)
	{
		it.second->render(*this->window);
	}	

	for (auto &it : this->texts)
	{
		this->window->draw(*it.second);
	}
	for (auto &it : this->boardButtons)
	{
		it.second->render(*this->window);
	}
}

std::string ConfigureHeroesState::heroTypeToString(HeroType herotype){
	switch(herotype){
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



void ConfigureHeroesState::render(){
	this->window->draw(this->backgroundRect);
	this->renderHeroes();
	this->renderButtons();
}