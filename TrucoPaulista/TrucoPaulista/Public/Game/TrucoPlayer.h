#pragma once

#include "Core\Player.h"

class TrucoPlayerState;
class Hand;

class TrucoPlayer : public Player
{
private:
	Hand* m_hand;

public:
	TrucoPlayer(TrucoPlayerState* pTrucoPlayerState, PlayerController* pPlayerController, Hand* hand);
	~TrucoPlayer();

	Hand* GetHand();
};

