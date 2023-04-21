/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Walls
*/

#include "Walls.hpp"

Floor::Floor(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position) : irr::scene::ISceneNode(parent, window->getSceneManager(), id)
{
    this->_position = position;
    this->_window = window;
    Create();
}

Floor::~Floor()
{
    _node->remove();
}

void Floor::Create()
{
    irr::scene::IMesh *mesh = _window->getSceneManager()->getMesh("./resources/Sol.obj");

    _node = _window->getSceneManager()->addMeshSceneNode(mesh);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(
        0,
        _window->getDriver()->getTexture("./resources/Sol.png")
    );
    _node->setPosition(_position);
    _node->setScale(irr::core::vector3df(20.2f, 10.5f, 20.2f));

}

Pillars::Pillars(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position) : irr::scene::ISceneNode(parent, window->getSceneManager(), id)
{
    this->_position = position;
    this->_window = window;
    Create();
}

Pillars::~Pillars()
{
    _node->remove();
}

void Pillars::Create()
{
    irr::scene::IMesh *mesh = _window->getSceneManager()->getMesh("./resources/Column.obj");

    _node = _window->getSceneManager()->addMeshSceneNode(mesh);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(
        0,
        _window->getDriver()->getTexture("./resources/Column.png")
    );
    _node->setPosition(_position);
    _node->setScale(irr::core::vector3df(20.2f, 10.5f, 20.2f));

}

void Floor::render()
{
    irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
    irr::video::IVideoDriver* driver = _window->getDriver();

    driver->setMaterial(Material);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 4, irr::video::EVT_STANDARD, irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT);
}

const irr::core::aabbox3d<irr::f32>& Floor::getBoundingBox() const
{
    return Box;
}

DesctructibleWalls::DesctructibleWalls(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position) : irr::scene::ISceneNode(parent, window->getSceneManager(), id)
{
    this->_position = position;
    this->_window = window;
    this->_id = id;
    Create();
}

DesctructibleWalls::~DesctructibleWalls()
{
    _node->remove();
}

void IndesctructibleWalls::Create()
{
    irr::scene::IMesh *mesh = _window->getSceneManager()->getMesh("./resources/Concrete.obj");

    _node = _window->getSceneManager()->addMeshSceneNode(mesh);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(
        0,
        _window->getDriver()->getTexture("./resources/Concrete.png")
    );
    _node->setPosition(_position);
    _node->setScale(irr::core::vector3df(20.2f, 10.5f, 20.2f));
}

IndesctructibleWalls::IndesctructibleWalls(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position) : irr::scene::ISceneNode(parent, window->getSceneManager(), id)
{
    this->_position = position;
    this->_window = window;
    Create();
}

IndesctructibleWalls::~IndesctructibleWalls()
{
    _node->remove();
}

void DesctructibleWalls::Create()
{
    irr::scene::IMesh *mesh = _window->getSceneManager()->getMesh("./resources/Bricks.obj");

    _node = _window->getSceneManager()->addMeshSceneNode(mesh);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setID(_id + 1);
    _node->setMaterialTexture(
        0,
        _window->getDriver()->getTexture("./resources/Bricks.png")
    );
    _node->setPosition(_position);
    _node->setScale(irr::core::vector3df(20.2f, 10.5f, 20.2f));
}

const irr::core::aabbox3d<irr::f32>& Pillars::getBoundingBox() const
{
    return Box;
}

void Pillars::render()
{
    irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
    irr::video::IVideoDriver* driver = _window->getDriver();

    driver->setMaterial(Material);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 4, irr::video::EVT_STANDARD, irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT);
}

const irr::core::aabbox3d<irr::f32>& IndesctructibleWalls::getBoundingBox() const
{
    return Box;
}

void IndesctructibleWalls::render()
{
    irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
    irr::video::IVideoDriver* driver = _window->getDriver();

    driver->setMaterial(Material);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 4, irr::video::EVT_STANDARD, irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT);
}

const irr::core::aabbox3d<irr::f32>& DesctructibleWalls::getBoundingBox() const
{
    return Box;
}

void DesctructibleWalls::render()
{
    irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
    irr::video::IVideoDriver* driver = _window->getDriver();

    driver->setMaterial(Material);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 4, irr::video::EVT_STANDARD, irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT);
}