#pragma once

#include "PlayerState.h"

class Hand;

/*! \class TrucoPlayerState
	\brief Especializacao da classe PlayerState para uma partida de truco.

	Aqui teremos as informacoes que sao relevantes apenas para a partida em curso.
*/
class TrucoPlayerState : public PlayerState
{
private:
	Hand* m_Hand;

public:
	TrucoPlayerState(Hand* hand);
	~TrucoPlayerState();

	Hand* GetHand();
};

