cmake_minimum_required(VERSION 3.11)
project(oop_indie_studio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

find_package(Threads)
include_directories(includes)
include_directories(src/Character)
include_directories(src/GameCore)
include_directories(src/Screen)
include_directories(src/Map)
include_directories(src/Tools)
include_directories(src/menu)
add_executable(
    bomberman
    main.cpp
    src/Character/Character.cpp
    src/GameCore/GameCore.cpp
    src/Screen/Screen.cpp
    src/Items/Walls.cpp
    src/map/Map.cpp
    src/map/MapCreator.cpp
    src/music/Music.cpp
    src/Tools/Sleep.cpp
    src/Items/Bomb.cpp
    src/menu/Menu.cpp
    src/menu/EventMenu.cpp
)
target_link_libraries(bomberman sfml-audio)
target_link_libraries(bomberman Irrlicht)
target_link_libraries (bomberman ${CMAKE_THREAD_LIBS_INIT})