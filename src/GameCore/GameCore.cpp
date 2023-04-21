/*
** EPITECH PROJECT, 2020
** testIrrlicht
** File description:
** GameCore
*/

#include "GameCore.hpp"

GameCore::GameCore(Screen *window, EventHandler *event, Character *firstPlayer, Character *secondPlayer,
irr::s32 _id, std::vector<std::vector<int>> mapVector, Map *rmap)
{
    _realmap = rmap;
    _max_id = _id;
    _window = window;
    _event_handler = event;
    _switch_first_char = false;
    _switch_second_char = false;
    _second_player = secondPlayer;
    _first_player = firstPlayer;
    _map = mapVector;
    _mBomb = new Music("bomb");
    _wbroke = new Music("wall_broke");
}

GameCore::~GameCore()
{
}

bool GameCore::canUMove(irr::core::vector3df pos, Dir dir)
{
    int y = static_cast<int>(pos.X * -1 +18) / 36;
    int x = static_cast<int>(pos.Z * -1 +18) / 36;
    double realx = (pos.Z * -1 +18) / 36;
    double realy = (pos.X * -1 +18) / 36;
    if (dir == UP && this->_map[y-1][x] > 0 && realy <= static_cast<double>(y) + 0.15) {
        return false;
    } else if(dir == DOWN && this->_map[y+1][x] > 0 && realy >= static_cast<double>(y+1) - 0.15) {
        return false;
    } else if(dir == RIGHT && this->_map[y][x+1] > 0 && realx >= static_cast<double>(x+1) - 0.15) {
        return false;
    } else if(dir == LEFT && this->_map[y][x-1] > 0 && realx <= static_cast<double>(x) + 0.15) {
        return false;
    }
    return true;
}

void GameCore::actionFirstChar(const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime)
{
    bool action = false;
    if (!_first_player)
        return;
    irr::core::vector3df position = _first_player->getCharacter()->getPosition();
    _position = position;
    if (_event_handler->IsKeyDown(irr::KEY_KEY_S) && !action && _first_player->_can_move && canUMove(position, DOWN)) {
            _first_player->walk(180);
            position.X -= MOVEMENT_SPEED * frameDeltaTime;
            action = true;
    }
    if (_event_handler->IsKeyDown(irr::KEY_KEY_D) && !action && _first_player->_can_move && canUMove(position, RIGHT)) {
        _first_player->walk(90);
        position.Z -= MOVEMENT_SPEED * frameDeltaTime;
        action = true;
    }
    if (_event_handler->IsKeyDown(irr::KEY_KEY_Z) && !action && _first_player->_can_move && canUMove(position, UP)) {
        _first_player->walk(0);
        position.X += MOVEMENT_SPEED * frameDeltaTime;
        action = true;
    }
    if (_event_handler->IsKeyDown(irr::KEY_KEY_Q) && !action && _first_player->_can_move && canUMove(position, LEFT)) {
        _first_player->walk(-90);
        position.Z += MOVEMENT_SPEED * frameDeltaTime;
        action = true;
    }
    if(_event_handler->IsKeyDown(irr::KEY_KEY_E) && _switch_first_char == false) {
        _first_player->put();
        Bomb *b = new Bomb(_window->getSceneManager()->getRootSceneNode(), _window, _max_id, position);
        _window->getSceneManager()->getRootSceneNode()->addChild(b);
        _bomb_vec.push_back(b);
        _switch_first_char = true;
        action = true;
        _max_id++;
    } else if (!_event_handler->IsKeyDown(irr::KEY_KEY_E) && _switch_first_char == true) {
        _switch_first_char = false;
    }

    if (!action) {
        _first_player->idle();
    }
    _first_player->getCharacter()->setPosition(position);
}

void GameCore::actionSecondChar(const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime)
{
    bool action = false;
    if (!_second_player)
        return;
    irr::core::vector3df position = _second_player->getCharacter()->getPosition();
    _position = position;
    if (_event_handler->IsKeyDown(irr::KEY_DOWN) && !action && _second_player->_can_move && canUMove(position, DOWN)) {
            _second_player->walk(180);
            position.X -= MOVEMENT_SPEED * frameDeltaTime;
            action = true;
    }
    if (_event_handler->IsKeyDown(irr::KEY_RIGHT) && !action && _second_player->_can_move && canUMove(position, RIGHT)) {
        _second_player->walk(90);
        position.Z -= MOVEMENT_SPEED * frameDeltaTime;
        action = true;
    }
    if (_event_handler->IsKeyDown(irr::KEY_UP) && !action && _second_player->_can_move && canUMove(position, UP)) {
        _second_player->walk(0);
        position.X += MOVEMENT_SPEED * frameDeltaTime;
        action = true;
    }
    if (_event_handler->IsKeyDown(irr::KEY_LEFT) && !action && _second_player->_can_move && canUMove(position, LEFT)) {
        _second_player->walk(-90);
        position.Z += MOVEMENT_SPEED * frameDeltaTime;
        action = true;
    }
    if(_event_handler->IsKeyDown(irr::KEY_RCONTROL) && _switch_second_char == false) {
        _second_player->put();
        Bomb *b = new Bomb(_window->getSceneManager()->getRootSceneNode(), _window, _max_id, position);
        _window->getSceneManager()->getRootSceneNode()->addChild(b);
        _bomb_vec.push_back(b);
        _switch_second_char = true;
        action = true;
        _max_id++;
    } else if (!_event_handler->IsKeyDown(irr::KEY_RCONTROL) && _switch_second_char == true) {
        _switch_second_char = false;
    }

    if (!action) {
        _second_player->idle();
    }
    _second_player->getCharacter()->setPosition(position);
}

void GameCore::setMaxId(irr::s32 id)
{
    _max_id = id;
}

void GameCore::_explode(size_t x, size_t y, int force)
{
    bool n = true;
    bool s = true;
    bool e = true;
    bool w = true;
    irr::core::vector3df position_first_player = _second_player->getCharacter()->getPosition();
    irr::core::vector3df position_second_player = _first_player->getCharacter()->getPosition();
    size_t y1 = static_cast<size_t>(position_second_player.X * -1 +18) / 36;
    size_t x1 = static_cast<size_t>(position_second_player.Z * -1 +18) / 36;
    size_t y2 = static_cast<size_t>(position_first_player.X * -1 +18) / 36;
    size_t x2 = static_cast<size_t>(position_first_player.Z * -1 +18) / 36;
    _wbroke->openMusicFromFile("./resources/wall_broke.ogg");
    for (int i = 1; i <= force; i++) {
        if ((y - i >= 0) && _map[y-i][x] == 2) n = false;
        if ((y - i >= 0) && _map[y-i][x] == 3 && n) {
            _wbroke->playMusic();
            _realmap->_destVector[y-i][x]->getSceneManager()->getSceneNodeFromId(_realmap->_destVector[y-i][x]->getID() + 1)->remove();
            _map[y-i][x] = 0;
        }
        if ((y+i <= _map.size()-1) && _map[y+i][x] == 2) s = false;
        if ((y+i <= _map.size()-1) && _map[y+i][x] == 3 && s) {
            _realmap->_destVector[y+i][x]->getSceneManager()->getSceneNodeFromId(_realmap->_destVector[y+i][x]->getID() + 1)->remove();
            _wbroke->playMusic();
            _map[y+i][x] = 0;
        }
        if ((x+i <= _map.at(y).size()-1) && _map[y][x+i] == 2) w = false;
        if ((x+i <= _map.at(y).size()-1) && _map[y][x+i] == 3 && w) {
            _realmap->_destVector[y][x+i]->getSceneManager()->getSceneNodeFromId(_realmap->_destVector[y][x+i]->getID() + 1)->remove();
            _wbroke->playMusic();
            _map[y][x+i] = 0;
        }
        if ((x - i >= 0) && _map[y][x-i] == 2) e = false;
        if ((x - i >= 0) && _map[y][x-i] == 3 && e) {
            _realmap->_destVector[y][x-i]->getSceneManager()->getSceneNodeFromId(_realmap->_destVector[y][x-i]->getID() + 1)->remove();
            _wbroke->playMusic();
            _map[y][x-i] = 0;
        }
        if ((y == y1 && x == x1) || ((y - i) == y1 && x == x1) || ((y + i) == y1 && x == x1) || (y == y1 && (x + i) == x1) || (y == y1 && (x - i) == x1))
            _first_player->hurt();
        if ((y == y2 && x == x2) || ((y - i) == y2 && x == x2) || ((y + i) == y2 && x == x2) || (y == y2 && (x + i) == x2) || (y == y2 && (x - i) == x2))
            _second_player->hurt();
    }
}

void GameCore::checkBombEvents(irr::f32 time)
{
    if (_bomb_vec.size() <= 0) return;
    std::vector<Bomb *>::iterator i = _bomb_vec.begin();
    while( i != _bomb_vec.end())
    {
        if ((*i) != NULL) {
            (*i)->_time += time;
            if ((*i)->_time >= 3 && (*i)->_state == Bomb::WAITING) {
                (*i)->_state = Bomb::EXPLODED;
                (*i)->getSceneManager()->getSceneNodeFromId((*i)->_id + 1)->remove();
                _explode((*i)->_x, (*i)->_y, 1);
                (*i)->_time = 0;
                _mBomb->openMusicFromFile("./resources/explosion.ogg");
                _mBomb->playMusic();
            }
        }
        ++i;
    }
}

void GameCore::addFpsToWindow(int *lastFPS)
{
    int fps = _window->getDriver()->getFPS();
    if (*lastFPS != fps)
    {
        irr::core::stringw tmp(L"Movement Example - Irrlicht Engine [");
        tmp += _window->getDriver()->getName();
        tmp += L"] fps: ";
        tmp += fps;
        _window->getDevice()->setWindowCaption(tmp.c_str());
        *lastFPS = fps;
    }
    _window->getSceneManager()->drawAll();
    _window->getDriver()->endScene();
}
void GameCore::gameLoop()
{
    int lastFPS = -1;
    irr::u32 then = _window->getDevice()->getTimer()->getTime();
    const irr::f32 MOVEMENT_SPEED = 100.f;
    while (_window->getDevice()->run()) {
        const irr::u32 now = _window->getDevice()->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f; // Time in seconds
        then = now;
        actionFirstChar(MOVEMENT_SPEED, frameDeltaTime);
        actionSecondChar(MOVEMENT_SPEED, frameDeltaTime);
        _window->getDriver()->beginScene(true, true, irr::video::SColor(255,255,255,255));
        checkBombEvents(frameDeltaTime);
        addFpsToWindow(&lastFPS);
    }
    _window->getDevice()->drop();
}