#pragma once

#include "PlayerState.h"
#include "PlayerController.h"

namespace GameEngine
{
	/*! \class Player
		\brief Classe base que representa o avatar de um jogador.

		Aqui teremos as informacoes sobre o jogador que nao mudam entre uma partida e outra.
	*/
	class Player
	{
	protected:
		PlayerController* m_PlayerController;
		PlayerState* m_PlayerState;

	public:
		Player(PlayerState* pPlayerState, PlayerController* pPlayerController);
		virtual ~Player();

		PlayerController* GetPlayerController();
		PlayerState* GetPlayerState();
	};
};
