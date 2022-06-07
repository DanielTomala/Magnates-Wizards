#include "../../../headers/ui/states/main_menu_state.hpp"

MainMenuState::MainMenuState(StatesStack *stackPointer,
							 sf::RenderWindow *window,
							 GraphicSettings *settings,
							 GameController *gameController)
	: State(stackPointer, window, settings, gameController)
{

	this->initTextures();

	this->initFonts();

	this->initGui();
}

void MainMenuState::initTextures()
{
	if (!this->backgroundTX.loadFromFile("../textures/backgrounds/main_menu.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["BUTTON"].loadFromFile("../textures/button.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("../Dosis-Light.ttf"))
	{
		throw("ERROR::MainMenuSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initGui()
{
	const sf::VideoMode &vm = this->settings->resolution;

	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.width,
			(float)vm.height));

	this->backgroundRect.setTexture(&this->backgroundTX);

	this->buttons["NEW_GAME"] = std::make_shared<Button>(
		xGrid * 38, yGrid * 32, xGrid * 24, yGrid * 16, std::make_shared<sf::Font>(this->font), "NEW GAME", 50,
		textures["BUTTON"], sf::Color(214, 154, 58), sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);

	this->buttons["EXIT"] = std::make_shared<Button>(
		xGrid * 38, yGrid * 52, xGrid * 24, yGrid * 16, std::make_shared<sf::Font>(this->font), "EXIT", 50,
		textures["BUTTON"], sf::Color(214, 154, 58), sf::Color(233, 150, 123), sf::Color(200, 30, 19), 1);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	if (this->buttons["NEW_GAME"]->isClicked())
	{
		this->states->push(std::make_shared<CreateHeroesState>(this->states,
												 this->window,
												 this->settings,
												 this->gameController));
	}

	if (this->buttons["EXIT"]->isClicked())
	{
		this->endState();
	}
}

void MainMenuState::update()
{
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

void MainMenuState::render()
{
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}
