#include "../../headers/states/create_heroes_state.hpp"


#include <iostream>
CreateHeroesState::CreateHeroesState(std::shared_ptr<StateData> state_data)
	: State(state_data)
{	
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->resetGui();
}

void CreateHeroesState::initTextures(){
	if (!this->backgroundTX.loadFromFile("textures/background.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["START_BUTTON"].loadFromFile("textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["EXIT_BUTTON"].loadFromFile("textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}


void CreateHeroesState::initFonts()
{
	if (!this->font.loadFromFile("src/states/Dosis-Light.ttf"))
	{
		throw("ERROR::CreateHeroesSTATE::COULD NOT LOAD FONT");
	}
	
}

void CreateHeroesState::initGui(){
	const sf::VideoMode& vm = this->stateData->settings->resolution;

	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.width,
			(float)vm.height)
	);
	

	this->backgroundRect.setTexture(&this->backgroundTX);
	
	float buttonWidth = 200, buttonHeight = 100;
	float topLeft_x = (vm.width - buttonWidth) / 2;
	float topLeft_y = 200;

	topLeft_y += 2*buttonHeight;

	this->buttons["EXIT"] = std::make_shared<Button>(
		topLeft_x, topLeft_y, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "EXIT", 30,
		textures["EXIT_BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);

}

void CreateHeroesState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

CreateHeroesState::~CreateHeroesState(){

}

void CreateHeroesState::updateButtons(){
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons["EXIT"]->isClicked()){
		this->endState();
	}

}

void CreateHeroesState::update(){
	this->updateMousePosition();
	this->updateButtons();
}

void CreateHeroesState::renderButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}	
}

void CreateHeroesState::render(){
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}
