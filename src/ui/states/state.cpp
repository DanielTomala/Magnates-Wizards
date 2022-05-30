#include "../../../headers/ui/states/state.hpp"
#include <iostream>
State::State(StatesStack  *stackPointer,
              sf::RenderWindow *window,
              GraphicSettings *settings,
              GameController *gameController){
    this->window = window;

    this->states = stackPointer;

    this->settings = settings;
    this->gameController = gameController;
    this->quit = false;
    this->createGrid();
}

State::~State(){

}

void State::createGrid(){
    auto vm = this->window->getSize();
    this->xGrid = vm.x * 0.01;
    this->yGrid = vm.y * 0.01;
}

void State::endState(){
    this->quit = true;
}

void State::updateMousePosition(){
    this->mousePos = sf::Mouse::getPosition(*this->window);
}

bool State::getQuit() const{
    return this->quit;
}
