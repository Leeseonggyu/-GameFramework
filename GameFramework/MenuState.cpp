#include "MenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"
#include "PlayState.h"
#include <SDL_image.h>

const std::string MenuState::s_menuID = "MENU";
MenuState* MenuState::s_pInstance = 0;

void MenuState::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void MenuState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter()
{
    /*
    if (!TheTextureManager::Instance()->load("battleback.png", "back", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    SDL_Surface*pTempSurface = IMG_Load("assets/battleback.png");
    m_pTexture = SDL_CreateTextureFromSurface(TheGame::Instance()->getRenderer(), pTempSurface);

    SDL_FreeSurface(pTempSurface);
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    m_sourceRectangle.w = 853;
    m_sourceRectangle.h = 480;

    TheTextureManager::Instance()->draw("back", 100, 100, m_sourceRectangle.w, m_sourceRectangle.y,
        TheGame::Instance()->getRenderer());

    SDL_RenderPresent(TheGame::Instance()->getRenderer());
    */
    SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 255, 0, 0, 255);
    if (!TheTextureManager::Instance()->load("assets/button.png",
        "playbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("assets/exit.png",
        "exitbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject* button1 = new MenuButton(
        new LoaderParams(100, 100, 400, 100, "playbutton"),
        s_menuToPlay);

    GameObject* button2 = new MenuButton(
        new LoaderParams(100, 300, 400, 100, "exitbutton"),
        s_exitFromMenu);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);
    std::cout << "entering MenuState\n";
    return true;
}

bool MenuState::onExit()
{
    SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()
        ->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()
        ->clearFromTextureMap("exitbutton");
    std::cout << "exiting MenuState\n";
    return true;
}

void MenuState::s_menuToPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
    TheGame::Instance()->quit();
}