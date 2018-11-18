#include"Game.h"

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		// load 부분 대치   
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

		//m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);

	}
	else {
		return false; // sdl could not initialize
	}
	return true;
}


void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	// draw 부분 대치 
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82,
		m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100,
		128, 82, 1, m_currentFrame, m_pRenderer);

	/*m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
	m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1,
	m_currentFrame, m_pRenderer);*/
	SDL_RenderPresent(m_pRenderer);
}