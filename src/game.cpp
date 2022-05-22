#include "../headers/game.hpp"
void Game::initVariables()
{

}
void Game::initWindow(){
    this->window = std::make_shared<sf::RenderWindow>(
        this->settings.resolution,
        this->settings.title,
        sf::Style::Fullscreen
        );
    this->window->setFramerateLimit(60);
}


void Game::initStates(){
        // ODKOMENTUJ STATE NAD KTÓRYM PRACUJESZ
        // W STATE NAD KTÓRYM PRACUJESZ NIE PRZECHODŹ DO INNYCH STATOW BO I TAK NIE ZADZIAŁA
        // TESTUJ TYLKO JEDEN STATE NA RAZ
        
        // this->states.push(std::make_shared<MainMenuState>(std::make_shared<StatesStack>(this->states),
        //                                               this->window,
        //                                               std::make_shared<GraphicSettings>(this->settings)));
        
        // this->states.push(std::make_shared<CreateHeroesState>(std::make_shared<StatesStack>(this->states),
        //                                               this->window,
        //                                               std::make_shared<GraphicSettings>(this->settings)));
        
        // this->states.push(std::make_shared<GameState>(std::make_shared<StatesStack>(this->states),
        //                                               this->window,
        //                                               std::make_shared<GraphicSettings>(this->settings)));
        
        // this->states.push(std::make_shared<PlayerState>(std::make_shared<StatesStack>(this->states),
        //                                               this->window,
        //                                               std::make_shared<GraphicSettings>(this->settings)));

}

void Game::initSettings()
{  
	this->settings = GraphicSettings();
}

Game::Game(){
    this->initSettings();
    this->initWindow();
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
    std::cout<<this->states.size()<<"\n";
    if(this->states.empty() == false){   		
        if (this->window->hasFocus()){
            this->states.top()->update();
            if(this->states.top()->getQuit()){
                this->states.top()->endState();
                this->states.pop();
            }
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