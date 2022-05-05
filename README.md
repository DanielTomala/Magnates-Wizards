# 22L_PROI_PROJ_ZD_IO_PR_DT

## Game_Name

## Description
Game description

## Authors
Team 25/25:
- Zuzanna Damszel
- Ireneusz Okniński
- Paweł Rogóż
- Daniel Tomala

## Using CMake
#### First use:
    mkdir build
    cd build
    cmake ..

#### To build all executables:
    cd build
    cmake --build .

#### Run executable:
    cd build
    ./main

#### Run all tests:
    ctest

#### Run one test to get more details:
    cd build
    ./tests_name

#### When adding new file to program:
1. Add file name to SRC variable

#### When adding new test to program add this line to CMakeLists.txt:
    add_executable(tests_name tests_path ${SRC})
    add_test(NAME Test_name COMMAND tests_name)
Name of executable ("tests_name") and name written after COMMAND ("tests_name") must be the same