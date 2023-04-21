/*
** EPITECH PROJECT, 2020
** dongmaster
** File description:
** MapCreator
*/

#ifndef MAPCREATOR_HPP_
#define MAPCREATOR_HPP_

#include <vector>
#include <iostream>

class MapCreator {
    public:
        MapCreator(int x, int y, float disp);
        ~MapCreator();

        int getHeight();
        int getWidth();
        std::vector<std::vector<int>> genmap();

        void speak();

    protected:
    private:
        int x;
        int y;
        float disp;
        std::vector<std::vector<int>> map;
        void fillWalls();
        void fillPillars();
        void fillBox();
        void clearCorners();
};

#endif /* !MAPCREATOR_HPP_ */
