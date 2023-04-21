/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sleep
*/

#ifndef SLEEP_HPP_
#define SLEEP_HPP_

#ifdef WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

class Sleep {
    public:
        Sleep(int sleep);
        ~Sleep();

    protected:
    private:
};

#endif /* !SLEEP_HPP_ */
