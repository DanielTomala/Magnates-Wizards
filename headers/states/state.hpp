#ifndef STATE_HPP
#define STATE_HPP

#include "../graphic_settings.hpp"
#include <memory>
#include <stack>

class State;
typedef std::stack<std::shared_ptr<State>> StatesStack;

class State{
    protected:
        std::shared_ptr<GraphicSettings> settings;                      // settings of window
        std::shared_ptr<StatesStack> states;                            // stack of states
        std::shared_ptr<sf::RenderWindow> window;                       // pointer for window

        bool quit;
        std::map<std::string, sf::Texture> textures;

        sf::Vector2i mousePos;

    
    public:
        State(std::shared_ptr<StatesStack> stackPointer,
              std::shared_ptr<sf::RenderWindow> window,
              std::shared_ptr<GraphicSettings> settings);
        virtual ~State();

        void endState();

        bool getQuit() const;

        virtual void updateMousePosition();
        virtual void update() = 0;
        virtual void render() = 0;
};

#endif