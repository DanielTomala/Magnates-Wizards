#include "../../../headers/ui/states/configure_heroes_state.hpp"

#include <iostream>
ConfigureHeroesState::ConfigureHeroesState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings,
					  GameController *gameController)
	: State(stackPointer, window, settings, gameController)
{	
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->resetGui();
}

ConfigureHeroesState::~ConfigureHeroesState(){

}

void ConfigureHeroesState::initTextures(){
	if (!this->backgroundTX.loadFromFile("../textures/backgrounds/battleback1.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	if (!this->textures["BUTTON"].loadFromFile("../textures/button.png")){
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

// std::string ConfigureHeroesState::heroTypeToString(HeroType herotype){
// 	switch(herotype){
// 		case EWizard:
// 			return "WIZARD";
// 		case EKnight:
// 			return "KNIGHT";
// 		case EArcher:
// 			return "ARCHER";
// 		case EMedic:
// 			return "MEDIC";
// 		case EIceDruid:
// 			return "ICE_DRUID";
// 		case ETrebuchet:
// 			return "TREBUCHET";
// 		case ECatapult:
// 			return "CATAPULT";
// 		case ENinja:
// 			return "NINJA";
// 		default:
// 			return "HERO";
// 	}
// }

void ConfigureHeroesState::initGui(){
	const sf::Vector2u vm = this->window->getSize();
	std::cout<<vm.x<<" "<<vm.y<<"\n";
	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.x,
			(float)vm.y)
	);

	this->backgroundRect.setTexture(&this->backgroundTX);

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
	this->shapes["MIDDLE_BG"] -> setSize(sf::Vector2f{vm.x- 700.f, 650.f});
	this->shapes["MIDDLE_BG"] -> setPosition(sf::Vector2f{350.f, 75.f});

	float buttonWidth = 100, buttonHeight = 50;
	float topLeft_x = vm.x - buttonWidth;
	float topLeft_y = 0.f;

	this->buttons["EXIT"] = std::make_shared<Button>(
		topLeft_x, topLeft_y, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "BACK", 30,
		textures["BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);

	this->buttons["START"] = std::make_shared<Button>(
		topLeft_x, vm.y-2*buttonHeight, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "START", 30,
		textures["BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);
}

void ConfigureHeroesState::updateButtons(){
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons["EXIT"]->isClicked()){
		this->endState();
	}
   	if (this->buttons["START"]->isClicked()){
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

	for (auto &it : this->texts)
	{
		this->window->draw(*it.second);
	}
}

void ConfigureHeroesState::render(){
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}