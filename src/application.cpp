#include "../headers/application.hpp"
#include <iostream>


Application::Application(bool scr):fullscreen(scr){
	time = sf::seconds(0);
	if (fullscreen)
		window.create(sf::VideoMode(monitor[0], monitor[1]), title, sf::Style::Fullscreen);
	else{
		window.create(sf::VideoMode(screen[0], screen[1]), title);
		center_window();
	}

	unsigned int xFields = 10, yFields = 6, field_size = 100;
	topLeft.x = (monitor[0] - xFields*field_size)/2;
	topLeft.y = (monitor[1] - yFields*field_size)/2;

}

void Application::output(){
	std::cout << "Monitor size: " << monitor[0] << ", " << monitor[1] << std::endl;
	std::cout << "Screen size: " << screen[0] << ", " << screen[1] << std::endl;
	std::cout << "Fullscreen: " << fullscreen << std::endl;
	std::cout << "Frame Time: " << time.asSeconds() << std::endl;
	std::cout << "Game Time: " << game_time.asSeconds() << std::endl;
	std::cout << "Mouse Position: " << mouse.x << " " << mouse.y << std::endl;
	std::cout << std::endl;
}

void Application::center_window(){
	window.setPosition(
		sf::Vector2i(
			(monitor[0] / 2) - (screen[0] / 2),
			(monitor[1] / 2) - (screen[1] / 2)
		)
	);
}

void Application::events(sf::Event e){
	while(window.pollEvent(e)){
		if (e.type == sf::Event::Closed){
			window.close();
		}
		else if (e.type == sf::Event::KeyPressed){
			if (e.key.code == sf::Keyboard::Escape){
				window.close();
			}
		}
		// if (e.type == sf::Event::MouseButtonPressed){
		// 	if (e.mouseButton.button == sf::Mouse::Left){
		// 		window.close();
		// 	}
		// }
	}
}

void Application::time_update(){
	time = clock.restart();
	game_time = game_clock.getElapsedTime();
}

void Application::update(){
	output();
	time_update();
	mouse = sf::Mouse::getPosition(window);
}


void Application::render(){
	window.clear();
	window.draw(backgroundSprite);
	window.display();
}

// void Application::loadTextures(){
// 	backgroundTX.loadFromFile("textures/background.png");
// 	fieldTX.loadFromFile("textures/field.png");
// 	field_greenTX.loadFromFile("textures/field_green.png");
// 	field_redTX.loadFromFile("textures/field_red.png");
// 	stoneTX.loadFromFile("textures/stone.png");
// 	bowerTX.loadFromFile("textures/bower.png");
// 	catapultTX.loadFromFile("textures/catapult.png");
// 	gnd_druideTX.loadFromFile("textures/gnd_druide.png");
// 	knightTX.loadFromFile("textures/knight.png");
// 	magicianTX.loadFromFile("textures/magician.png");
// 	medicTX.loadFromFile("textures/medic.png");
// 	ninjaTX.loadFromFile("textures/ninja.png");
// 	trebuchetTX.loadFromFile("textures/trebuchet.png");
// 	wizardTX.loadFromFile("textures/wizard.png");
// }

// void Application::loadSprites(){
// 	backgroundSprite.setTexture(backgroundTX);
// 	fieldSprite.setTexture(fieldTX);
// 	field_greenSprite.setTexture(field_greenTX);
// 	field_redSprite.setTexture(field_redTX);
// 	stoneSprite.setTexture(stoneTX);
// 	bowerSprite.setTexture(bowerTX);
// 	gnd_druideSprite.setTexture(gnd_druideTX);
// 	knightSprite.setTexture(knightTX);
// 	magicianSprite.setTexture(magicianTX);
// 	medicSprite.setTexture(medicTX);
// 	ninjaSprite.setTexture(ninjaTX);
// 	trebuchetSprite.setTexture(trebuchetTX);
// 	wizardSprite.setTexture(wizardTX);
// }

void Application::loadBackground(){
	backgroundTX.loadFromFile("textures/background.png");
	sf::Vector2u size = backgroundTX.getSize();
	backgroundSprite.setTexture(backgroundTX);
	float xScale = monitor[0]/size.x;
	float yScale = monitor[1]/size.y;
	backgroundSprite.setScale(xScale, yScale);
	backgroundSprite.setPosition(0,0);
}

void Application::run(){
	loadBackground();
	while (window.isOpen()){
		sf::Event event;
		events(event);
		update();
		render();
	}
}

