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
        this->states.pop();
    }
}


void Game::initWindow()
{
    this->window = new sf::RenderWindow(
        this->settings.resolution,
        this->settings.title,
        sf::Style::Fullscreen);
    this->window->setFramerateLimit(this->settings.frameLimit);
}

void Game::initStates()
{
    this->states.push(std::make_shared<MainMenuState>(&this->states,
                                        this->window,
                                        &this->settings,
                                        &this->controller));
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
    if (this->states.empty() == false)
    {
        if (this->window->hasFocus())
        {
            this->states.top()->update();
            if (this->states.top()->getQuit())
            {
                this->states.top()->endState();
                this->states.pop();
            }
        }
    }
    else
    {
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

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}