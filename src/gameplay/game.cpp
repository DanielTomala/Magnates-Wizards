#include "../../headers/gameplay/game.hpp"

Game::Game()
{
    this->initSettings();
    this->initController();
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;
    while (this->states.empty() == false)
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::initVariables()
{
}
void Game::initWindow()
{
    //Daniel
    this->window = new sf::RenderWindow(
        this->settings.resolution,
        this->settings.title,
        sf::Style::Default);
    //Irek
    // this->window = new sf::RenderWindow(
    //     this->settings.resolution,
    //     this->settings.title,
    //     sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

void Game::initStates()
{
    // ODKOMENTUJ STATE NAD KTÓRYM PRACUJESZ
    // W STATE NAD KTÓRYM PRACUJESZ NIE PRZECHODŹ DO INNYCH STATOW BO I TAK NIE ZADZIAŁA
    // TESTUJ TYLKO JEDEN STATE NA RAZ

    // this->states.push(new MainMenuState(&this->states,
    //                                               this->window,
    //                                               &this->settings,
    //                                               &this->controller));

    // this->states.push(std::make_shared<CreateHeroesState>(std::make_shared<StatesStack>(this->states),
    //                                               this->window,
    //                                               std::make_shared<GraphicSettings>(this->settings)));

    // this->states.push(std::make_shared<GameState>(std::make_shared<StatesStack>(this->states),
    //                                               this->window,
    //                                               std::make_shared<GraphicSettings>(this->settings)));

    this->states.push(new MainMenuState(&this->states,
                                    this->window,
                                    &this->settings,
                                    &this->controller));

    // this->states.push(std::make_shared<PlayerState>(std::make_shared<StatesStack>(this->states),
    //                                               this->window,
    //                                               std::make_shared<GraphicSettings>(this->settings)));
}

void Game::initSettings()
{
    this->settings = GraphicSettings();
}

void Game::initController()
{
    this->controller = GameController(std::make_shared<Board>());
}

void Game::updateEvents()
{
    while (this->window->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateEvents();
    // std::cout << this->states.size() << "\n";
    if (this->states.empty() == false)
    {
        if (this->window->hasFocus())
        {
            this->states.top()->update();
            if (this->states.top()->getQuit())
            {
                this->states.top()->endState();
                delete this->states.top();
                this->states.pop();
            }
        }
    }
    else
    {
        this->endGame();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();
    if (this->states.empty() == false)
    {
        this->states.top()->render();
    }
    this->window->display();
}

void Game::endGame()
{
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}