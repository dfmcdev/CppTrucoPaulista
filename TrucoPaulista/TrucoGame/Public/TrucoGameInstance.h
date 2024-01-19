#pragma once

#include "GameInstance.h"

namespace TrucoGame
{
	/*! \class TrucoGameInstance
		\brief Expecializacao da classe GameInstance para um jogo de truco.

		Aqui teremos controle sobre o inicio de partidas, acesso aos jogadores, configuracao de jogo, e etc.
		E o ponto de entrada de gerenciamento e configuracao das partidas.
	*/
	class TrucoGameInstance : public GameEngine::GameInstance
	{
	public:
		void CreateGame(int numPlayers, int numAIPlayers, GameEngine::GameMode* pGameMode) override;
	};
};
