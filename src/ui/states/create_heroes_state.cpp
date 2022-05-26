#include "../../../headers/ui/states/create_heroes_state.hpp"


#include <iostream>
CreateHeroesState::CreateHeroesState(StatesStack *stackPointer,
                      sf::RenderWindow *window,
                      GraphicSettings *settings,
					  GameController *gameController)
	: State(stackPointer, window, settings, gameController)
{	
	this->heroesDescriptions = Descriptions();
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->resetGui();
}

void CreateHeroesState::initTextures(){
	if (!this->backgroundTX.loadFromFile("../textures/backgrounds/battleback1.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	if (!this->textures["BUTTON"].loadFromFile("../textures/button.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ARCHER"].loadFromFile("../textures/archer.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["KNIGHT"].loadFromFile("../textures/knight.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["WIZARD"].loadFromFile("../textures/wizard.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["ICE_DRUID"].loadFromFile("../textures/ice_druid.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["CATAPULT"].loadFromFile("../textures/catapult.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["MEDIC"].loadFromFile("../textures/medic.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["NINJA"].loadFromFile("../textures/ninja.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
	if (!this->textures["TREBUCHET"].loadFromFile("../textures/trebuchet.png")){
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_TEXTURE";
	}
}


void CreateHeroesState::initFonts()
{
	if (!this->font.loadFromFile("../src/ui/states/Dosis-Light.ttf"))
	{
		throw("ERROR::CreateHeroesSTATE::COULD NOT LOAD FONT");
	}
	
}

void CreateHeroesState::initGui(){
	const sf::Vector2u vm = this->window->getSize();
	std::cout<<vm.x<<" "<<vm.y<<"\n";
	this->backgroundRect.setSize(
		sf::Vector2f(
			(float)vm.x,
			(float)vm.y)
	);
	

	this->backgroundRect.setTexture(&this->backgroundTX);
	
	this->texts["HERO_DESCRIPTION"] = std::make_shared<sf::Text>("", this->font, 20);
	this->texts["HERO_DESCRIPTION"] -> setPosition(375.f, 100.f);
	this->texts["HERO_DESCRIPTION"] -> setFillColor(sf::Color::Black);
	this->texts["HERO_DESCRIPTION"] -> setStyle(sf::Text::Bold);

	this->texts["MANUAL"] = std::make_shared<sf::Text>(this->heroesDescriptions.getManual(), this->font, 20);
	this->texts["MANUAL"] -> setPosition(vm.x-675.f, 100.f);
	this->texts["MANUAL"] -> setFillColor(sf::Color::Black);
	this->texts["MANUAL"] -> setStyle(sf::Text::Bold);


	this->texts["ERROR"] = std::make_shared<sf::Text>("", this->font, 20);
	this->texts["ERROR"] -> setPosition(375.f, 700.f);
	this->texts["ERROR"] -> setFillColor(sf::Color::Black);
	this->texts["ERROR"] -> setStyle(sf::Text::Bold);
	
	this->texts["PLAYER_1"] = std::make_shared<sf::Text>("PLAYER 1", this->font, 30);
	this->texts["PLAYER_1"] -> setPosition(130.f, 100.f);
	this->texts["PLAYER_1"] -> setFillColor(sf::Color::Black);
	this->texts["PLAYER_1"] -> setStyle(sf::Text::Bold);

	this->texts["PLAYER_2"] = std::make_shared<sf::Text>("PLAYER 2", this->font, 30);
	this->texts["PLAYER_2"] -> setPosition(vm.x - 230.f, 100.f);
	this->texts["PLAYER_2"] -> setFillColor(sf::Color::Black);
	this->texts["PLAYER_2"] -> setStyle(sf::Text::Bold);

	this->shapes["LEFT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["LEFT_BG"] -> setFillColor(sf::Color(214, 154, 58));
	this->shapes["LEFT_BG"] -> setSize(sf::Vector2f{300.f, 650.f});
	this->shapes["LEFT_BG"] -> setPosition(sf::Vector2f{25.f, 75.f});

	this->shapes["RIGHT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["RIGHT_BG"] -> setFillColor(sf::Color(214, 154, 58));
	this->shapes["RIGHT_BG"] -> setSize(sf::Vector2f{300.f, 650.f});
	this->shapes["RIGHT_BG"] -> setPosition(sf::Vector2f{vm.x-325.f, 75.f});

	this->shapes["MIDDLE_LEFT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["MIDDLE_LEFT_BG"] -> setFillColor(sf::Color(214, 154, 58));
	this->shapes["MIDDLE_LEFT_BG"] -> setSize(sf::Vector2f{350.f, 350.f});
	this->shapes["MIDDLE_LEFT_BG"] -> setPosition(sf::Vector2f{350.f, 75.f});
	
	this->shapes["MIDDLE_RIGHT_BG"] = std::make_shared<sf::RectangleShape>();
	this->shapes["MIDDLE_RIGHT_BG"] -> setFillColor(sf::Color(214, 154, 58));
	this->shapes["MIDDLE_RIGHT_BG"] -> setSize(sf::Vector2f{350.f, 650.f});
	this->shapes["MIDDLE_RIGHT_BG"] -> setPosition(sf::Vector2f{vm.x-700.f, 75.f});
	
	float buttonWidth = 100, buttonHeight = 50;
	float topLeft_x = vm.x - buttonWidth;
	float topLeft_y = 0.f;
	this->buttons["EXIT"] = std::make_shared<Button>(
		topLeft_x, topLeft_y, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "BACK", 30,
		textures["BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);

	this->buttons["START"] = std::make_shared<Button>(
		topLeft_x, vm.y-buttonHeight, buttonWidth, buttonHeight, std::make_shared<sf::Font>(this->font), "START", 30,
		textures["BUTTON"], sf::Color::Yellow, sf::Color::Magenta, sf::Color::Blue, 1
	);

	this->heroButtons["ARCHER_1"] = std::make_shared<SelectButton>(
		50.f, 150.f, 100.f, 100.f, textures["ARCHER"], sf::Color::Green, heroesDescriptions.getDescription(EArcher), First, EArcher);
	
	this->heroButtons["KNIGHT_1"] = std::make_shared<SelectButton>(
		50.f, 300.f, 100.f, 100.f, textures["KNIGHT"], sf::Color::Green, heroesDescriptions.getDescription(EKnight), First, EKnight);
	
	this->heroButtons["ICE_DRUID_1"] = std::make_shared<SelectButton>(
		50.f, 450.f, 100.f, 100.f, textures["ICE_DRUID"], sf::Color::Green, heroesDescriptions.getDescription(EIceDruid), First, EIceDruid);
	
	this->heroButtons["CATAPULT_1"] = std::make_shared<SelectButton>(
		50.f, 600.f, 100.f, 100.f, textures["CATAPULT"], sf::Color::Green, heroesDescriptions.getDescription(ECatapult), First, ECatapult);
	
	this->heroButtons["NINJA_1"] = std::make_shared<SelectButton>(
		200.f, 150.f, 100.f, 100.f, textures["NINJA"], sf::Color::Green, heroesDescriptions.getDescription(ENinja), First, ENinja);
	
	this->heroButtons["MEDIC_1"] = std::make_shared<SelectButton>(
		200.f, 300.f, 100.f, 100.f, textures["MEDIC"], sf::Color::Green, heroesDescriptions.getDescription(EMedic), First, EMedic);
	
	this->heroButtons["WIZARD_1"] = std::make_shared<SelectButton>(
		200.f, 450.f, 100.f, 100.f, textures["WIZARD"], sf::Color::Green, heroesDescriptions.getDescription(EWizard), First, EWizard);
	
	this->heroButtons["TREBUCHET_1"] = std::make_shared<SelectButton>(
		200.f, 600.f, 100.f, 100.f, textures["TREBUCHET"], sf::Color::Green, heroesDescriptions.getDescription(ETrebuchet), First, ETrebuchet);

	this->heroButtons["ARCHER_2"] = std::make_shared<SelectButton>(
		vm.x-300.f, 150.f, 100.f, 100.f, textures["ARCHER"], sf::Color::Green, heroesDescriptions.getDescription(EArcher), Second, EArcher);
	
	this->heroButtons["KNIGHT_2"] = std::make_shared<SelectButton>(
		vm.x-300.f, 300.f, 100.f, 100.f, textures["KNIGHT"], sf::Color::Green, heroesDescriptions.getDescription(EKnight), Second, EKnight);
	
	this->heroButtons["ICE_DRUID_2"] = std::make_shared<SelectButton>(
		vm.x-300.f, 450.f, 100.f, 100.f, textures["ICE_DRUID"], sf::Color::Green, heroesDescriptions.getDescription(EIceDruid), Second, EIceDruid);
	
	this->heroButtons["CATAPULT_2"] = std::make_shared<SelectButton>(
		vm.x-300.f, 600.f, 100.f, 100.f, textures["CATAPULT"], sf::Color::Green, heroesDescriptions.getDescription(ECatapult), Second, ECatapult);
	
	this->heroButtons["NINJA_2"] = std::make_shared<SelectButton>(
		vm.x-150.f, 150.f, 100.f, 100.f, textures["NINJA"], sf::Color::Green, heroesDescriptions.getDescription(ENinja), Second, ENinja);
	
	this->heroButtons["MEDIC_2"] = std::make_shared<SelectButton>(
		vm.x-150.f, 300.f, 100.f, 100.f, textures["MEDIC"], sf::Color::Green, heroesDescriptions.getDescription(EMedic), Second, EMedic);
	
	this->heroButtons["WIZARD_2"] = std::make_shared<SelectButton>(
		vm.x-150.f, 450.f, 100.f, 100.f, textures["WIZARD"], sf::Color::Green, heroesDescriptions.getDescription(EWizard), Second, EWizard);
	
	this->heroButtons["TREBUCHET_2"] = std::make_shared<SelectButton>(
		vm.x-150.f, 600.f, 100.f, 100.f, textures["TREBUCHET"], sf::Color::Green, heroesDescriptions.getDescription(ETrebuchet), Second, ETrebuchet);
}
void CreateHeroesState::resetGui()
{
	this->buttons.clear();

	this->initGui();
}

CreateHeroesState::~CreateHeroesState(){

}

void CreateHeroesState::loadHeroes(){
	for (auto &it : this->heroButtons)
	{
		if(it.second->isChoosen()){
			if(it.second->getPlayer() == First){
				this->firstPlayerHeroes.push_back(it.second->getHeroType());
			}
			if(it.second->getPlayer() == Second){
				this->secondPlayerHeroes.push_back(it.second->getHeroType());
			}
		}
	}
}

void CreateHeroesState::updateButtons(){

	if (this->buttons["EXIT"]->isClicked()){
		this->endState();
	}

	if(this->heroButtons["ARCHER_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["ARCHER_1"]->getDescription());
	}
	else if(this->heroButtons["ARCHER_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["ARCHER_2"]->getDescription());
	}
	else if(this->heroButtons["KNIGHT_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["KNIGHT_1"]->getDescription());
	}
	else if(this->heroButtons["KNIGHT_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["KNIGHT_2"]->getDescription());
	}
	else if(this->heroButtons["NINJA_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["NINJA_1"]->getDescription());
	}
	else if(this->heroButtons["NINJA_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["NINJA_2"]->getDescription());
	}
	else if(this->heroButtons["ICE_DRUID_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["ICE_DRUID_1"]->getDescription());
	}
	else if(this->heroButtons["ICE_DRUID_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["ICE_DRUID_2"]->getDescription());
	}
	else if(this->heroButtons["CATAPULT_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["CATAPULT_1"]->getDescription());
	}
	else if(this->heroButtons["CATAPULT_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["CATAPULT_2"]->getDescription());
	}
	else if(this->heroButtons["TREBUCHET_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["TREBUCHET_1"]->getDescription());
	}
	else if(this->heroButtons["TREBUCHET_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["TREBUCHET_2"]->getDescription());
	}
	else if(this->heroButtons["WIZARD_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["WIZARD_1"]->getDescription());
	}
	else if(this->heroButtons["WIZARD_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["WIZARD_2"]->getDescription());
	}
	else if(this->heroButtons["MEDIC_1"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["MEDIC_1"]->getDescription());
	}
	else if(this->heroButtons["MEDIC_2"]->isHovered()){

		this->texts["HERO_DESCRIPTION"] -> setString(this->heroButtons["MEDIC_2"]->getDescription());
	}
	else{
		this->texts["HERO_DESCRIPTION"] -> setString("");
	}

	if (this->buttons["START"]->isClicked()){
		this->loadHeroes();
		if(this->firstPlayerHeroes.size() != 4 || this->secondPlayerHeroes.size() != 4){
			this->texts["ERROR"] -> setString("wrong heroes number");
			this->firstPlayerHeroes.clear();
			this->secondPlayerHeroes.clear();
		}
		else{
		this->states->pop();
		this->states->push(new ConfigureHeroesState(this->states,
                                         this->window,
                                         this->settings,
										 this->gameController));
		this->endState();
		}
	}

	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePos);
	}

	for (auto &it : this->heroButtons)
	{
		it.second->update(this->mousePos);
	}

}

void CreateHeroesState::update(){
	this->updateMousePosition();
	this->updateButtons();
}

void CreateHeroesState::renderButtons()
{
	for (auto &it : this->shapes)
	{
		this->window->draw(*it.second);
	}	

	for (auto &it : this->buttons)
	{
		it.second->render(*this->window);
	}	

	for (auto &it : this->heroButtons)
	{
		it.second->render(*this->window);
	}

	for (auto &it : this->texts)
	{
		this->window->draw(*it.second);
	}

}

void CreateHeroesState::render(){
	this->window->draw(this->backgroundRect);
	this->renderButtons();
}
