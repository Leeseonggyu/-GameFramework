#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	//std::vector<GameObject*> m_gameObjects;


	SDLGameObject* m_go;
	SDLGameObject* m_player;
	SDLGameObject* m_enemy;


private:
	static Game* s_pInstance;
	typedef Game TheGame;
	//SDL_Window * m_pWindow;
	//SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;
	//TextureManager m_textureManager;

	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // 원본 사각형 
	//SDL_Rect m_destinationRectangle; // 대상 사각형 
};