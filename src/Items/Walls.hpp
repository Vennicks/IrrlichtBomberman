/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Walls
*/

#ifndef WALLS_HPP_
#define WALLS_HPP_

#ifdef WIN32
    #include <irrlicht.h>
#else
    #include <irr/irrlicht.h>
#endif

#include "../Screen/Screen.hpp"

class Pillars : public irr::scene::ISceneNode
{
    public:
        Pillars(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position);
        ~Pillars();
        void Create();
        virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;
        virtual void render();

    private:
        irr::scene::IMeshSceneNode *_node;
        irr::core::vector3df _position;
        Screen *_window;
        irr::core::aabbox3d<irr::f32> Box;
        irr::video::S3DVertex Vertices[4];
        irr::video::SMaterial Material;
};

class DesctructibleWalls : public irr::scene::ISceneNode
{
    public:
        DesctructibleWalls(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position);
        ~DesctructibleWalls();
        void Create();
        virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;
        virtual void render();

    private:
        irr::scene::IMeshSceneNode *_node;
        irr::core::vector3df _position;
        Screen *_window;
        int _id;
        irr::core::aabbox3d<irr::f32> Box;
        irr::video::S3DVertex Vertices[4];
        irr::video::SMaterial Material;
};

class IndesctructibleWalls : public irr::scene::ISceneNode
{
    public:
        IndesctructibleWalls(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position);
        ~IndesctructibleWalls();
        void Create();
        virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;
        virtual void render();

    private:
        irr::scene::IMeshSceneNode *_node;
        irr::core::vector3df _position;
        Screen *_window;
        irr::core::aabbox3d<irr::f32> Box;
        irr::video::S3DVertex Vertices[4];
        irr::video::SMaterial Material;
};

class Floor : public irr::scene::ISceneNode
{
    public:
        Floor(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position);
        ~Floor();
        void Create();
        virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;
        virtual void render();

    private:
        irr::scene::IMeshSceneNode *_node;
        irr::core::vector3df _position;
        Screen *_window;
        irr::core::aabbox3d<irr::f32> Box;
        irr::video::S3DVertex Vertices[4];
        irr::video::SMaterial Material;
};

#endif /* !WALLS_HPP_ */
