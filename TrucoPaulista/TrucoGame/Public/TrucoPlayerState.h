#pragma once

#include "PlayerState.h"

class Hand;

class TrucoPlayerState : public PlayerState
{
private:
	Hand* m_hand;

public:
	TrucoPlayerState(Hand* hand);
	~TrucoPlayerState();

	Hand* GetHand();
};

