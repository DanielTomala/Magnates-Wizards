#ifndef CREATE_HEROES_STATE_HPP
#define CREATE_HEROES_STATE_HPP
#include "state.hpp"
#include "../button.hpp"

class CreateHeroesState: public State{
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
        CreateHeroesState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings);
        virtual ~CreateHeroesState();

        void updateButtons();
        void update();

        void renderButtons();
        void render();
};

#endif