#include "TrucoAIPlayer.h"
#include "TrucoAIPlayerState.h"
#include "TrucoPlayerState.h"
#include "AIPlayerController.h"
#include "Hand.h"
#include "Card.h"
#include "Result.h"
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

GameEngine::Result TrucoAIPlayer::DoAction()
{
	int sleep_time = std::rand() % m_MaxThinkTimeSeconds + m_MinThinkTimeSeconds;
	Think(sleep_time);

	// Play card
	TrucoPlayerState* state = dynamic_cast<TrucoPlayerState*>(GetPlayerState());
	if (state->GetHand()->GetNumCards() == 0)
	{
		return GameEngine::Result(GameEngine::ResultCode::EmptyHand, "There is no card to play!");
	}

	Card* card = state->GetHand()->PlayCard(0); // TODO: Isso precisa ser adicionado ao jogo quando as regras forem implementadas

	return GameEngine::Result::Success(card);
}
