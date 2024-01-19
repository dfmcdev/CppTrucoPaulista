#include "TrucoGameState.h"
#include "Deck.h"

using namespace TrucoGame;

TrucoGameState::TrucoGameState(Deck* deck) : m_TurnPlayer(nullptr)
{
	m_Deck = deck;
	m_CurrentTurn = 0;
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

TrucoPlayer* TrucoGameState::GetTurnPlayer()
{
	return m_TurnPlayer;
}

void TrucoGameState::AdvanceTurn(TrucoPlayer* turnPlayer)
{
	m_CurrentTurn++;
	m_TurnPlayer = turnPlayer;
}

void TrucoGameState::ResetTurn()
{
	m_TurnPlayer = nullptr;
	m_CurrentTurn = 0;
}
