/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <iostream>

class Music {
    public:
        Music(const std::string &name = "default");
        ~Music();
        const std::string &getName() const;
    public:
        bool loadSoundFromFile(const std::string &filename);
        void setSoundFromLoadedFile();
        void playSound();
        void pauseSound();
        void stopSound();
        void setPitchSound(float pitch);
        void setVolumeSound(float volume);
        void setLoopSound(bool state);
        sf::Sound &getSound();

    public:
        bool openMusicFromFile(const std::string &filename);
        void playMusic();
        void pauseMusic();
        void stopMusic();
        void setPitchMusic(float pitch);
        void setVolumeMusic(float volume);
        void setLoopMusic(bool state);
        sf::Music &getMusic();

    private:
        sf::SoundBuffer _buffer;
        sf::Music _music;
        sf::Sound _sound;
        std::string _name;
};

#endif /* !MUSIC_HPP_ */
