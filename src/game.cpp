#include "../headers/game.hpp"
void Game::initVariables()
{
	this->window = NULL;
}
void Game::initWindow(){
    this->window = std::make_shared<sf::RenderWindow>(
        this->settings.resolution,
        this->settings.title,
        sf::Style::Fullscreen
        );
    this->window->setFramerateLimit(60);
}

void Game::initStateData(){
    this->stateData.window = this->window;
    this->stateData.settings = std::make_shared<GraphicSettings>(this->settings);
    this->stateData.states = std::make_shared<StatesStack>(this->states);
}

void Game::initStates(){
    this->states.push(std::make_shared<MainMenuState>(std::make_shared<StateData>(this->stateData)));
}

void Game::initSettings()
{  
	this->settings = GraphicSettings();
}

Game::Game(){
    this->initSettings();
    this->initWindow();
    this->initStateData();
    this->initStates();    
}

Game::~Game(){
    while(this->states.empty() == false){
        this->states.pop();
    }
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update(){
    this->updateEvents();
    if(this->states.empty() == false){
        this->states.top()->update();
        
        if(this->states.top()->getQuit()){
            this->states.top()->endState();
            this->states.pop();
        }
    }
    else{
        this->endGame();
        this->window->close();
    }
}

void Game::render(){
    this->window->clear();
    if(this->states.empty() == false){
        this->states.top()->render();
    }
    this->window->display();
}

void Game::endGame(){
    
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}