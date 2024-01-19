#pragma once

#include "AIPlayer.h"
#include "TrucoPlayer.h"

class TrucoAIPlayerState;
class AIPlayerController;

/*! \class TrucoAIPlayer
	\brief Especializacao da classe AIPlayer para um jogo de truco.

	Aqui teremos as informacoes sobre o avatar que nao mudam entre uma partida e outra.
*/
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

