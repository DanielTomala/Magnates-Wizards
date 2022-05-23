CC=g++
CFLAGS=-c -Wall -std=c++2a
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES= main.cpp src/gameplay/game_controller.cpp src/game_logic/board.cpp src/game_logic/field.cpp src/game_logic/heroes/hero.cpp src/game_logic/weapons/weapon.cpp src/game_logic/wearable.cpp src/game_logic/weapons/bow.cpp src/ui/button.cpp src/gameplay/game.cpp src/ui/graphic_settings.cpp src/ui/states/state.cpp src/ui/states/main_menu_state.cpp src/ui/states/create_heroes_state.cpp src/ui/states/player_menu_state.cpp src/ui/states/game_state.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=build

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm main.o src/*.o src/states/*.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)