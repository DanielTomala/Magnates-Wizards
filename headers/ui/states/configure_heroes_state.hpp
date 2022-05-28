#ifndef CONFIGURE_HEROES_HPP
#define CONFIGURE_HEROES_HPP

#include "game_state.hpp"
#include "../button.hpp"
#include "../select_button.hpp"


class ConfigureHeroesState: public State{
    private:
    
    sf::Texture backgroundTX;
    sf::RectangleShape backgroundRect;
    sf::Font font;


    std::map<std::string, std::shared_ptr<Button>> buttons;
    
    //std::map<std::string, std::shared_ptr<SelectButton>> heroButtons;

    std::map<std::string, std::shared_ptr<sf::Text>> texts;

    std::map<std::string, std::shared_ptr<sf::RectangleShape>> shapes;
    
    std::vector<std::shared_ptr<Hero>> firstPlayerHeroes;
    std::vector<std::shared_ptr<Hero>> secondPlayerHeroes;

    std::map<std::tuple<HeroType, Player>, std::shared_ptr<Button>> heroButtons;

    std::map<std::tuple<int, int>, std::shared_ptr<Button>> boardButtons;
    

    void initHeroes(std::vector<HeroType> firstPlayerHeroes,
                    std::vector<HeroType> secondPlayerHeroes);

    std::shared_ptr<Hero> createHero(HeroType heroType);
    
    void initBoard();
    void initTextures();
    void initFonts();
    void initGui();
    void resetGui();
    void renderHeroes();
    void drawBoard();
    void showHero(std::shared_ptr<Hero> hero, int buttonX, int buttonY);
    void putHero(std::shared_ptr<Hero> hero, int xCoo, int yCoo);
    void showMenu();
    void hideMenu();
    std::string heroTypeToString(HeroType herotype);

    std::optional<std::shared_ptr<Hero>> choosenHero;

    public:
    ConfigureHeroesState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings,
                      GameController *gameController,
                      std::vector<HeroType> firstPlayerHeroes,
                      std::vector<HeroType> secondPlayerHeroes);
                      
    virtual ~ConfigureHeroesState();

    void updateButtons();
    void update();

    void renderButtons();
    void render();

};

#endif