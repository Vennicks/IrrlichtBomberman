/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EventHandler
*/

#ifndef EVENTHANDLER_HPP_
#define EVENTHANDLER_HPP_

#ifdef WIN32
    #include <irrlicht.h>
#else
    #include <irr/irrlicht.h>
#endif

class EventHandler : public irr::IEventReceiver
{
public:
    // This is the one method that we have to implement
    virtual bool OnEvent(const irr::SEvent& event)
    {
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        return false;
    }

    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }
    EventHandler()
    {
        for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }

    private:
        bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};
#endif /* !EVENTHANDLER_HPP_ */
