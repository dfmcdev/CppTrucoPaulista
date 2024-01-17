#include "Core\GameInstance.h"
#include "Core\GameState.h"
#include "Game\TrucoPaulistaGameMode.h"
#include "Core\AIPlayerController.h"
#include "Core\AIPlayerState.h"
#include "Core\AIPlayer.h"

GameInstance* GameInstance::m_Instance = nullptr;

void GameInstance::Cleanup()
{
	if (m_GameMode)
	{
		delete m_GameMode;
	}

	std::vector<PlayerController*>::iterator it;
	for (it = m_Controllers.begin(); it != m_Controllers.end(); it++)
	{
		delete* it;
	}
}

GameInstance::~GameInstance()
{
	Cleanup();

	if (m_Instance != nullptr)
	{
		delete m_Instance;
	}
}

GameInstance* GameInstance::Get()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new GameInstance();
	}

	return m_Instance;
}

void GameInstance::CreateGame(int numPlayers, int numAIPlayers, GameMode* pGameMode)
{
	Cleanup();

	int totalPlayers = numPlayers + numAIPlayers;

	// Inicializa o modo de jogo
	m_GameMode = new TrucoPaulistaGameMode(totalPlayers, new GameState());

	// Inicializa os jogadores
	m_Controllers.reserve(totalPlayers);

	for (size_t i = 0; i < numPlayers; i++)
	{
		PlayerController* pController = new PlayerController();
		m_Controllers.push_back(pController);

		PlayerState* pState = new PlayerState();
		Player* pPlayer = new Player(pState);

		pController->Posses(pPlayer);

		m_GameMode->Join(pController);
	}

	for (size_t i = 0; i < numAIPlayers; i++)
	{
		AIPlayerController* pAIController = new AIPlayerController();
		m_Controllers.push_back(pAIController);

		AIPlayerState* pAIState = new AIPlayerState();
		AIPlayer* pAIPlayer = new AIPlayer(pAIState);

		pAIController->Posses(pAIPlayer);

		m_GameMode->Join(pAIController);
	}
}
