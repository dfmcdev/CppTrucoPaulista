#include "Game\TrucoGameMode.h"
#include "Game\TrucoPlayer.h"
#include "Game\TrucoPlayerState.h"
#include "Game\Card.h"
#include "Game\Hand.h"
#include "Game\Deck.h"
#include "Core\AIPlayer.h"
#include "Core\AIPlayerState.h"
#include "Core\AIPlayerController.h"

TrucoGameMode::TrucoGameMode(int numPlayers, GameState* gameState, Deck* deck) 
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
			player->GetHand()->AddCard(card);
		}
	}
}

void TrucoGameMode::OnJoined(PlayerController* pPlayerController, bool isAIControlled)
{
	if (isAIControlled)
	{
		AIPlayer* pAIPlayer = new AIPlayer(new AIPlayerState(), dynamic_cast<AIPlayerController*>(pPlayerController));
	}
	else
	{
		TrucoPlayer* pPlayer = new TrucoPlayer(new TrucoPlayerState(), pPlayerController, new Hand());
	}	

	GameMode::OnJoined(pPlayerController, isAIControlled);
}

Deck* TrucoGameMode::GetDeck()
{
	return m_deck;
}
