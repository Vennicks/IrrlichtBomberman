/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#include "Music.hpp"

Music::Music(const std::string &name)
{
    this->_name = name;
}

Music::~Music()
{

}

bool Music::loadSoundFromFile(const std::string &filename)
{
    if (this->_buffer.loadFromFile(filename) == false)
        return false;
    return true;
}

void Music::setSoundFromLoadedFile()
{
    this->_sound.setBuffer(this->_buffer);
}

void Music::playSound()
{
    this->_music.play();
}

void Music::pauseSound()
{
    this->_music.pause();
}

void Music::stopSound()
{
    this->_music.stop();
}

void Music::setPitchSound(float pitch)
{
    this->_music.setPitch(pitch);
}

void Music::setVolumeSound(float volume)
{
    this->_music.setVolume(volume);
}

void Music::setLoopSound(bool loop)
{
    this->_music.setLoop(loop);
}

sf::Sound &Music::getSound()
{
    return this->_sound;
}

bool Music::openMusicFromFile(const std::string &filename)
{
    if (this->_music.openFromFile(filename) == false)
        return false;
    return true;
}

void Music::playMusic()
{
    this->_music.play();
}

void Music::pauseMusic()
{
    this->_music.pause();
}

void Music::stopMusic()
{
    this->_music.stop();
}

void Music::setPitchMusic(float pitch)
{
    this->_music.setPitch(pitch);
}

void Music::setVolumeMusic(float volume)
{
    this->_music.setVolume(volume);
}

void Music::setLoopMusic(bool loop)
{
    this->_music.setLoop(loop);
}

sf::Music &Music::getMusic()
{
    return this->_music;
}

const std::string &Music::getName() const
{
    return this->_name;
}