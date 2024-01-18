#pragma once

#include "Player.h"

class TrucoPlayerState;

class TrucoPlayer : public Player
{
public:
	TrucoPlayer(TrucoPlayerState* pTrucoPlayerState, PlayerController* pPlayerController);
};

