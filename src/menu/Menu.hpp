/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../Screen/Screen.hpp"

#include "EventMenu.hpp"

class Menu {
    public:
        Menu(Screen *window);
        ~Menu();
        int MenuLoop();

    protected:
    private:
        irr::gui::IGUIEnvironment* _env;
        irr::gui::IGUISkin *_skin;
        Screen *_window;
        irr::video::ITexture *_background;
        irr::gui::IGUIButton * _bouton_new;
        irr::gui::IGUIButton * _bouton_load;
        irr::gui::IGUIButton * _bouton_quit;
};

#endif /* !MENU_HPP_ */
