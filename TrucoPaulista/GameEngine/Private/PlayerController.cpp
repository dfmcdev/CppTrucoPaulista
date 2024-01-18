#include "PlayerController.h"
#include "Player.h"

PlayerController::PlayerController() : 
	m_IsAIControled(false), 
	m_ControlledPlayer(nullptr)
{
}

PlayerController::PlayerController(bool isAIControlled) : 
	m_IsAIControled(isAIControlled),
	m_ControlledPlayer(nullptr)
{
}

PlayerController::~PlayerController()
{
	if (m_ControlledPlayer)
	{
		delete m_ControlledPlayer;
	}
}

void PlayerController::Posses(Player* pPlayer)
{
	m_ControlledPlayer = pPlayer;
}

Player* PlayerController::GetControlledPlayer()
{
	return m_ControlledPlayer;
}
