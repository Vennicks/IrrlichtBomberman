/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <vector>
#include "../Screen/Screen.hpp"
#include "../Items/Walls.hpp"

#ifdef WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
    #define UN __attribute__((unused))
#endif
class Map {
    public:
        Map(irr::scene::ISceneNode *mapNode, Screen *window, std::vector<std::vector<int>> map);
        ~Map();
        void Create();
        irr::s32 _id;
        std::vector<std::vector<DesctructibleWalls *>> _destVector;

    private:
        std::vector<std::vector<int>> _map;
        Screen *_window;
        irr::scene::ISceneNode *_mapNode;
};

#endif /* !MAP_HPP_ */
