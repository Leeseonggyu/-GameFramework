#include "MenuState.h"
const std::string MenuState::s_menuID = "MENU";

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
}

void MenuState::update()
{
	// nothing for now
}

void MenuState::render()
{
	// nothing for now
}

bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}