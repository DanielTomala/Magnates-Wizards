#include "../../../headers/ui/states/state.hpp"
#include <iostream>
State::State(StatesStack  *stackPointer,
              sf::RenderWindow *window,
              GraphicSettings *settings){
    this->window = window;

    this->states = stackPointer;

    this->settings = settings;
    this->quit = false;
}

State::~State(){

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
