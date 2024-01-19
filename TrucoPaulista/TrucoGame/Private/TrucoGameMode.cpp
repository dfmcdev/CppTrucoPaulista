#include "TrucoGameMode.h"
#include "TrucoGameState.h"
#include "GameState.h"
#include "TrucoPlayer.h"
#include "TrucoPlayerState.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "TrucoAIPlayer.h"
#include "TrucoAIPlayerState.h"
#include "AIPlayerController.h"

using namespace TrucoGame;

TrucoPlayer* TrucoGameMode::GetStartPlayer()
{
	TrucoPlayer* pStartPlayer = nullptr;

	if (!m_PlayersList.empty())
	{
		pStartPlayer = dynamic_cast<TrucoPlayer*>(m_PlayersList[0]->GetControlledPlayer());
	}

	return pStartPlayer;
}

TrucoGameMode::TrucoGameMode(int numPlayers, TrucoGameState* gameState)
	: GameEngine::GameMode(numPlayers, gameState)
{
}

TrucoGameMode::~TrucoGameMode()
{
}

void TrucoGameMode::StartGame()
{
	std::vector<TrucoPlayer*> players;

	for (auto& pController : m_PlayersList)
	{
		TrucoPlayer* pPlayer = dynamic_cast<TrucoPlayer*>(pController->GetControlledPlayer());
		if (pPlayer)
		{
			players.push_back(pPlayer);
		}
	}

	TrucoGameState* pTrucoGameState = dynamic_cast<TrucoGameState*>(m_GameState);
	if (pTrucoGameState)
	{
		Deck* deck = pTrucoGameState->GetDeck();
		
		// Set initial players cards
		deck->Init();
		deck->Shuffle();

		for (int i = 0; i < m_NumStartCards; i++)
		{
			for (auto& player : players)
			{
				Card* card = deck->DrawCard();
				TrucoPlayerState* pTrucoPlayerState = dynamic_cast<TrucoPlayerState*>(player->GetPlayerState());

				if (pTrucoPlayerState)
				{
					pTrucoPlayerState->GetHand()->AddCard(card);
				}
			}
		}

		GameEngine::GameMode::StartGame();
	}
}

void TrucoGameMode::OnGameStarted()
{
	GameEngine::GameMode::OnGameStarted();

	// Initialize turn
	TrucoGameState* pTrucoGameState = dynamic_cast<TrucoGameState*>(m_GameState);

	if (pTrucoGameState)
	{
		pTrucoGameState->ResetTurn();

		TrucoPlayer* pStartPlayer = GetStartPlayer();
		AdvancedTurn(pStartPlayer);
	}
}

void TrucoGameMode::OnJoined(GameEngine::PlayerController* pPlayerController, bool isAIControlled)
{
	if (isAIControlled)
	{
		TrucoPlayerState* pTrucoPlayerState = new TrucoPlayerState(new Hand());
		TrucoAIPlayer* pAIPlayer = new TrucoAIPlayer(pTrucoPlayerState, new TrucoAIPlayerState(), dynamic_cast<GameEngine::AIPlayerController*>(pPlayerController), 2, 5);
	}
	else
	{
		TrucoPlayer* pPlayer = new TrucoPlayer(new TrucoPlayerState(new Hand()), pPlayerController);
	}	

	GameEngine::GameMode::OnJoined(pPlayerController, isAIControlled);
}

void TrucoGameMode::OnTurnAdvanced(TrucoPlayer* turnPlayer)
{
	if (m_OnTurnAdvancedCallback)
	{
		m_OnTurnAdvancedCallback(turnPlayer);
	}
}

void TrucoGameMode::BindTurnAdvancedCallback(std::function<void(TrucoPlayer*)> callback)
{
	m_OnTurnAdvancedCallback = callback;
}

void TrucoGameMode::AdvancedTurn(TrucoPlayer* turnPlayer)
{
	TrucoGameState* pTrucoGameState = dynamic_cast<TrucoGameState*>(m_GameState);

	if (pTrucoGameState)
	{
		pTrucoGameState->AdvanceTurn(turnPlayer);
	}

	OnTurnAdvanced(turnPlayer);
}
