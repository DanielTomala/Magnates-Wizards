#include "../../headers/states/state.hpp"

State::State(std::shared_ptr<StateData> stateData){
    this->stateData = stateData;
    this->window = stateData->window;
    this->states = stateData->states;
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
