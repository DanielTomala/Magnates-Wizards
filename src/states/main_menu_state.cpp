#include "../../headers/states/main_menu_state.hpp"
#include <iostream>
MainMenuState::MainMenuState(std::shared_ptr<StateData> state_data)
	: State(state_data)
{
	this->initFonts();
	this->initGui();
	this->resetGui();
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
	
	if (!this->backgroundTX.loadFromFile("textures/background.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->backgroundRect.setTexture(&this->backgroundTX);
}

void MainMenuState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

MainMenuState::~MainMenuState(){

}

void MainMenuState::updateButtons(){

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
