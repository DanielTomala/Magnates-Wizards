cmake_minimum_required(VERSION 3.10)
project(Magantes&Wizards)

set(SRC
    #Game_Logic
    src/game_logic/heroes/hero.cpp
    src/game_logic/heroes/hero_attributes.cpp
    src/game_logic/weapons/bow.cpp
    src/game_logic/weapons/ice_druid_staff.cpp
    src/game_logic/weapons/mage_wand.cpp
    src/game_logic/weapons/medical_box.cpp
    src/game_logic/weapons/shuriken.cpp
    src/game_logic/weapons/sword.cpp
    src/game_logic/weapons/stone.cpp
    src/game_logic/weapons/weapon.cpp
    src/game_logic/board.cpp
    src/game_logic/field.cpp
    src/game_logic/wearable.cpp
    #Gameplay
    src/gameplay/game_controller.cpp
    src/gameplay/game.cpp
    #UI
    src/ui/states/create_heroes_state.cpp
    src/ui/states/configure_heroes_state.cpp
    src/ui/states/game_state.cpp
    src/ui/states/main_menu_state.cpp
    src/ui/states/state.cpp
    src/ui/button.cpp
    src/ui/HPbar.cpp
    src/ui/loads.cpp
    src/ui/select_button.cpp
    src/ui/descriptions.cpp
    src/ui/graphic_settings.cpp
    src/ui/action_menu_buttons.cpp
)
# file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")          #Get all cpp files
# file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/headers/*.hpp")  #Get all header files

set_property(GLOBAL PROPERTY CXX_STANDARD 20)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++2a -Wall -Wextra -Werror -pedantic -lsfml-graphics -lsfml-window -lsfml-system)
# SFML
# find_package(SFML COMPONENTS Graphics Window System)
include(FetchContent)
# set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)

add_executable(main main.cpp ${SRC})
target_link_libraries(main sfml-graphics sfml-window sfml-audio sfml-system)

add_executable(hero_tests tests/tests_hero.cpp ${SRC})
target_link_libraries(hero_tests sfml-graphics sfml-window sfml-audio sfml-system)

add_executable(weapon_tests tests/tests_weapon.cpp ${SRC})
target_link_libraries(weapon_tests sfml-graphics sfml-window sfml-audio sfml-system)


add_executable(wearable_tests tests/tests_wearable.cpp ${SRC})
target_link_libraries(wearable_tests sfml-graphics sfml-window sfml-audio sfml-system)

add_executable(board_tests tests/tests_board.cpp ${SRC})
target_link_libraries(board_tests sfml-graphics sfml-window sfml-audio sfml-system)

add_executable(field_tests tests/tests_field.cpp ${SRC})
target_link_libraries(field_tests sfml-graphics sfml-window sfml-audio sfml-system)

enable_testing()
add_test(NAME Hero_tests COMMAND hero_tests)
add_test(NAME Weapon_tests COMMAND weapon_tests)
add_test(NAME Wearable_tests COMMAND wearable_tests)
add_test(NAME Board_tests COMMAND board_tests)
add_test(NAME Field_tests COMMAND field_tests)