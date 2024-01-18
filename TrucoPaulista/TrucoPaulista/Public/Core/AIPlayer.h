#pragma once

#include "Core\Player.h"

class AIPlayerState;
class AIPlayerController;

class AIPlayer : public Player
{
public:
	AIPlayer(AIPlayerState* pAIPlayerState, AIPlayerController* pAIPlayerController);
};

