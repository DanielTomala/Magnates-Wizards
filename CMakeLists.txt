cmake_minimum_required(VERSION 3.10)
project(PROI_project)

# set(SRC
#     src/hero.cpp
#     src/weapon.cpp
#     src/wearable.cpp
# )
file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")          #Get all cpp files
file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/headers/*.hpp")  #Get all header files

set_property(GLOBAL PROPERTY CXX_STANDARD 20)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)
add_compile_options(-std=c++2a -Wall -Wextra -Werror -pedantic)

add_executable(main main.cpp ${SRC})

add_executable(hero_tests tests/tests_hero.cpp ${SRC})
add_executable(weapon_tests tests/tests_weapon.cpp ${SRC})
add_executable(wearable_tests tests/tests_wearable.cpp ${SRC})

enable_testing()
add_test(NAME Hero_tests COMMAND hero_tests)
add_test(NAME Weapon_tests COMMAND weapon_tests)
add_test(NAME Wearable_tests COMMAND wearable_tests)