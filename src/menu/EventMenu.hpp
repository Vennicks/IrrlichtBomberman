/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EventMenu
*/

#ifndef EVENTMENU_HPP_
#define EVENTMENU_HPP_

#include <irr/irrlicht.h>
#include <irr/IImage.h>
#include <irr/IGUIButton.h>
#include "../src/Screen/Screen.hpp"
#include "../src/GameCore/GameCore.hpp"
#include "../src/GameCore/EventHandler.hpp"
#include "../src/Character/Character.hpp"
#include "../src/Items/Walls.hpp"
#include "../src/menu/Menu.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

struct SAppContext {
    irr::IrrlichtDevice *device;
    irr::s32             counter;
    irr::gui::IGUIListBox*    listbox;
};

enum {
    ID_QUIT_BUTTON = 101,
    ID_NEW_GAME_BUTTON,
    ID_LOAD_GAME_BUTTON
};

class EventReceiverMenu : public irr::IEventReceiver
{
    public:
        EventReceiverMenu(SAppContext & context, Screen *_window) : Context(context) {
            window = _window;
        }
        ~EventReceiverMenu() {}
        virtual bool OnEvent(const irr::SEvent& event);
    private:
        Screen *window;
        SAppContext &Context;
};


#endif /* !EVENTMENU_HPP_ */
