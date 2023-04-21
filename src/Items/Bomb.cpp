/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(irr::scene::ISceneNode *parent, Screen *window, irr::s32 id, irr::core::vector3df position) : irr::scene::ISceneNode(parent, window->getSceneManager(), id)
{
    _time = 0;
    this->_window = window;
    this->_position = position;
    this->_id = id;
    this->_pouissance = 1;
    _y = static_cast<int>(_position.X * -1 +18) / 36;
    _x = static_cast<int>(_position.Z * -1 +18) / 36;
    Create();
}

void Bomb::Create()
{
    _state = WAITING;
    irr::scene::IMesh *mesh = _window->getSceneManager()->getMesh("./resources/Bomb.obj");
    _mesh = _window->getSceneManager()->addMeshSceneNode(mesh);
    _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _mesh->setID(_id + 1);
    irr::video::ITexture *text = _window->getDriver()->getTexture("./resources/Bomb.png");
    _mesh->setMaterialTexture(0, text);
    _mesh->setPosition(irr::core::vector3df(_position.X, 0, _position.Z));
    _mesh->setScale(irr::core::vector3df(20.2f, 10.5f, 20.2f));
    Music *m = new Music("bomb");
    m->openMusicFromFile("./resources/planting_bomb.ogg");
    m->playMusic();
    Music *tictac = new Music("tictac");
    tictac->openMusicFromFile("./resources/bomb_timer.ogg");
    tictac->playMusic();
}

Bomb::~Bomb()
{
}

const irr::core::aabbox3d<irr::f32>& Bomb::getBoundingBox() const
{
    return Box;
}

void Bomb::render()
{
    irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
    irr::video::IVideoDriver* driver = _window->getDriver();

    driver->setMaterial(Material);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 4, irr::video::EVT_STANDARD, irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT);
}