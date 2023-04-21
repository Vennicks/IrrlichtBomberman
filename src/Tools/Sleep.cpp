/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sleep
*/

#include "Sleep.hpp"

Sleep::Sleep(int microsecondes)
{
    #ifdef WIN32
        Sleep(microsecondes / 1000);
    #else
        usleep(microsecondes);
    #endif
}

Sleep::~Sleep()
{
}
