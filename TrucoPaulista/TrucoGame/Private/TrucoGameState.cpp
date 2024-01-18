#include "TrucoGameState.h"
#include "Deck.h"

TrucoGameState::TrucoGameState(Deck* deck)
{
	m_Deck = deck;
}

TrucoGameState::~TrucoGameState()
{
	if (m_Deck)
	{
		delete m_Deck;
	}
}

Deck* TrucoGameState::GetDeck()
{
	return m_Deck;
}
