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
        MainMenuState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings,
                      GameController *gameController);
        virtual ~MainMenuState();

        void updateButtons();
        void update();

        void renderButtons();
        void render();
};
#endif