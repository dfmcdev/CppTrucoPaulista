#pragma once

#include <vector>

namespace GameEngine
{
	class GameMode;
	class PlayerController;

	/*! \class GameInstance
		\brief Classe base que gerencia de forma geral uma instancia do jogo em execucao.

		Aqui teremos controle sobre o inicio de partidas, acesso aos jogadores, configuracao de jogo, e etc.
		E o ponto de entrada de gerenciamento e configuracao das partidas.
	*/
	class GameInstance
	{
	protected:
		GameMode* m_GameMode;
		std::vector<PlayerController*> m_Controllers;

		GameInstance();
		void Cleanup();

		static GameInstance* m_Instance;

	public:
		~GameInstance();
		GameInstance(GameInstance& other) = delete;
		void operator = (const GameInstance&) = delete;

		static GameInstance* Get();

		virtual void CreateGame(int numPlayers, int numAIPlayers, GameMode* pGameMode);
	};
};
