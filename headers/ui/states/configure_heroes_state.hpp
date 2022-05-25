#ifndef CONFIGURE_HEROES_HPP
#define CONFIGURE_HEROES_HPP

#include "game_state.hpp"
#include "../button.hpp"

class ConfigureHeroesState: public State{
    private:
    
    sf::Texture backgroundTX;
    sf::RectangleShape backgroundRect;
    sf::Font font;


    std::map<std::string, std::shared_ptr<Button>> buttons;
    
    //std::map<std::string, std::shared_ptr<SelectButton>> heroButtons;

    std::map<std::string, std::shared_ptr<sf::Text>> texts;

    std::map<std::string, std::shared_ptr<sf::RectangleShape>> shapes;
    
    
    void initTextures();
    void initFonts();
    void initGui();
    void resetGui();
    
    public:
    ConfigureHeroesState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings,
                      GameController *gameController);
                      
    virtual ~ConfigureHeroesState();

    void updateButtons();
    void update();

    void renderButtons();
    void render();

};

#endif