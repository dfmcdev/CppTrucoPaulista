#include "TrucoPlayerState.h"
#include "Hand.h"

using namespace TrucoGame;

TrucoPlayerState::TrucoPlayerState(Hand* hand) : GameEngine::PlayerState()
{
	m_Hand = hand;
}

TrucoPlayerState::~TrucoPlayerState()
{
	if (m_Hand)
	{
		delete m_Hand;
	}
}

Hand* TrucoPlayerState::GetHand()
{
	return m_Hand;
}
