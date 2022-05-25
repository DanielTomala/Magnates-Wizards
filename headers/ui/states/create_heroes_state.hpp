#ifndef CREATE_HEROES_STATE_HPP
#define CREATE_HEROES_STATE_HPP
#include "configure_heroes_state.hpp"
#include "../button.hpp"
#include "../select_button.hpp"
#include "../descriptions.hpp"



class CreateHeroesState : public State
{
private:
    sf::Texture backgroundTX;
    sf::RectangleShape backgroundRect;
    sf::Font font;


    std::map<std::string, std::shared_ptr<Button>> buttons;
    
    std::map<std::string, std::shared_ptr<SelectButton>> heroButtons;

    std::map<std::string, std::shared_ptr<sf::Text>> texts;

    std::map<std::string, std::shared_ptr<sf::RectangleShape>> shapes;

    Descriptions heroesDescriptions;

    std::vector<HeroType> firstPlayerHeroes;
    std::vector<HeroType> secondPlayerHeroes;

    void initTextures();
    void initFonts();
    void initGui();
    void resetGui();

    void loadHeroes();

public:
    CreateHeroesState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings,
                      GameController *gameController);
    virtual ~CreateHeroesState();

    void updateButtons();
    void update();

    void renderButtons();
    void render();
};

#endif