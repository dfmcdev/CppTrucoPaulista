#pragma once

#include "Player.h"

class TrucoPlayerState;

/*! \class TrucoPlayer
	\brief Especializacao da classe Player para um jogo de truco.

	Aqui teremos as informacoes sobre o jogador que nao mudam entre uma partida e outra.
*/
class TrucoPlayer : public Player
{
public:
	TrucoPlayer(TrucoPlayerState* pTrucoPlayerState, PlayerController* pPlayerController);
};

