/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(irr::scene::ISceneNode *mapNode, Screen *window, std::vector<std::vector<int>> map)
{
    this->_map = map;
    this->_window = window;
    _mapNode = mapNode;
    _id = 20;
    Create();
}

Map::~Map()
{
}

void Map::Create()
{
    int z = 0;
    int x = 0;

    x = 0;
    for (size_t line = 0; line < _map.size(); line++) {
        std::vector<DesctructibleWalls *> destW;
        z = 0;
        for (size_t column = 0; column < _map[line].size(); column++) {
            if (_map[line][column] ==  1) {
                #ifdef WIN32
                    IndesctructibleWalls *i = new IndesctructibleWalls(_mapNode, _window, _id,irr::core::vector3df(x, 0, z));
                #else
                    IndesctructibleWalls *i UN = new IndesctructibleWalls(_mapNode, _window, _id,irr::core::vector3df(x, 0, z));
                #endif
                destW.push_back(NULL);
                z -= 36;
            }
            if (_map[line][column] ==  2) {
                #ifdef WIN32
                    Pillars *p = new Pillars(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                    Floor *f = new Floor(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                #else
                    Pillars *p UN = new Pillars(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                    Floor *f UN = new Floor(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                #endif
                destW.push_back(NULL);
                z -= 36;
            }
            if (_map[line][column] == 3) {
                #ifdef WIN32
                    DesctructibleWalls *d = new DesctructibleWalls(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                    Floor *f = new Floor(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                #else
                    DesctructibleWalls *d UN = new DesctructibleWalls(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                    Floor *f UN = new Floor(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                #endif
                destW.push_back(d);
                z -= 36;
            }
            if (_map[line][column] == 0) {
                #ifdef WIN32
                    Floor *f = new Floor(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                #else
                    Floor *f UN = new Floor(_mapNode, _window, _id, irr::core::vector3df(x, 0, z));
                #endif
                destW.push_back(NULL);
                z -= 36;
            }
            _id++;
        }
        this->_destVector.push_back(destW);
        x -= 36;
    }
}