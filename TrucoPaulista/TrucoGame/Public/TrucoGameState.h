#pragma once

#include "GameState.h"

namespace TrucoGame
{
	class Deck;
	class TrucoPlayer;

	/*! \class TrucoGameState
		\brief Especializacao da classe GameState para um jogo de truco.

		Aqui teremos as informacoes que sao relevantes apenas para a partida em curso.
	*/
	class TrucoGameState : public GameEngine::GameState
	{
	private:
		Deck* m_Deck;
		int m_CurrentTurn;

		TrucoPlayer* m_TurnPlayer;

	public:
		TrucoGameState(Deck* deck);
		~TrucoGameState();

		Deck* GetDeck();
		TrucoPlayer* GetTurnPlayer();

		void AdvanceTurn(TrucoPlayer* turnPlayer);
		void ResetTurn();
	};
};
