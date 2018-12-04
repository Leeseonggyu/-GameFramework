#pragma once
#include "GameState.h"

class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void update();
	void render();
	void popState();
	void pushState(GameState *pState);

private:
	GameState * m_currentState;
	GameState* m_prevState;

	std::vector<GameState*> m_gameStates;
};