#pragma once

#include "GameState.h"

class Deck;

class TrucoGameState : public GameState
{
private:
	Deck* m_Deck;

public:
	TrucoGameState(Deck* deck);
	~TrucoGameState();

	Deck* GetDeck();
};

