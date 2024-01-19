#include "GameInstance.h"
#include "GameState.h"
#include "AIPlayerController.h"
#include "AIPlayerState.h"
#include "AIPlayer.h"
#include "Result.h"
#include "GameMode.h"

using namespace GameEngine;

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

GameInstance::GameInstance() : m_GameMode(nullptr)
{
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
}
