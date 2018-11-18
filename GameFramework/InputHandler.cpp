#include "InputHandler.h"

InputHandler::InputHandler()
{
	// »ý¼ºÀÚ 
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
}