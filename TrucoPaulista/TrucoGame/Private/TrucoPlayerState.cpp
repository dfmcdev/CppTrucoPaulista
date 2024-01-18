#include "TrucoPlayerState.h"
#include "Hand.h"

TrucoPlayerState::TrucoPlayerState(Hand* hand) : PlayerState()
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
