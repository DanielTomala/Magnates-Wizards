#ifndef STATE_HPP
#define STATE_HPP

#include "../graphic_settings.hpp"
#include <memory>
#include <stack>


class State{
    protected:
        std::shared_ptr<GraphicSettings> GraphicSettings;               // settings of window
        std::shared_ptr<std::stack<std::shared_ptr<State>>> states;     // stack of states
        std::shared_ptr<sf::RenderWindow> window;                       // pointer for window

        bool quit;
        sf::Vector2i mousePos;

        std::map<std::string, sf::Texture> textures;
    
    public:
        State();
        virtual ~State();

        void endState();
        
        virtual void update() = 0;
        virtual void render() = 0;
};

#endif