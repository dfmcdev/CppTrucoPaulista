#include "TrucoAIPlayer.h"
#include "TrucoAIPlayerState.h"
#include "AIPlayerController.h"

TrucoAIPlayer::TrucoAIPlayer(
	TrucoPlayerState* pPlayerState,
	TrucoAIPlayerState* pAIPlayerState, 
	AIPlayerController* pAIPlayerController, 
	double minTinkTimeSec, 
	double maxThinkTimeSec) : 
		TrucoPlayer(pPlayerState, pAIPlayerController),
		AIPlayer(pAIPlayerState, minTinkTimeSec, maxThinkTimeSec)
{
}
