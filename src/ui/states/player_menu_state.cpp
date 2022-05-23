#include "../../../headers/ui/states/player_menu_state.hpp"

#include <iostream>
PlayerMenuState::PlayerMenuState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings)
	: State(stackPointer, window, settings)
{
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->resetGui();
}

void PlayerMenuState::initTextures(){
	if (!this->backgroundTX.loadFromFile("textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["START_BUTTON"].loadFromFile("textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["EXIT_BUTTON"].loadFromFile("textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}


void PlayerMenuState::initFonts()
{
	if (!this->font.loadFromFile("src/states/Dosis-Light.ttf"))
	{
		throw("ERROR::PlayerMenuSTATE::COULD NOT LOAD FONT");
	}

}

void PlayerMenuState::initGui(){
	const sf::VideoMode& vm = this->settings->resolution;

	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.width,
			(float)vm.height)
	);


	this->backgroundRect.setTexture(&this->backgroundTX);

	float buttonWidth = 200, buttonHeight = 100;
	//float topLeft_x = (vm.width - buttonWidth) / 2;
	//float topLeft_y = 200;

	//topLeft_y += 2*buttonHeight;

	this->buttons["EXIT"] = std::make_shared<Button>(
		0, 0, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "EXIT", 30,
		textures["EXIT_BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);

}

void PlayerMenuState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

PlayerMenuState::~PlayerMenuState(){

}

void PlayerMenuState::updateButtons(){
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons["EXIT"]->isClicked()){
		this->endState();
	}

}

void PlayerMenuState::update(){
	this->updateMousePosition();
	this->updateButtons();
}

void PlayerMenuState::renderButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}
}

void PlayerMenuState::render(){
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}
