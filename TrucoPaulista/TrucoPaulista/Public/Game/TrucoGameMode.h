#pragma once
#include "Core\GameMode.h"

class Deck;

class TrucoGameMode : public GameMode
{
private:
	Deck* m_deck;
	int m_numStartCards = 3;

public:
	TrucoGameMode(int numPlayersgameState, GameState* gameState, Deck* deck);
	~TrucoGameMode();

	void StartGame() override;
	void OnJoined(PlayerController* pPlayerController, bool isAIControlled = false) override;

	Deck* GetDeck();

	int GetNumStartCards() { return m_numStartCards; }
};

