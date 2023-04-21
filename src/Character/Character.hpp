/*
** EPITECH PROJECT, 2020
** testIrrlicht
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "../Screen/Screen.hpp"
#ifdef WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
    #define UN __attribute__((unused))
#endif
#include <thread>
#include <iostream>
#include "../Tools/Sleep.hpp"


class Character : public irr::scene::ISceneNode
{
    enum Statement
    {
        NONE,
        WALK,
        IDLE,
        DYING,
        PUT,
        HURT
    };
    public:
        Character(irr::scene::ISceneNode *parent, Screen *window, const irr::io::path filename, irr::s32 id);
        ~Character();
        irr::scene::IAnimatedMeshSceneNode *getCharacter() const;
        void setMaterialTexture(Screen *window, const irr::io::path filename);
        void walk(int i);
        void put();
        void hurt();
        void die();
        void idle();
        void orientation(int i);
        void unlock_anim(int i);
        bool getLock() const;
        void del(int i);
        bool _can_move;
        virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;
        virtual void render();
    protected:
    private:
        irr::core::vector3df _position;
        Statement _state;
        bool lock;
        int _hp;
        Screen *_window;
        irr::scene::IAnimatedMeshSceneNode *_character;
        irr::core::aabbox3d<irr::f32> Box;
        irr::video::S3DVertex Vertices[4];
        irr::video::SMaterial Material;
};

#endif /* !CHARACTER_HPP_ */
