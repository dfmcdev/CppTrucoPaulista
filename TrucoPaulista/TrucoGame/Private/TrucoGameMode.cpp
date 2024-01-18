#include "TrucoGameMode.h"
#include "TrucoGameState.h"
#include "TrucoPlayer.h"
#include "TrucoPlayerState.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "TrucoAIPlayer.h"
#include "TrucoAIPlayerState.h"
#include "AIPlayerController.h"

TrucoGameMode::TrucoGameMode(int numPlayers, TrucoGameState* gameState, Deck* deck) 
	: GameMode(numPlayers, gameState)
{
	m_deck = deck;
}

TrucoGameMode::~TrucoGameMode()
{
	if (m_deck)
	{
		delete m_deck;
	}
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

	// Set initial players cards
	m_deck->Init();
	m_deck->Shuffle();

	for (int i = 0; i < m_numStartCards; i++)
	{
		for (auto& player : players)
		{
			Card* card = m_deck->DrawCard();
			TrucoPlayerState* pTrucoPlayerState = dynamic_cast<TrucoPlayerState*>(player->GetPlayerState());

			if (pTrucoPlayerState)
			{
				pTrucoPlayerState->GetHand()->AddCard(card);
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

Deck* TrucoGameMode::GetDeck()
{
	return m_deck;
}
