#include "InputHandler.h"

InputHandler::InputHandler()
{
<<<<<<< HEAD
	// »ý¼ºÀÚ 
=======
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
>>>>>>> parent of 8ca1a71... Add
}

void InputHandler::clean()
{
	// ÇâÈÄ Ãß°¡ 
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
<<<<<<< HEAD
		if (event.type == SDL_KEYUP)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}

		if (event.type == SDL_KEYDOWN)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
=======
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
>>>>>>> parent of 8ca1a71... Add
		}
	}
}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0) {
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else {
			return false;
		}
	}
	return false;
<<<<<<< HEAD
=======
}
bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D*  InputHandler::getMousePosition()
{
	return m_mousePosition;
>>>>>>> parent of 8ca1a71... Add
}