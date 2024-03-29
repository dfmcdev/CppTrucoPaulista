#pragma once
#include "GameMode.h"
#include <functional>

namespace TrucoGame
{
	class Deck;
	class TrucoPlayer;
	class TrucoGameState;

	/*! \class TrucoGameMode
		\brief Especializacao da classe GameMode para um jogo de truco.
	*/
	class TrucoGameMode : public GameEngine::GameMode
	{
	private:
		int m_NumStartCards = 3;
		const std::vector<int> m_DefaultStackle = { 3, 2, 1, 10, 8, 9, 7, 6, 5, 4 };

		TrucoPlayer* GetStartPlayer();
		std::function<void(TrucoPlayer*)> m_OnTurnAdvancedCallback;

		void OnTurnAdvanced(TrucoPlayer* turnPlayer);

	public:
		TrucoGameMode(int numPlayers, TrucoGameState* gameState);
		~TrucoGameMode();

		void StartGame() override;
		void OnGameStarted() override;
		void OnJoined(GameEngine::PlayerController* pPlayerController, bool isAIControlled = false) override;

		void BindTurnAdvancedCallback(std::function<void(TrucoPlayer*)> callback);
		void AdvancedTurn(TrucoPlayer* turnPlayer);

		int GetNumStartCards() { return m_NumStartCards; }
		int GetStackleCard() { return  m_DefaultStackle[0]; }
	};
};
