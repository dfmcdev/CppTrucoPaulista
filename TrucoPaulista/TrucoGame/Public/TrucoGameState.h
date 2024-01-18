#pragma once

#include "GameState.h"

class Deck;
class TrucoPlayer;

class TrucoGameState : public GameState
{
private:
	Deck* m_Deck;
	int m_CurrentTurn;

	TrucoPlayer* m_TurnPlayer;

public:
	TrucoGameState(Deck* deck);
	~TrucoGameState();

	Deck* GetDeck();
	TrucoPlayer* GetTurnPlayer();

	void AdvanceTurn(TrucoPlayer* turnPlayer);	
	void ResetTurn();
};
