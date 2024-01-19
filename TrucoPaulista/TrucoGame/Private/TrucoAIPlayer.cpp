#include "TrucoAIPlayer.h"
#include "TrucoAIPlayerState.h"
#include "AIPlayerController.h"

using namespace TrucoGame;

TrucoAIPlayer::TrucoAIPlayer(
	TrucoPlayerState* pPlayerState,
	TrucoAIPlayerState* pAIPlayerState, 
	GameEngine::AIPlayerController* pAIPlayerController, 
	double minTinkTimeSec, 
	double maxThinkTimeSec) : 
		GameEngine::AIPlayer(pAIPlayerState, minTinkTimeSec, maxThinkTimeSec),
		TrucoPlayer(pPlayerState, pAIPlayerController)
{
}
