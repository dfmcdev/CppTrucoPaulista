#include "Core\Player.h"
#include "Core\PlayerController.h"
#include "Core\PlayerState.h"

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
