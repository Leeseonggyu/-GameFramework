#pragma once
#include"GameState.h"
#include"SDLGameObject.h"

class MenuButton : SDLGameObject
{
public:
    void(*m_callback)();

    bool m_bReleased;

    MenuButton(const LoaderParams* pParams, void(*callback)());
};