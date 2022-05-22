#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP
#include "state.hpp"
#include "../button.hpp"
#include <iostream>

class MainMenuState: public State{
    private:
        sf::Texture backgroundTX;
        sf::RectangleShape backgroundRect;
        sf::Font font;

        std::map<std::string, std::shared_ptr<Button>> buttons;

        void initFonts();
        void initGui();
        void resetGui();
    public:
        MainMenuState(std::shared_ptr<StateData> stateData);
        virtual ~MainMenuState();

        void updateButtons();
        void update();

        void renderButtons();
        void render();
};
#endif