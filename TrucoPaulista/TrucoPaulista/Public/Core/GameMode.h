#pragma once

#include <vector>
#include "Result.h"
#include "GameState.h"
#include "PlayerController.h"

class GameMode
{
private:
	int m_MaxPlayers = 1;

protected:	
	std::vector<PlayerController*> m_PlayersList;

	GameState* m_GameState;

	virtual void OnJoined(PlayerController* pController);
	virtual void OnLeaved(PlayerController* pController);

	virtual void OnGameStarted();
	virtual void OnGameEnded();

public:
	GameMode(int maxPlayers, GameState* pGameState);
	virtual ~GameMode();

	Result Join(PlayerController* pController);
	void Leave(PlayerController* pController);
	void StartGame();
	void EndGame();

	int GetNumPlayers();
};

