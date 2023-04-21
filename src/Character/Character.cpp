/*
** EPITECH PROJECT, 2020
** testIrrlicht
** File description:
** Character
*/

#include "Character.hpp"
#include "../music/Music.hpp"

Character::Character(irr::scene::ISceneNode *parent, Screen *window, const irr::io::path filename, irr::s32 id) : irr::scene::ISceneNode(parent, window->getSceneManager(), id)
{
    _character = window->getSceneManager()->addAnimatedMeshSceneNode (
        window->getSceneManager()->getMesh(filename));
    if (!_character) {
        window->getDevice()->drop();
        std::exit(84);
    }
    _window = window;
    _hp = 3;
    lock = false;
    _state = NONE;
    _can_move = true;
    _character->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    Material.Wireframe = false;
    Material.Lighting = false;

    _character->setFrameLoop(0, 13);
    _character->setAnimationSpeed(15);
    _character->setRotation(irr::core::vector3df(0,-90,0));
}

Character::~Character()
{
}

bool Character::getLock() const
{
    return lock;
}

irr::scene::IAnimatedMeshSceneNode *Character::getCharacter() const
{
    return _character;
}

void Character::unlock_anim(int i)
{
    Sleep(i*10000);
    lock = false;
}

void Character::walk(int i)
{
    if (_state != WALK && !lock) {
        _character->setMD2Animation(irr::scene::EMAT_RUN);
        _state = WALK;
         Music *step = new Music("step");
        step->openMusicFromFile("./resources/charac_move.ogg");
        step->playMusic();
    }
    orientation(i);
}

void Character::put()
{
    if (_state != PUT && !lock) {
        _character->setMD2Animation(irr::scene::EMAT_SALUTE);
        _state = PUT;
        lock = true;
        #ifdef WIN32
            std::thread *thd = new std::thread(&Character::unlock_anim, this, 50);
        #else
            std::thread *thd UN = new std::thread(&Character::unlock_anim, this, 50);
        #endif
    }
}

void Character::del(int i)
{
    Sleep(i*10000);
    _character->setMD2Animation(irr::scene::EMAT_BOOM);
    _character->setAnimationSpeed(0);
}

void Character::die()
{
    if (_state != DYING) {
        Music *die = new Music("die");
        die->openMusicFromFile("./resources/charac_death.ogg");
        die->playMusic();
        _can_move = false;
        lock = true;
        _character->setMD2Animation(irr::scene::EMAT_DEATH_FALLBACKSLOW);
        #ifdef WIN32
            std::thread *thd = new std::thread(&Character::del, this, 90);
        #else
            std::thread *thd UN = new std::thread(&Character::del, this, 90);
        #endif
        _state = DYING;
    }
}

void Character::hurt()
{
    if (_state != HURT) {
        _hp--;
        if (_hp <= 0) {
            this->die();
            return;
        }
        lock = true;
        Music *mHurt = new Music("Hurt");
        mHurt->openMusicFromFile("./resources/charac_damage.ogg");
        mHurt->playMusic();
        #ifdef WIN32
            std::thread *thd = new std::thread(&Character::unlock_anim, this, 50);
        #else
            std::thread *thd UN = new std::thread(&Character::unlock_anim, this, 50);
        #endif
        _character->setMD2Animation(irr::scene::EMAT_PAIN_B);
        _state = HURT;
    }
}

void Character::idle()
{
    if (_state != IDLE && !lock) {
        _character->setMD2Animation(irr::scene::EMAT_STAND);
        _state = IDLE;
    }
}

void Character::orientation(int i)
{
    _character->setRotation(irr::core::vector3df(0,i,0));
}

void Character::setMaterialTexture(Screen *window, const irr::io::path filename)
{
    _character->setMaterialTexture(0, window->getDriver()->getTexture(filename));
}

const irr::core::aabbox3d<irr::f32>& Character::getBoundingBox() const
{
    return Box;
}

void Character::render()
{
    irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
    irr::video::IVideoDriver* driver = _window->getDriver();

    driver->setMaterial(Material);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 4, irr::video::EVT_STANDARD, irr::scene::EPT_TRIANGLES, irr::video::EIT_16BIT);
}