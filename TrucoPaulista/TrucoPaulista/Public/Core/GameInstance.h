#pragma once

#include <vector>

class GameMode;
class PlayerController;

class GameInstance
{
private:
	GameMode* m_GameMode;
	std::vector<PlayerController*> m_Controllers;

protected:
	GameInstance();
	void Cleanup();

	static GameInstance* m_Instance;

public:
	~GameInstance();
	GameInstance(GameInstance& other) = delete;
	void operator = (const GameInstance&) = delete;

	static GameInstance* Get();

	void CreateGame(int numPlayers, int numAIPlayers, GameMode* pGameMode);
};

