#pragma once

#include "AIPlayerState.h"

namespace TrucoGame
{
	/*! \class TrucoAIPlayerState
		\brief Especializacao da classe AIPlayerState para um jogo de truco.

		Aqui teremos informacoes pertinentes ao estado da AI durante as partidas.
	*/
	class TrucoAIPlayerState : public GameEngine::AIPlayerState
	{
	public:
		TrucoAIPlayerState();
	};
};
