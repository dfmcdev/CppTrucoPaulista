#pragma once
#include "GameMode.h"

class TrucoGameState;
class Deck;

class TrucoGameMode : public GameMode
{
private:	
	int m_NumStartCards = 3;

public:
	TrucoGameMode(int numPlayers, TrucoGameState* gameState);
	~TrucoGameMode();

	void StartGame() override;
	void OnJoined(PlayerController* pPlayerController, bool isAIControlled = false) override;	

	int GetNumStartCards() { return m_NumStartCards; }
};

