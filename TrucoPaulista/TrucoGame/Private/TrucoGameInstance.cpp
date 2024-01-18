#include "TrucoGameInstance.h"
#include "TrucoGameMode.h"
#include "TrucoGameState.h"
#include "Deck.h"
#include "AIPlayerController.h"
#include "PlayerController.h"
#include "GameMode.h"
#include "Result.h"

void TrucoGameInstance::CreateGame(int numPlayers, int numAIPlayers, GameMode* pGameMode)
{
	Cleanup();

	int totalPlayers = numPlayers + numAIPlayers;

	// Inicializa o modo de jogo
	m_GameMode = new TrucoGameMode(totalPlayers, new TrucoGameState(), new Deck());

	// Inicializa os jogadores
	m_Controllers.reserve(totalPlayers);

	for (size_t i = 0; i < numPlayers; i++)
	{
		PlayerController* pController = new PlayerController();
		m_Controllers.push_back(pController);

		m_GameMode->Join(pController);
	}

	for (size_t i = 0; i < numAIPlayers; i++)
	{
		AIPlayerController* pAIController = new AIPlayerController();
		m_Controllers.push_back(pAIController);

		m_GameMode->Join(pAIController, true);
	}
}
