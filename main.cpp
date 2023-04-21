/*
** EPITECH PROJECT, 2020
** testIrrlicht
** File description:
** main
*/

#include <iostream>
#include "./src/Screen/Screen.hpp"
#include "./src/GameCore/GameCore.hpp"
#include "./src/GameCore/EventHandler.hpp"
#include "./src/Character/Character.hpp"
#include "./src/Items/Walls.hpp"
#include "./src/menu/Menu.hpp"
#include <vector>

int main(void)
{
    Music *mGucci = new Music("Gucci");
    mGucci->openMusicFromFile("./resources/gucci_gang.ogg");
    mGucci->setLoopMusic(true);
    mGucci->playMusic();
    Screen *window = new Screen(1920, 1080, 32, NULL);
    Menu menu(window);
    menu.MenuLoop();
    mGucci->stopMusic();
    return (0);
}