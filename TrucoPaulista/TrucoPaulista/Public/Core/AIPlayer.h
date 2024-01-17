#pragma once

#include "Core\Player.h"

class AIPlayerState;

class AIPlayer : public Player
{
public:
	AIPlayer(AIPlayerState* pState);
};

