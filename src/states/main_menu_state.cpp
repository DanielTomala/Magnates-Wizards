#include "../../headers/states/main_menu_state.hpp"
#include <iostream>
MainMenuState::MainMenuState(std::shared_ptr<StateData> state_data)
	: State(state_data)
{	
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->resetGui();
}

void MainMenuState::initTextures(){
	if (!this->backgroundTX.loadFromFile("textures/background.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["START_BUTTON"].loadFromFile("textures/knight.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
}


void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("src/states/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
	
}

void MainMenuState::initGui(){
	const sf::VideoMode& vm = this->stateData->settings->resolution;

	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.width,
			(float)vm.height)
	);
	

	this->backgroundRect.setTexture(&this->backgroundTX);
	
	this->buttons["PLAY"] = std::make_shared<Button>(
		400.f, 200.f, 200.f, 100.f, std::make_shared<sf::Font>(this->font), "New Game", 30,
		textures["START_BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);
}

void MainMenuState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

MainMenuState::~MainMenuState(){

}

void MainMenuState::updateButtons(){
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons["PLAY"]->isClicked()){
		this->endState();
	}

}

void MainMenuState::update(){
	this->updateMousePosition();
	this->updateButtons();
}

void MainMenuState::renderButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}	
}

void MainMenuState::render(){
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}
