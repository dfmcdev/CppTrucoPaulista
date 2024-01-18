#pragma once

#include "GameInstance.h"

class TrucoGameInstance : public GameInstance
{
public:
	void CreateGame(int numPlayers, int numAIPlayers, GameMode* pGameMode) override;
};

