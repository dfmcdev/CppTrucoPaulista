#pragma once

#include <vector>
#include <functional>

class Result;
class GameState;
class PlayerController;

class GameMode
{
private:
	int m_MaxPlayers = 1;
	std::function<void(void)> m_OnGameStartedCallback;

protected:	
	std::vector<PlayerController*> m_PlayersList;
	GameState* m_GameState;

	virtual void OnJoined(PlayerController* pController, bool isAIControlled = false);
	virtual void OnLeaved(PlayerController* pController);

	virtual void OnGameStarted();
	virtual void OnGameEnded();

public:
	GameMode(int maxPlayers, GameState* pGameState);
	virtual ~GameMode();

	Result Join(PlayerController* pController, bool isAIControlled = false);
	void Leave(PlayerController* pController);
	virtual void StartGame();
	virtual void EndGame();

	int GetNumPlayers();

	GameState* GetGameState();

	void BindGameStartedCallback(std::function<void(void)> func);
};

