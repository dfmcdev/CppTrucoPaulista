#pragma once
#include "GameMode.h"

class TrucoGameState;
class Deck;

class TrucoGameMode : public GameMode
{
private:
	Deck* m_deck;
	int m_numStartCards = 3;

public:
	TrucoGameMode(int numPlayers, TrucoGameState* gameState, Deck* deck);
	~TrucoGameMode();

	void StartGame() override;
	void OnJoined(PlayerController* pPlayerController, bool isAIControlled = false) override;

	Deck* GetDeck();

	int GetNumStartCards() { return m_numStartCards; }
};

