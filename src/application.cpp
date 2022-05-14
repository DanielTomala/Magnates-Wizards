#include "../headers/application.hpp"
 

Application::Application(bool scr):fullscreen(scr){
	time = sf::seconds(0);
	if (fullscreen)
		window.create(sf::VideoMode(monitor[0], monitor[1]), title, sf::Style::Fullscreen);
	else{
		window.create(sf::VideoMode(screen[0], screen[1]), title);
		center_window();
	}

	topLeft.x = (monitor[0] - BOARD_COLUMNS*FIELD_SIZE)/2;
	topLeft.y = (monitor[1] - BOARD_ROWS*FIELD_SIZE)/2;

}

void Application::output(){
	std::cout << "Monitor size: " << monitor[0] << ", " << monitor[1] << std::endl;
	std::cout << "Screen size: " << screen[0] << ", " << screen[1] << std::endl;
	std::cout << "Fullscreen: " << fullscreen << std::endl;
	std::cout << "Frame Time: " << time.asSeconds() << std::endl;
	std::cout << "Game Time: " << game_time.asSeconds() << std::endl;
	std::cout << "Mouse Positions: " << mouse.x << " " << mouse.y << std::endl;
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
	this->drawBoard();
	window.display();
}


void Application::loadBackground(){
	auto backgroundTX = textures["background.png"];
	sf::Vector2u size = backgroundTX->getSize();
	backgroundSprite.setTexture(*backgroundTX, false);
	float xScale = monitor[0]/size.x;
	float yScale = monitor[1]/size.y;
	backgroundSprite.setScale(xScale, yScale);
	backgroundSprite.setPosition(0,0);
}


void Application::run(){
	loadTextures();
	createBoard();
	loadFieldsSprites();
	loadBackground();
	while (window.isOpen()){
		sf::Event event;
		events(event);
		update();
		render();
	}
}


void Application::drawBoard(){
    FieldsArray fields = board.getFields();
    for (unsigned int x=0; x<BOARD_ROWS; x++)
    {
        for (unsigned int y=0; y<BOARD_COLUMNS; y++)
        {
			auto field = board.getFieldByCoordinate(x, y);
			window.draw(field->sprite);

			// if(field->isFree() == false){
			// 	auto hero = field->getHero();
			// 	window.draw(hero->sprite);
			// }
        }
    }
}

void Application::loadTextures(){
	std::string path = "textures/";
	for (const auto & entry : std::filesystem::directory_iterator(path)){
		auto texture = std::make_shared<sf::Texture>();
		texture->loadFromFile(entry.path());
        textures[entry.path().filename()]  = texture;
	}
}

void Application::loadFieldsSprites(){
	sf::Vector2f coordiantes;
	FieldsArray fields = board.getFields();
	Hero hero;
    for (unsigned int x=0; x<BOARD_ROWS; x++){
        for (unsigned int y=0; y<BOARD_COLUMNS; y++){
			float xCoordinate = topLeft.x + FIELD_SIZE*y;
			float yCoordinate = topLeft.y + FIELD_SIZE*x;
			coordiantes = {xCoordinate, yCoordinate};
			auto field = board.getFieldByCoordinate(x,y);
			if(field->isFree()){
				auto fieldTX = textures["field.png"];
				field->sprite.setTexture(*fieldTX, true);
			}
			else{
				//TODO zaimplementować wyswietlanie roznych kolorów pól
				auto fieldTX  = textures["field_red.png"];
				field->sprite.setTexture(*fieldTX, true);
				auto hero = field->getHero();
			}
			field->sprite.setPosition(coordiantes);
		}
	}	
}

void Application::createBoard(){
	FieldsArray fields;
	for (unsigned int x=0; x<BOARD_ROWS; x++){
        for (unsigned int y=0; y<BOARD_COLUMNS; y++){
			auto field = std::make_shared<Field>();
			fields[x][y] = field;
		}
	}
	this->board = Board(fields);
}