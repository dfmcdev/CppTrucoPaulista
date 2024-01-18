#pragma once
#include "GameMode.h"

class Deck;
class TrucoPlayer;
class TrucoGameState;

class TrucoGameMode : public GameMode
{
private:	
	int m_NumStartCards = 3;

	TrucoPlayer* GetStartPlayer();

public:
	TrucoGameMode(int numPlayers, TrucoGameState* gameState);
	~TrucoGameMode();

	void StartGame() override;
	void OnJoined(PlayerController* pPlayerController, bool isAIControlled = false) override;	

	void OnTurnAdvanced(TrucoPlayer* turnPlayer);

	int GetNumStartCards() { return m_NumStartCards; }
};

