#include "../../../headers/ui/states/main_menu_state.hpp"
#include <iostream>
MainMenuState::MainMenuState(StatesStack *stackPointer,
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

void MainMenuState::initTextures(){
	if (!this->backgroundTX.loadFromFile("../textures/backgrounds/main_menu.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["START_BUTTON"].loadFromFile("../textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["EXIT_BUTTON"].loadFromFile("../textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}


void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("../src/ui/states/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}

}

void MainMenuState::initGui(){
	const sf::VideoMode& vm = this->settings->resolution;

	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.width,
			(float)vm.height)
	);


	this->backgroundRect.setTexture(&this->backgroundTX);

	float buttonWidth = 200, buttonHeight = 100;
	float topLeft_x = (vm.width - buttonWidth) / 2;
	float topLeft_y = 200;



	this->buttons["NEW_GAME"] = std::make_shared<Button>(
		topLeft_x, topLeft_y, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "NEW GAME", 30,
		textures["START_BUTTON"], sf::Color(214, 154, 58), sf::Color::Magenta, sf::Color::Blue, 1
	);

	topLeft_y += 2*buttonHeight;

	this->buttons["EXIT"] = std::make_shared<Button>(
		topLeft_x, topLeft_y, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "EXIT", 30,
		textures["EXIT_BUTTON"], sf::Color(214, 154, 58), sf::Color::Magenta, sf::Color::Blue, 1
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

	if (this->buttons["NEW_GAME"]->isClicked()){
		this->states->push(new CreateHeroesState(this->states,
                                                      this->window,
                                                      this->settings,
													  this->gameController));
	}

	if (this->buttons["EXIT"]->isClicked()){
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
