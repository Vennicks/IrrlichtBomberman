/*
** EPITECH PROJECT, 2020
** testIrrlicht
** File description:
** Screen
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#ifdef WIN32
    #include <irrlicht.h>
#else
    #include <irr/irrlicht.h>
#endif

#include <string>
#include "../GameCore/EventHandler.hpp"
class Screen {
    public:
        Screen(int width, int height, int bits, EventHandler *event);
        ~Screen();
        irr::IrrlichtDevice *getDevice();
        irr::video::IVideoDriver *getDriver();
        irr::scene::ISceneManager *getSceneManager();
    private:
        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_sceneManager;
};

#endif /* !SCREEN_HPP_ */
