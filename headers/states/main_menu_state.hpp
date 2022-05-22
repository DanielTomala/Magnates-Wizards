#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP
#include "create_heroes_state.hpp"
#include "../button.hpp"
#include <iostream>

class MainMenuState: public State{
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
        MainMenuState(std::shared_ptr<StatesStack> stackPointer,
                      std::shared_ptr<sf::RenderWindow> window,
                      std::shared_ptr<GraphicSettings> settings);
        virtual ~MainMenuState();

        void updateButtons();
        void update();

        void renderButtons();
        void render();
};
#endif