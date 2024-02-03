#include "TrucoAIPlayer.h"
#include "TrucoAIPlayerState.h"
#include "AIPlayerController.h"
#include <thread>
#include <chrono>
#include <random>

using namespace TrucoGame;

TrucoAIPlayer::TrucoAIPlayer(
	TrucoPlayerState* pPlayerState,
	TrucoAIPlayerState* pAIPlayerState, 
	GameEngine::AIPlayerController* pAIPlayerController, 
	int minTinkTimeSec, 
	int maxThinkTimeSec) : 
		GameEngine::AIPlayer(pAIPlayerState, minTinkTimeSec, maxThinkTimeSec),
		TrucoPlayer(pPlayerState, pAIPlayerController)
{
}

void TrucoAIPlayer::Think(int thinkTime)
{
	std::this_thread::sleep_for(std::chrono::seconds(thinkTime));
}

void TrucoAIPlayer::DoAction()
{
	int sleep_time = std::rand() % m_MaxThinkTimeSeconds + m_MinThinkTimeSeconds;
	Think(sleep_time);

	// Play card
}
