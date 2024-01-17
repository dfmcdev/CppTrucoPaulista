#include "Core\Player.h"
#include "Core\PlayerController.h"
#include "Core\PlayerState.h"

Player::Player(PlayerState* pPlayerState)
{
	m_PlayerState = pPlayerState;
}

Player::~Player()
{
	if (m_PlayerState)
	{
		delete m_PlayerState;
	}
}

void Player::SetControlled(PlayerController* pPlayerController)
{
	m_PlayerController = pPlayerController;
}

PlayerController* Player::GetPlayerController()
{
	return m_PlayerController;
}

PlayerState* Player::GetPlayerState()
{
	return m_PlayerState;
}
