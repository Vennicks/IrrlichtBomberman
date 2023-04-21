/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "../Screen/Screen.hpp"
#include "../music/Music.hpp"
#include "../Tools/Sleep.hpp"
#ifdef WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
    #define Un __attribute__((unused))
#endif
#include <thread>
#include <iostream>
#include <queue>

class Bomb : public irr::scene::ISceneNode
{
    public:
        enum State {
            WAITING,
            EXPLODED
        };
        Bomb(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position);
        ~Bomb();
        virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;
        virtual void render();
        void Create();
        irr::f32 _time;
        int _id;
        State _state;
        int _y;
        int _x;
    protected:
    private:
        Screen *_window;
        int _pouissance;
        irr::core::vector3df _position;
        irr::scene::IMeshSceneNode *_mesh;
        irr::core::aabbox3d<irr::f32> Box;
        irr::video::S3DVertex Vertices[4];
        irr::video::SMaterial Material;
};

#endif /* !BOMB_HPP_ */
