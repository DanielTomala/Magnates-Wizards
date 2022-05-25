#ifndef PLAYER_MENU_STATE_HPP
#define PLAYER_MENU_STATE_HPP

#include "state.hpp"
#include "../button.hpp"

class PlayerMenuState: public State{
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
        PlayerMenuState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings,
                      GameController *gameController);
        virtual ~PlayerMenuState();

        void updateButtons();
        void update();

        void renderButtons();
        void render();
};

#endif