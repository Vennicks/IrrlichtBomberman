/*
** EPITECH PROJECT, 2020
** dongmaster
** File description:
** MapCreator
*/

#include "MapCreator.hpp"

int MapCreator::getHeight()
{
    return(this->y);
}

int MapCreator::getWidth()
{
    return(this->x);
}

void MapCreator::speak()
{
    if (this->map.size() < 1) {
        std::cout << "NO MAP" << std::endl;
    } else {
        for (size_t i = 0; i < this->map.size(); i++) {
            for (size_t y = 0; y < this->map.at(i).size(); y++) {
                std::cout << this->map.at(i).at(y);
            }
            std::cout << std::endl;
        }
    }
    std::cout << "My settings : x=" << this->x <<" y=" <<this->y <<" disp=" <<this->disp<<std::endl;
}

void MapCreator::fillWalls()
{
    //fill right and left
    for (size_t i = 0; i < this->map.size(); i++) {
        this->map.at(i).at(0) = 1;
        this->map.at(i).at(this->map.at(i).size()-1) = 1;
    }
    //fill up and down
    for (size_t i = 0; i < this->map.at(0).size(); i++) {
        this->map.at(0).at(i) = 1;
        this->map.at(map.size()-1).at(i) = 1;
    }
}

void MapCreator::fillPillars()
{
    for (size_t i = 2; i < this->map.size()-2; i=i+2) {
        for (size_t y = 2; y < this->map.at(i).size()-2; y=y+2) {
            this->map.at(i).at(y) = 2;
        }
    }
}

void MapCreator::fillBox()
{
    srand(time(NULL));
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t y = 0; y < this->map.at(i).size(); y++) {
            float random = ((float) rand()) / (float) RAND_MAX;
            if (random < this->disp) {
                this->map.at(i).at(y) = 3;
            }
        }
    }
}

void MapCreator::clearCorners()
{
    this->map.at(1).at(1) = 0;
    this->map.at(1).at(2) = 0;
    this->map.at(2).at(1) = 0;

    this->map.at(1).at(map.at(1).size()-3) = 0;
    this->map.at(1).at(map.at(1).size()-2) = 0;
    this->map.at(2).at(map.at(2).size()-2) = 0;

    this->map.at(map.size()-2).at(1) = 0;
    this->map.at(map.size()-2).at(2) = 0;
    this->map.at(map.size()-3).at(1) = 0;

    this->map.at(map.size()-2).at(map.at(1).size()-2) = 0;
    this->map.at(map.size()-2).at(map.at(1).size()-3) = 0;
    this->map.at(map.size()-3).at(map.at(1).size()-2) = 0;
}

std::vector<std::vector<int>> MapCreator::genmap()
{
    if (this->getHeight() < 5) this->y = 5;
    if (this->getWidth() < 5) this->x = 5;
    if (this->disp < 0 || this->disp > 1) this->disp = 0.5;

    std::vector<int> line;
    for (int i = 0; i < this->x; i++) {
        line.push_back(0);
    }
    for (int i = 0; i < this->y; i++) {
        this->map.push_back(line);
    }
    this->fillBox();
    this->fillWalls();
    this->fillPillars();
    this->clearCorners();
    return map;
}

MapCreator::MapCreator(int x, int y, float disp)
{
    this->x = x;
    this->y = y;
    this->disp = disp;
}

MapCreator::~MapCreator()
{
}