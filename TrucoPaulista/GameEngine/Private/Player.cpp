#include "Player.h"
#include "PlayerController.h"
#include "PlayerState.h"

using namespace GameEngine;

Player::Player(PlayerState* pPlayerState, PlayerController* pPlayerController)
{
	m_PlayerState = pPlayerState;
	m_PlayerController = pPlayerController;

	pPlayerController->Posses(this);
}

Player::~Player()
{
	if (m_PlayerState)
	{
		delete m_PlayerState;
	}
}

PlayerController* Player::GetPlayerController()
{
	return m_PlayerController;
}

PlayerState* Player::GetPlayerState()
{
	return m_PlayerState;
}
