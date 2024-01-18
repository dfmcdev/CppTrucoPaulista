#include "TrucoPlayerState.h"
#include "Hand.h"

TrucoPlayerState::TrucoPlayerState(Hand* hand) : PlayerState()
{
	m_hand = hand;
}

TrucoPlayerState::~TrucoPlayerState()
{
	if (m_hand)
	{
		delete m_hand;
	}
}

Hand* TrucoPlayerState::GetHand()
{
	return m_hand;
}
