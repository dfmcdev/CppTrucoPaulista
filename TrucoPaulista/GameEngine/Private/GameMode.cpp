#include "GameMode.h"
#include "GameState.h"
#include "Player.h"
#include "PlayerController.h"
#include "Result.h"
#include <algorithm>

GameMode::GameMode(int numPlayers, GameState* pGameState)
{
	m_MaxPlayers = numPlayers;
	m_PlayersList.reserve(numPlayers);
	m_GameState = pGameState;
}

GameMode::~GameMode()
{
	if (m_GameState)
	{
		delete m_GameState;
	}
}

void GameMode::OnJoined(PlayerController* pPlayerController, bool isAIControlled)
{
}

void GameMode::OnLeaved(PlayerController* pPlayerController)
{
}

void GameMode::OnGameStarted()
{
}

void GameMode::OnGameEnded()
{
}

Result GameMode::Join(PlayerController* pPlayerController, bool isAIControlled)
{
	if (m_PlayersList.size() == m_MaxPlayers)
	{
		// TODO: Add log or warning
		return Result(ResultCode::GameIsFull, "This game already reached the maximum players limit.");
	}
	
	std::vector<PlayerController*>::iterator it;
	it = std::find(m_PlayersList.begin(), m_PlayersList.end(), pPlayerController);

	if (it != m_PlayersList.end())
	{
		return Result(ResultCode::PlayerAlreadyJoined, "This player is alreadi in the game.");
	}

	m_PlayersList.push_back(pPlayerController);

	OnJoined(pPlayerController, isAIControlled);

	return Result::Success();
}

void GameMode::Leave(PlayerController* pPlayerController)
{
	std::vector<PlayerController*>::iterator it;
	it = std::find(m_PlayersList.begin(), m_PlayersList.end(), pPlayerController);

	if (it != m_PlayersList.end())
	{
		OnLeaved(pPlayerController);

		m_PlayersList.erase(it);
	}
}

void GameMode::StartGame()
{
	OnGameStarted();
}

void GameMode::EndGame()
{
	OnGameEnded();
}

int GameMode::GetNumPlayers()
{
	return (int)m_PlayersList.size();
}
