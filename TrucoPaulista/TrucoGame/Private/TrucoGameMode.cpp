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

TrucoGameMode::TrucoGameMode(int numPlayers, TrucoGameState* gameState) 
	: GameMode(numPlayers, gameState)
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
	}
}

void TrucoGameMode::OnJoined(PlayerController* pPlayerController, bool isAIControlled)
{
	if (isAIControlled)
	{
		TrucoPlayerState* pTrucoPlayerState = new TrucoPlayerState(new Hand());
		TrucoAIPlayer* pAIPlayer = new TrucoAIPlayer(pTrucoPlayerState, new TrucoAIPlayerState(), dynamic_cast<AIPlayerController*>(pPlayerController), 2, 5);
	}
	else
	{
		TrucoPlayer* pPlayer = new TrucoPlayer(new TrucoPlayerState(new Hand()), pPlayerController);
	}	

	GameMode::OnJoined(pPlayerController, isAIControlled);
}
