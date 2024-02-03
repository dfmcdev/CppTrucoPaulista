#pragma once

#include "AIPlayer.h"
#include "TrucoPlayer.h"
#include "AIPlayerController.h"

class Result;

namespace TrucoGame
{
	class TrucoAIPlayerState;

	/*! \class TrucoAIPlayer
		\brief Especializacao da classe AIPlayer para um jogo de truco.

		Aqui teremos as informacoes sobre o avatar que nao mudam entre uma partida e outra.
	*/
	class TrucoAIPlayer : public GameEngine::AIPlayer, public TrucoPlayer
	{
	protected:
		void Think(int thinkTime) override;

	public:
		TrucoAIPlayer(
			TrucoPlayerState* pPlayerState,
			TrucoAIPlayerState* pAIPlayerState,
			GameEngine::AIPlayerController* pAIPlayerController,
			int minTinkTimeSec,
			int maxThinkTimeSec);
		
		GameEngine::Result DoAction() override;
	};
};
