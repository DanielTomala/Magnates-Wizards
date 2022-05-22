CC=g++
CFLAGS=-c -Wall -std=c++2a
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES= main.cpp src/game_controller.cpp src/board.cpp src/field.cpp src/hero.cpp src/weapon.cpp src/wearable.cpp src/weapons/bow.cpp src/button.cpp src/game.cpp src/graphic_settings.cpp src/states/state.cpp src/states/main_menu_state.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=build

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm main.o src/*.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)