#pragma once

#include "AIPlayer.h"
#include "TrucoPlayer.h"

class TrucoAIPlayerState;
class AIPlayerController;

class TrucoAIPlayer : public AIPlayer, public TrucoPlayer
{
public:
	TrucoAIPlayer(
		TrucoPlayerState* pPlayerState, 
		TrucoAIPlayerState* pAIPlayerState, 
		AIPlayerController* pAIPlayerController, 
		double minTinkTimeSec, 
		double maxThinkTimeSec);
};

