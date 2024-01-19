#include "TrucoPlayer.h"
#include "TrucoPlayerState.h"
#include "Hand.h"

using namespace TrucoGame;

TrucoPlayer::TrucoPlayer(TrucoPlayerState* pTrucoPlayerState, GameEngine::PlayerController* pPlayerController) : 
	GameEngine::Player(pTrucoPlayerState, pPlayerController)
{
}
