/*
** EPITECH PROJECT, 2020
** testIrrlicht
** File description:
** GameCore
*/

#ifndef GAMECORE_HPP_
#define GAMECORE_HPP_
#include <iostream>
#include "../Screen/Screen.hpp"
#include "./EventHandler.hpp"
#include "../Items/Bomb.hpp"
#include <vector>
#include <iterator>
#include "../Character/Character.hpp"
#include "../map/Map.hpp"
#include "../map/MapCreator.hpp"
class GameCore {
    public:
        enum Dir {
            LEFT,
            RIGHT,
            UP,
            DOWN
        };
        GameCore(Screen *Window, EventHandler *event, Character *firstPlayer , Character *secondPlayer,
        irr::s32 id, std::vector<std::vector<int>> map, Map *rmap);
        ~GameCore();
        void gameLoop();
        void actionFirstChar(const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime);
        void actionSecondChar(const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime);
        void setMaxId(irr::s32 id);
        void checkBombEvents(irr::f32 time);
        bool canUMove(irr::core::vector3df pos, Dir dir);
        void addFpsToWindow(int *lastFPS);
    protected:
    private:
        void _explode(size_t x, size_t y, int force);
        std::vector<Bomb *> _bomb_vec;
        bool _switch_first_char;
        bool _switch_second_char;
        Screen *_window;
        EventHandler *_event_handler;
        Character *_first_player;
        Character *_second_player;
        irr::s32 _max_id;
        Music *_mBomb;
        Music *_wbroke;
        Map *_realmap;
        irr::core::vector3df _position;
        std::vector<std::vector<int>> _map;
};

#endif /* !GAMECORE_HPP_ */
