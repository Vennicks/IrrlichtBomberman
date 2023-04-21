/*
** EPITECH PROJECT, 2020
** testIrrlicht
** File description:
** Screen
*/

#include "Screen.hpp"

Screen::Screen(int width, int height, int bits, EventHandler *event)
{
    _device = irr::createDevice (
        irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(width, height),
        bits,
        false,
        true,
        false,
        event
    );
    _driver = _device->getVideoDriver();
    _sceneManager = _device->getSceneManager ();
    _device->setWindowCaption(L"BOMBERMAN 3D");
    _device->setResizable(true);
}

Screen::~Screen()
{
}

irr::IrrlichtDevice *Screen::getDevice()
{
    return _device;
}


irr::video::IVideoDriver *Screen::getDriver()
{
    return _driver;
}

irr::scene::ISceneManager *Screen::getSceneManager()
{
    return _sceneManager;
}