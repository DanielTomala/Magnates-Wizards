#include "../../../headers/ui/states/game_state.hpp"

#include <iostream>
GameState::GameState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings)
	: State(stackPointer, window, settings)
{
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->resetGui();
}

void GameState::initTextures(){
	if (!this->backgroundTX.loadFromFile("textures/knight.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["START_BUTTON"].loadFromFile("textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["EXIT_BUTTON"].loadFromFile("textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}


void GameState::initFonts()
{
	if (!this->font.loadFromFile("src/states/Dosis-Light.ttf"))
	{
		throw("ERROR::GameSTATE::COULD NOT LOAD FONT");
	}

}

void GameState::initGui(){
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

void GameState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

GameState::~GameState(){

}

void GameState::updateButtons(){
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons["EXIT"]->isClicked()){
		this->endState();
	}

}

void GameState::update(){
	this->updateMousePosition();
	this->updateButtons();
}

void GameState::renderButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}
}

void GameState::render(){
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}

