CXX = g++
CXX_FLAGS = -Wall -Wextra -pedantic -Werror -fsanitize=undefined -std=c++2a

vpath %.cpp ./src ./tests
vpath %.hpp ./headers
vpath %.o ./build

HEADERS := ./headers
BUILD := ./build
ALL_O = $(wildcard $(BUILD)/*.o)
ALL_HPP = $(wildcard $(HEADERS)/*.hpp)


main: main.o
	$(CXX) $(CXX_FLAGS) $(ALL_O) -o main

tests_catch: tests.o
	$(CXX) $(CXX_FLAGS) ./build/tests.o -o tests_catch

main.o: main.cpp
	$(CXX) $(CXX_FLAGS) -I$(HEADERS) -c $< -o $(BUILD)/$@

tests.o: tests.cpp
	$(CXX) $(CXX_FLAGS) -I$(HEADERS) -c $< -o $(BUILD)/$@

# Template
# file_name.o: file_name.cpp file_name.hpp other1.hpp other2.hpp
# 	$(CXX) $(CXX_FLAGS) -I$(HEADERS) -c $< -o $(BUILD)/$@

clean:
	rm build/*.o