/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** EventMenu
*/

#include "EventMenu.hpp"

void newGame(Screen *window)
{
    EventHandler receiver;
    window->getDevice()->setEventReceiver(&receiver);
    irr::scene::ISceneNode *mapNode = window->getSceneManager()->addSceneNode("Map");
    irr::scene::ISceneNode *rootNode = window->getSceneManager()->getRootSceneNode();
    Character *player1 = new Character(mapNode, window, "./resources/sydney.md2", 1);
    Character *player2 = new Character(mapNode, window, "./resources/sydney.md2", 1);
    rootNode->addChild(mapNode);
    rootNode->addChild(player1);
    rootNode->addChild(player2);
    player1->setMaterialTexture(window, "./resources/sydney.bmp");
    player2->setMaterialTexture(window, "./resources/Britney.png");
    player1->getCharacter()->setPosition(irr::core::vector3df(-36, 24, -36));
    player2->getCharacter()->setPosition(irr::core::vector3df(-400, 24, -612));
    MapCreator map(19, 13, 0.51); //comme le pastaga
    std::vector<std::vector<int>> mapVector = map.genmap();
    Map mp(mapNode, window, mapVector);
    GameCore *game = new GameCore(window, &receiver, player1, player2, mp._id, mapVector, &mp);
    window->getSceneManager()->addCameraSceneNode(0,        // cree une camera fixe
        irr::core::vector3df(-213.0f, 400.0f, -323.0f),    // position de la cam
        irr::core::vector3df(-213.0f, 0.0f, -323.0f));     // cible de la cam
    game->gameLoop();
    delete window;
    delete player1;
    delete player2;
    delete game;
}

void loadGame(Screen *window)
{
    EventHandler receiver;
    window->getDevice()->setEventReceiver(&receiver);
    irr::scene::ISceneNode *mapNode = window->getSceneManager()->addSceneNode("Map");
    irr::scene::ISceneNode *rootNode = window->getSceneManager()->getRootSceneNode();
    Character *player1 = new Character(mapNode, window, "./resources/sydney.md2", 1);
    Character *player2 = new Character(mapNode, window, "./resources/sydney.md2", 1);
    rootNode->addChild(mapNode);
    rootNode->addChild(player1);
    rootNode->addChild(player2);
    player1->setMaterialTexture(window, "./resources/sydney.bmp");
    player2->setMaterialTexture(window, "./resources/Britney.png");
    player1->getCharacter()->setPosition(irr::core::vector3df(-36, 24, -36));
    player2->getCharacter()->setPosition(irr::core::vector3df(-400, 24, -612));
    MapCreator map(19, 13, 0.51); //comme le pastaga
    std::vector<std::vector<int>> mapVector = map.genmap();
    Map mp(mapNode, window, mapVector);
    GameCore *game = new GameCore(window, &receiver, player1, player2, mp._id, mapVector, &mp);
    window->getSceneManager()->addCameraSceneNode(0,        // cree une camera fixe
        irr::core::vector3df(-213.0f, 400.0f, -323.0f),    // position de la cam
        irr::core::vector3df(-213.0f, 0.0f, -323.0f));     // cible de la cam
    game->gameLoop();
    delete window;
    delete player1;
    delete player2;
    delete game;
}

bool EventReceiverMenu::OnEvent(const irr::SEvent& event) {
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
             case irr::gui::EGET_BUTTON_CLICKED:
                switch (id) {
                    case ID_LOAD_GAME_BUTTON:
                        {
                            loadGame(window);
                        }
                        return true;
                    case ID_NEW_GAME_BUTTON:
                        {
                            newGame(window);
                        }
                        return true;
                    case ID_QUIT_BUTTON:
                        Context.device->closeDevice();
                        return true;
                    default:
                        return false;
                }
                break;
            default:
                break;
        }
    }
    return false;
}