/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(Screen *window)
{
    _window = window;
    _env = _window->getDevice()->getGUIEnvironment();
    _skin = _env->getSkin();
    printf("loop\n");
    _background = _window->getDriver()->getTexture("./src/menu/menu_background4.png");
    _skin->setFont(_env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
     _bouton_new= _env->addButton(irr::core::rect<irr::s32>(20,800,610,920 + 50), 0, ID_NEW_GAME_BUTTON, L"");
    _bouton_load = _env->addButton(irr::core::rect<irr::s32>(640,800,1250,920 + 50), 0, ID_LOAD_GAME_BUTTON, L"");
    _bouton_quit = _env->addButton(irr::core::rect<irr::s32>(1290,800,1900,920 + 50), 0, ID_QUIT_BUTTON, L"");
    _bouton_new->setImage(_window->getDriver()->getTexture("./src/menu/New_game_button.png"));
    _bouton_load->setImage(_window->getDriver()->getTexture("./src/menu/Load_game_button.png"));
    _bouton_quit->setImage(_window->getDriver()->getTexture("./src/menu/Quit_game_button.png"));
}

Menu::~Menu()
{
}

int Menu::MenuLoop()
{
    SAppContext context;
    context.device = _window->getDevice();
    context.counter = 0;
    EventReceiverMenu receiver(context, _window);
    _window->getDevice()->setEventReceiver(&receiver);
     while(_window->getDevice()->run() && _window->getDevice())
        if (_window->getDevice()->isWindowActive()) {
            _window->getDriver()->beginScene(true, true, irr::video::SColor(0,200,200,200));
            _window->getDriver()->draw2DImage(_background, irr::core::position2d<irr::s32>(-385,-250));
            _env->drawAll();
            _window->getDriver()->endScene();
        }
    _window->getDevice()->drop();
    return 0;
}
