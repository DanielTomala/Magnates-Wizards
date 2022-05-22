#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "state.hpp"
#include "../button.hpp"

class GameState: public State{
    private:
        sf::Texture backgroundTX;
        sf::RectangleShape backgroundRect;
        sf::Font font;

        std::map<std::string, std::shared_ptr<Button>> buttons;
	
        void initTextures();
        void initFonts();
        void initGui();
        void resetGui();
    public:
        GameState(std::shared_ptr<StatesStack> stackPointer,
                          std::shared_ptr<sf::RenderWindow> window,
                          std::shared_ptr<GraphicSettings> settings);
        virtual ~GameState();

        void updateButtons();
        void update();

        void renderButtons();
        void render();
};

#endif