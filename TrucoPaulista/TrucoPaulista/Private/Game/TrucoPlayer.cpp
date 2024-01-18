#include "Game\TrucoPlayer.h"
#include "Game\TrucoPlayerState.h"
#include "Game\Hand.h"

TrucoPlayer::TrucoPlayer(TrucoPlayerState* pTrucoPlayerState, PlayerController* pPlayerController, Hand* hand) : 
	Player(pTrucoPlayerState, pPlayerController)
{
	m_hand = hand;
}

TrucoPlayer::~TrucoPlayer()
{
	if (m_hand)
	{
		delete m_hand;
	}
}

Hand* TrucoPlayer::GetHand()
{
	return m_hand;
}
