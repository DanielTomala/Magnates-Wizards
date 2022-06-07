#ifndef CONFIGURE_HEROES_HPP
#define CONFIGURE_HEROES_HPP

#include "game_state.hpp"
#include "../button.hpp"
#include "../select_button.hpp"
#include "../descriptions.hpp"
#include "../../game_logic/heroes/archer.hpp"
#include "../../game_logic/heroes/catapult.hpp"
#include "../../game_logic/heroes/iceDruid.hpp"
#include "../../game_logic/heroes/knight.hpp"
#include "../../game_logic/heroes/mage.hpp"
#include "../../game_logic/heroes/medic.hpp"
#include "../../game_logic/heroes/ninja.hpp"
#include "../../game_logic/heroes/trebuchet.hpp"


class ConfigureHeroesState : public State
{
private:
    sf::Texture backgroundTX;
    sf::RectangleShape backgroundRect;
    sf::Font font;

    Descriptions descriptions;

    std::map<std::string, std::shared_ptr<Button>> buttons;
    std::map<std::tuple<HeroType, Player>, std::shared_ptr<Button>> heroButtons;
    std::map<std::tuple<int, int>, std::shared_ptr<Button>> boardButtons;
    std::map<Personalisation, std::shared_ptr<Button>> menuButtons;
    std::map<std::string, std::shared_ptr<sf::Text>> texts;
    std::map<std::string, std::shared_ptr<sf::RectangleShape>> shapes;

    std::vector<std::shared_ptr<Hero>> firstPlayerHeroes;
    std::vector<std::shared_ptr<Hero>> secondPlayerHeroes;

    std::optional<std::shared_ptr<Hero>> choosenHero;

    void initBoard();
    void initTextures();
    void initFonts();
    void initGui();
    void initHeroes(std::vector<HeroType> firstPlayerHeroes,
                    std::vector<HeroType> secondPlayerHeroes);

    void showHero(std::shared_ptr<Hero> hero, int buttonX, int buttonY);
    void putHero(std::shared_ptr<Hero> hero, int xCoo, int yCoo);
    void showMenu();
    void hideMenu();

    std::shared_ptr<Hero> createHero(HeroType heroType);
    std::string heroTypeToString(HeroType herotype);

    void renderBackground();
    void renderShapes();
    void renderTexts();
    void renderBoardButtons();
    void renderButtons();
    void renderHeroButtons();
    void renderMenuButtons();
    void renderHeroes();

    void updateButtons();
    void updateBoardButtons();
    void updateHeroButtons();
    void updateMenuButtons();

public:
    ConfigureHeroesState(StatesStack *stackPointer,
                         sf::RenderWindow *window,
                         GraphicSettings *settings,
                         GameController *gameController,
                         std::vector<HeroType> firstPlayerHeroes,
                         std::vector<HeroType> secondPlayerHeroes);

    virtual ~ConfigureHeroesState();

    void update();
    void render();
};

#endif